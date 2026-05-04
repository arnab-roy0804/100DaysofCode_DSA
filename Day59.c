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

int postIdx;

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

Node* build(int inorder[], int postorder[], int start, int end) {
    if (start > end) return NULL;
    Node* root = newNode(postorder[postIdx--]);
    int idx = search(inorder, start, end, root->data);
    root->right = build(inorder, postorder, idx + 1, end);
    root->left = build(inorder, postorder, start, idx - 1);
    return root;
}

int first = 1;
void preorder(Node* root) {
    if (!root) return;
    if (!first) printf(" ");
    printf("%d", root->data);
    first = 0;
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    postIdx = n - 1;
    Node* root = build(in, post, 0, n - 1);
    preorder(root);
    printf("\n");
    return 0;
}