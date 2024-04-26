#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

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
    if (q->front == NULL) {
        return -1;
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    Queue q;
    initQueue(&q);
    
    char op[20];
    int val;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &val);
            enqueue(&q, val);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(&q));
        }
    }
    
    while (q.front != NULL) {
        dequeue(&q);
    }
    
    return 0;
}