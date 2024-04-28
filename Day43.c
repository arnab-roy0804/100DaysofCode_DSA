#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    if (data == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* constructTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        Node* curr = queue[front++];

        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
        }

        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    free(queue);
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = constructTree(arr, n);
    inorder(root);
    printf("\n");

    return 0;
}