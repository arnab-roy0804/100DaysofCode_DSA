#include <stdio.h>

typedef struct { int val, id; } Pair;
int count[100005];

void mergeCount(Pair arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Pair L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l, rightCounter = 0;
    while (i < n1 && j < n2) {
        if (R[j].val < L[i].val) { rightCounter++; arr[k++] = R[j++]; }
        else { count[L[i].id] += rightCounter; arr[k++] = L[i++]; }
    }
    while (i < n1) { count[L[i].id] += rightCounter; arr[k++] = L[i++]; }
    while (j < n2) arr[k++] = R[j++];
}

void solve(Pair arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        solve(arr, l, m); solve(arr, m + 1, r);
        mergeCount(arr, l, m, r);
    }
}

int main() {
    int n; scanf("%d", &n);
    Pair arr[n];
    for (int i = 0; i < n; i++) { scanf("%d", &arr[i].val); arr[i].id = i; count[i] = 0; }
    solve(arr, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", count[i]);
    return 0;
}