#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop() {
    int val = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char token[20];
    while (scanf("%s", token) == 1) {
        if (isdigit(token[0]) || (token[0] == '-' && token[1] != '\0')) {
            push(atoi(token));
        } else {
            int b = pop(), a = pop(), result;
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            push(result);
        }
    }
    printf("%d\n", pop());
    return 0;
}