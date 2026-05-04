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

void bfs(int s, int n) {
    int queue[n], front = 0, rear = 0;
    visited[s] = 1;
    queue[rear++] = s;
    int first = 1;
    while (front < rear) {
        int v = queue[front++];
        if (!first) printf(" ");
        printf("%d", v);
        first = 0;
        Node* curr = adj[v];
        while (curr) {
            if (!visited[curr->data]) {
                visited[curr->data] = 1;
                queue[rear++] = curr->data;
            }
            curr = curr->next;
        }
    }
    printf("\n");
}

int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) { adj[i] = NULL; visited[i] = 0; }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    scanf("%d", &s);
    bfs(s, n);
    return 0;
}