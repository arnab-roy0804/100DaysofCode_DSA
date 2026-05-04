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

Node* lca(Node* root, int p, int q) {
    if (!root || root->data == p || root->data == q) return root;
    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int n; scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    Node* root = buildTree(arr, n);
    int p, q; scanf("%d %d", &p, &q);
    printf("%d\n", lca(root, p, q)->data);
    return 0;
}