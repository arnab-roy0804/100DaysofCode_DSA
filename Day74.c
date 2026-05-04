#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { char name[50]; int votes; } Candidate;

int cmp(const void* a, const void* b) {
    Candidate* ca = (Candidate*)a;
    Candidate* cb = (Candidate*)b;
    if (cb->votes != ca->votes) return cb->votes - ca->votes;
    return strcmp(ca->name, cb->name);
}

int main() {
    int n; scanf("%d", &n);
    Candidate table[100];
    int size = 0;
    for (int i = 0; i < n; i++) {
        char name[50]; scanf("%s", name);
        int found = 0;
        for (int j = 0; j < size; j++)
            if (strcmp(table[j].name, name) == 0) { table[j].votes++; found = 1; break; }
        if (!found) { strcpy(table[size].name, name); table[size++].votes = 1; }
    }
    qsort(table, size, sizeof(Candidate), cmp);
    printf("%s %d\n", table[0].name, table[0].votes);
    return 0;
}