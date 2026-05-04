#include <stdio.h>
#include <stdlib.h>

typedef struct { int pos; double time; } Car;
int cmpCar(const void* a, const void* b) { return ((Car*)b)->pos - ((Car*)a)->pos; }

int main() {
    int target, n; scanf("%d %d", &target, &n);
    Car cars[n];
    for (int i = 0; i < n; i++) {
        int s; scanf("%d %d", &cars[i].pos, &s);
        cars[i].time = (double)(target - cars[i].pos) / s;
    }
    qsort(cars, n, sizeof(Car), cmpCar);
    int fleets = 0; double lastTime = 0;
    for (int i = 0; i < n; i++) {
        if (cars[i].time > lastTime) { fleets++; lastTime = cars[i].time; }
    }
    printf("%d\n", fleets);
    return 0;
}