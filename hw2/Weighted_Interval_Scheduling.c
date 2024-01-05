#include <stdio.h>
#pragma warning( disable : 4996 )
typedef struct work {
    int start;
    int end;
    int profit;
}Work;


int max(int a, int b) {
    if (a > b) return a;
    else    return b;
}

int cmp(const Work* c, const Work* d) {
    return c->end - d->end;
}

int NotOverlap(Work c, Work d) {
    return c.end <= d.start;
}

int main() {
    int n;
    scanf("%d", &n);

    Work works[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &works[i].start, &works[i].end);
        works[i].profit = works[i].end - works[i].start;
    }

    qsort(works, n, sizeof(works[0]), cmp);


    int U, V;
    scanf("%d%d", &U, &V);

    int dpMemo[1000];



    for (int i = 0; i < n; i++) {
        if (works[i].start < U) dpMemo[i] = 0;
        else dpMemo[i] = works[i].profit;
    }


    int maxP = 0;
    for (int i = 1; i < n; i++) {

        if (works[i].start < U)    continue;
        if (works[i].end > V)  break;

        for (int j = 0; j < i; j++) {

            if (NotOverlap(works[j], works[i])) {
                dpMemo[i] = max(dpMemo[i], dpMemo[j] + works[i].profit);
                maxP = max(maxP, dpMemo[i]);
            }

        }

    }

    printf("%d", maxP);
}