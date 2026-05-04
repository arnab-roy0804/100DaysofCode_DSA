#include <stdio.h>
#define INF 1e9
#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    double graph[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = (i == j) ? 0 : INF;
    for (int i = 0; i < m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;
    }
    double key[MAX]; int inMST[MAX];
    for (int i = 1; i <= n; i++) { key[i] = INF; inMST[i] = 0; }
    key[1] = 0;
    double total = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;
        inMST[u] = 1;
        total += key[u];
        for (int v = 1; v <= n; v++)
            if (!inMST[v] && graph[u][v] < key[v])
                key[v] = graph[u][v];
    }
    printf("%.0f\n", total);
    return 0;
}