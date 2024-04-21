#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;
int size = 0;

void enqueue(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = front;
    if (rear == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    size++;
}

void rotate() {
    if (front == NULL) return;
    rear = front;
    front = front->next;
    rear->next = front;
}

void display() {
    if (front == NULL) return;
    struct Node *temp = front;
    for (int i = 0; i < size; i++) {
        printf("%d", temp->data);
        if (i < size - 1) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        rotate();
    }
    display();
    return 0;
}