#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void addEdge(Node* adj[], int u, int v) {
    Node* nu = newNode(v);
    nu->next = adj[u];
    adj[u] = nu;
    Node* nv = newNode(u);
    nv->next = adj[v];
    adj[v] = nv;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* curr = adj[i];
        while (curr) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
    return 0;
}