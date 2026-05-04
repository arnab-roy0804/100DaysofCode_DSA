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
        int p = (i-1)/2;
        if (heap[p].dist > heap[i].dist) {
            HeapNode t = heap[p]; heap[p] = heap[i]; heap[i] = t; i = p;
        } else break;
    }
}

HeapNode pop() {
    HeapNode top = heap[0]; heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, s = i;
        if (l < heapSize && heap[l].dist < heap[s].dist) s = l;
        if (r < heapSize && heap[r].dist < heap[s].dist) s = r;
        if (s == i) break;
        HeapNode t = heap[i]; heap[i] = heap[s]; heap[s] = t; i = s;
    }
    return top;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) adj[i] = NULL;
    for (int i = 0; i < m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w); addEdge(u, v, w);
    }
    int src; scanf("%d", &src);
    double dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[src] = 0; push(src, 0);
    while (heapSize > 0) {
        HeapNode curr = pop();
        Node* nb = adj[curr.v];
        while (nb) {
            if (dist[curr.v] + nb->weight < dist[nb->data]) {
                dist[nb->data] = dist[curr.v] + nb->weight;
                push(nb->data, dist[nb->data]);
            }
            nb = nb->next;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%.0f", dist[i]);
    }
    printf("\n");
    return 0;
}