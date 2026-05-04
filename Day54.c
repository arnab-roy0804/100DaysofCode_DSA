#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val; n->left = n->right = NULL;
    return n;
}

Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node* root = newNode(arr[0]);
    Node* q[100]; int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (f < r && i < n) {
        Node* curr = q[f++];
        if (i < n && arr[i] != -1) { curr->left = newNode(arr[i]); q[r++] = curr->left; } i++;
        if (i < n && arr[i] != -1) { curr->right = newNode(arr[i]); q[r++] = curr->right; } i++;
    }
    return root;
}

void zigzag(Node* root) {
    if (!root) return;
    Node* q[100]; int f = 0, r = 0;
    q[r++] = root;
    int level = 0, first = 1;
    while (f < r) {
        int size = r - f;
        int buf[100];
        for (int i = 0; i < size; i++) {
            Node* curr = q[f++];
            buf[i] = curr->data;
            if (curr->left)  q[r++] = curr->left;
            if (curr->right) q[r++] = curr->right;
        }
        if (level % 2 == 0)
            for (int i = 0; i < size; i++) { if (!first) printf(" "); printf("%d", buf[i]); first = 0; }
        else
            for (int i = size - 1; i >= 0; i--) { if (!first) printf(" "); printf("%d", buf[i]); first = 0; }
        level++;
    }
    printf("\n");
}

int main() {
    int n; scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    zigzag(buildTree(arr, n));
    return 0;
}