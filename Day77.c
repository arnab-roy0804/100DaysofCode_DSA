#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node* next; } Node;
Node* adj[100];
int visited[100];

void addEdge(int u, int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v; n->next = adj[u]; adj[u] = n;
    n = (Node*)malloc(sizeof(Node));
    n->data = u; n->next = adj[v]; adj[v] = n;
}

void dfs(int v) {
    visited[v] = 1;
    Node* curr = adj[v];
    while (curr) { if (!visited[curr->data]) dfs(curr->data); curr = curr->next; }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) { adj[i] = NULL; visited[i] = 0; }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v); addEdge(u, v);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (!visited[i]) { printf("NOT CONNECTED\n"); return 0; }
    printf("CONNECTED\n");
    return 0;
}