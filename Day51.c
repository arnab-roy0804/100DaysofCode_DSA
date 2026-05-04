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

Node* insert(Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

Node* lca(Node* root, int p, int q) {
    if (!root) return NULL;
    if (p < root->data && q < root->data) return lca(root->left, p, q);
    if (p > root->data && q > root->data) return lca(root->right, p, q);
    return root;
}

int main() {
    int n; scanf("%d", &n);
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        root = insert(root, val);
    }
    int p, q; scanf("%d %d", &p, &q);
    printf("%d\n", lca(root, p, q)->data);
    return 0;
}