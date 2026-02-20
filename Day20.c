#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    long long count = 0;
    long long prefix = 0;
    int *map = calloc(MAX * 2, sizeof(int));
    map[MAX] = 1;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        count += map[prefix + MAX];
        map[prefix + MAX]++;
    }

    printf("%lld\n", count);
    free(map);
    return 0;
}
