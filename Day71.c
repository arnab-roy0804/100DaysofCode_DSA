#include <stdio.h>
#include <string.h>

int main() {
    int m;
    scanf("%d", &m);
    int table[m];
    for (int i = 0; i < m; i++) table[i] = -1;
    int q; scanf("%d", &q);
    while (q--) {
        char op[10]; int key;
        scanf("%s %d", op, &key);
        int h = key % m;
        if (strcmp(op, "INSERT") == 0) {
            for (int i = 0; i < m; i++) {
                int idx = (h + i * i) % m;
                if (table[idx] == -1) { table[idx] = key; break; }
            }
        } else {
            int found = 0;
            for (int i = 0; i < m; i++) {
                int idx = (h + i * i) % m;
                if (table[idx] == key) { found = 1; break; }
                if (table[idx] == -1) break;
            }
            printf("%s\n", found ? "FOUND" : "NOT FOUND");
        }
    }
    return 0;
}