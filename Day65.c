#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[100];
int visited[100];

void addEdge(int u, int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v; n->next = adj[u]; adj[u] = n;
    n = (Node*)malloc(sizeof(Node));
    n->data = u; n->next = adj[v]; adj[v] = n;
}

int dfs(int v, int parent) {
    visited[v] = 1;
    Node* curr = adj[v];
    while (curr) {
        if (!visited[curr->data]) {
            if (dfs(curr->data, v)) return 1;
        } else if (curr->data != parent) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) { adj[i] = NULL; visited[i] = 0; }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    int hasCycle = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dfs(i, -1)) { hasCycle = 1; break; }
    printf("%s\n", hasCycle ? "YES" : "NO");
    return 0;
}