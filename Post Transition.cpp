#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[11];
    int weight;
} package;

typedef struct {
    package *packages;
    int packages_count;
    int min_weight;
    int max_weight;
} post_office;

typedef struct {
    char name[11];
    post_office *offices;
    int offices_count;
} town;

/* Function to print all packages in a town */
void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

/* Transaction between two post offices */
void send_all_packages(town *sourceTown, int sourceIndex, town *targetTown, int targetIndex) {
    post_office *src = &sourceTown->offices[sourceIndex];
    post_office *dst = &targetTown->offices[targetIndex];

    int newSrcCount = 0;
    package *newSrcPackages = (package *)malloc(src->packages_count * sizeof(package));

    for (int i = 0; i < src->packages_count; i++) {
        package p = src->packages[i];
        if (p.weight >= dst->min_weight && p.weight <= dst->max_weight) {
            dst->packages = (package *)realloc(dst->packages, (dst->packages_count + 1) * sizeof(package));
            dst->packages[dst->packages_count++] = p;
        } else {
            newSrcPackages[newSrcCount++] = p;
        }
    }

    free(src->packages);
    src->packages = newSrcPackages;
    src->packages_count = newSrcCount;
}

/* Find town with most packages */
town town_with_most_packages(town *towns, int towns_count) {
    int maxCount = -1;
    int index = 0;
    for (int i = 0; i < towns_count; i++) {
        int total = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            total += towns[i].offices[j].packages_count;
        }
        if (total > maxCount) {
            maxCount = total;
            index = i;
        }
    }
    return towns[index];
}

/* Find town by name */
town* find_town(town *towns, int towns_count, char *name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL;
}

int main() {
    int towns_count;
    scanf("%d", &towns_count);

    town *towns = (town *)malloc(towns_count * sizeof(town));

    for (int i = 0; i < towns_count; i++) {
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = (post_office *)malloc(towns[i].offices_count * sizeof(post_office));

        for (int j = 0; j < towns[i].offices_count; j++) {
            int packages_count, min_weight, max_weight;
            scanf("%d %d %d", &packages_count, &min_weight, &max_weight);
            towns[i].offices[j].packages_count = packages_count;
            towns[i].offices[j].min_weight = min_weight;
            towns[i].offices[j].max_weight = max_weight;
            towns[i].offices[j].packages = (package *)malloc(packages_count * sizeof(package));

            for (int k = 0; k < packages_count; k++) {
                scanf("%s %d", towns[i].offices[j].packages[k].id, &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);

    for (int q = 0; q < queries; q++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char townName[11];
            scanf("%s", townName);
            town *t = find_town(towns, towns_count, townName);
            print_all_packages(*t);
        } else if (type == 2) {
            char sourceName[11], targetName[11];
            int sourceIndex, targetIndex;
            scanf("%s %d %s %d", sourceName, &sourceIndex, targetName, &targetIndex);
            town *srcTown = find_town(towns, towns_count, sourceName);
            town *dstTown = find_town(towns, towns_count, targetName);
            send_all_packages(srcTown, sourceIndex, dstTown, targetIndex);
        } else if (type == 3) {
            town t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t.name);
        }
    }

    /* Free memory */
    for (int i = 0; i < towns_count; i++) {
        for (int j = 0; j < towns[i].offices_count; j++) {
            free(towns[i].offices[j].packages);
        }
        free(towns[i].offices);
    }
    free(towns);

    return 0;
}

