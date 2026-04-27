#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front, *rear;
} Queue;

void enqueue(Queue *q, int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue *q) {
    if (q->front == NULL) return -1;
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

void reverseQueue(Queue *q) {
    int stack[1000]; 
    int top = -1;

    while (q->front != NULL) {
        stack[++top] = dequeue(q);
    }

    while (top != -1) {
        enqueue(q, stack[top--]);
    }
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    Queue q = {NULL, NULL};

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    reverseQueue(&q);

    Node *temp = q.front;
    while (temp != NULL) {
        printf("%d%s", temp->data, temp->next ? " " : "");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}