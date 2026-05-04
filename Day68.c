#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node* next; } Node;

Node* adj[100];
int indegree[100];

void addEdge(int u, int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v; n->next = adj[u]; adj[u] = n;
    indegree[v]++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) { adj[i] = NULL; indegree[i] = 0; }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    int queue[100], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) queue[rear++] = i;
    int first = 1;
    while (front < rear) {
        int v = queue[front++];
        if (!first) printf(" ");
        printf("%d", v);
        first = 0;
        Node* curr = adj[v];
        while (curr) {
            if (--indegree[curr->data] == 0) queue[rear++] = curr->data;
            curr = curr->next;
        }
    }
    printf("\n");
    return 0;
}