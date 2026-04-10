#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    pq[size++] = x;
}

void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    int minIdx = 0;
    for (int i = 1; i < size; i++)
        if (pq[i] < pq[minIdx])
            minIdx = i;
    printf("%d\n", pq[minIdx]);
    pq[minIdx] = pq[--size];
}

void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    int min = pq[0];
    for (int i = 1; i < size; i++)
        if (pq[i] < min)
            min = pq[i];
    printf("%d\n", min);
}

int main() {
    int n;
    scanf("%d", &n);
    char op[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') {
            delete();
        } else {
            peek();
        }
    }
    return 0;
}