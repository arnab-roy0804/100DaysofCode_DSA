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

#define OFFSET 100
int col_data[200][100];
int col_count[200];

void dfs(Node* root, int col) {
    if (!root) return;
    col_data[col + OFFSET][col_count[col + OFFSET]++] = root->data;
    dfs(root->left, col - 1);
    dfs(root->right, col + 1);
}

int main() {
    int n; scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    Node* root = buildTree(arr, n);

    for (int i = 0; i < 200; i++) col_count[i] = 0;
    dfs(root, 0);

    for (int i = 0; i < 200; i++) {
        if (col_count[i] > 0) {
            for (int j = 0; j < col_count[i]; j++) {
                if (j) printf(" ");
                printf("%d", col_data[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}