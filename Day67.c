#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node* next; } Node;

Node* adj[100];
int visited[100];
int stack[100], top = -1;

void addEdge(int u, int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v; n->next = adj[u]; adj[u] = n;
}

void dfs(int v) {
    visited[v] = 1;
    Node* curr = adj[v];
    while (curr) {
        if (!visited[curr->data]) dfs(curr->data);
        curr = curr->next;
    }
    stack[++top] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) { adj[i] = NULL; visited[i] = 0; }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs(i);
    for (int i = top; i >= 0; i--) {
        if (i != top) printf(" ");
        printf("%d", stack[i]);
    }
    printf("\n");
    return 0;
}