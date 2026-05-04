#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int preIdx = 0;

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

Node* build(int preorder[], int inorder[], int start, int end) {
    if (start > end) return NULL;
    Node* root = newNode(preorder[preIdx++]);
    int idx = search(inorder, start, end, root->data);
    root->left = build(preorder, inorder, start, idx - 1);
    root->right = build(preorder, inorder, idx + 1, end);
    return root;
}

int first = 1;
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    if (!first) printf(" ");
    printf("%d", root->data);
    first = 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    Node* root = build(pre, in, 0, n - 1);
    postorder(root);
    printf("\n");
    return 0;
}