#include <stdio.h>
#include <stdlib.h>
#define INF 1e9

typedef struct Node { int data, weight; struct Node* next; } Node;
typedef struct { int v, dist; } HeapNode;

Node* adj[100];
HeapNode heap[10000];
int heapSize = 0;

void addEdge(int u, int v, int w) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v; n->weight = w; n->next = adj[u]; adj[u] = n;
    n = (Node*)malloc(sizeof(Node));
    n->data = u; n->weight = w; n->next = adj[v]; adj[v] = n;
}

void push(int v, int d) {
    heap[heapSize].v = v; heap[heapSize].dist = d;
    int i = heapSize++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].dist > heap[i].dist) {
            HeapNode tmp = heap[p]; heap[p] = heap[i]; heap[i] = tmp;
            i = p;
        } else break;
    }
}

HeapNode pop() {
    HeapNode top = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if (l < heapSize && heap[l].dist < heap[smallest].dist) smallest = l;
        if (r < heapSize && heap[r].dist < heap[smallest].dist) smallest = r;
        if (smallest == i) break;
        HeapNode tmp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) adj[i] = NULL;
    for (int i = 0; i < m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    int src; scanf("%d", &src);
    double dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;
    push(src, 0);
    while (heapSize > 0) {
        HeapNode curr = pop();
        int v = curr.v;
        Node* nb = adj[v];
        while (nb) {
            if (dist[v] + nb->weight < dist[nb->data]) {
                dist[nb->data] = dist[v] + nb->weight;
                push(nb->data, dist[nb->data]);
            }
            nb = nb->next;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        if (dist[i] == INF) printf("INF");
        else printf("%.0f", dist[i]);
    }
    printf("\n");
    return 0;
}