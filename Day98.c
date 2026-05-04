#include <stdio.h>
#include <stdlib.h>

typedef struct { int s, e; } Interval;
int cmp(const void* a, const void* b) { return ((Interval*)a)->s - ((Interval*)b)->s; }

int main() {
    int n; scanf("%d", &n);
    Interval arr[n];
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].s, &arr[i].e);
    qsort(arr, n, sizeof(Interval), cmp);
    int resIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[resIdx].e >= arr[i].s) {
            if (arr[i].e > arr[resIdx].e) arr[resIdx].e = arr[i].e;
        } else {
            resIdx++; arr[resIdx] = arr[i];
        }
    }
    for (int i = 0; i <= resIdx; i++) printf("[%d,%d] ", arr[i].s, arr[i].e);
    return 0;
}