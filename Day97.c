#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int main() {
    int n; scanf("%d", &n);
    int start[n], end[n];
    for (int i = 0; i < n; i++) scanf("%d %d", &start[i], &end[i]);
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);
    int rooms = 0, max_rooms = 0, i = 0, j = 0;
    while (i < n) {
        if (start[i] < end[j]) { rooms++; i++; }
        else { rooms--; j++; }
        if (rooms > max_rooms) max_rooms = rooms;
    }
    printf("%d\n", max_rooms);
    return 0;
}