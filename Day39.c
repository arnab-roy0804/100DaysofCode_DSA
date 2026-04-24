#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MinHeap {
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    h->capacity = capacity;
    h->size = 0;
    h->arr = (int*)malloc(capacity * sizeof(int));
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *h, int x) {
    if (h->size == h->capacity) return;
    h->size++;
    int i = h->size - 1;
    h->arr[i] = x;
    while (i != 0 && h->arr[(i - 1) / 2] > h->arr[i]) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapify(MinHeap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;
    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        minHeapify(h, smallest);
    }
}

int extractMin(MinHeap *h) {
    if (h->size <= 0) return -1;
    if (h->size == 1) {
        h->size--;
        return h->arr[0];
    }
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    minHeapify(h, 0);
    return root;
}

int peek(MinHeap *h) {
    if (h->size <= 0) return -1;
    return h->arr[0];
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    MinHeap *h = createHeap(n);
    char op[20];
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(h, val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin(h));
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek(h));
        }
    }
    free(h->arr);
    free(h);
    return 0;
}