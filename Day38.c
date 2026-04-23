#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *rear;
    int size;
} Deque;

void initDeque(Deque *dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

bool empty(Deque *dq) {
    return dq->size == 0;
}

void push_front(Deque *dq, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (empty(dq)) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

void push_back(Deque *dq, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = dq->rear;
    newNode->next = NULL;

    if (empty(dq)) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

void pop_front(Deque *dq) {
    if (empty(dq)) return;

    Node *temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
    dq->size--;
}

void pop_back(Deque *dq) {
    if (empty(dq)) return;

    Node *temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
    dq->size--;
}

int front(Deque *dq) {
    return (dq->front != NULL) ? dq->front->data : -1;
}

int back(Deque *dq) {
    return (dq->rear != NULL) ? dq->rear->data : -1;
}

void clear(Deque *dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

void display(Deque *dq) {
    Node *temp = dq->front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque myDeque;
    initDeque(&myDeque);

    push_back(&myDeque, 10);
    push_back(&myDeque, 20);
    push_front(&myDeque, 5);
    display(&myDeque);

    printf("Front: %d\n", front(&myDeque));
    printf("Rear: %d\n", back(&myDeque));
    printf("Size: %d\n", myDeque.size);

    pop_front(&myDeque);
    display(&myDeque);

    pop_back(&myDeque);
    display(&myDeque);

    clear(&myDeque);
    printf("Is empty? %s\n", empty(&myDeque) ? "Yes" : "No");

    return 0;
}