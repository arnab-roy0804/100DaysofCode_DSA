#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    int value = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();
            int result;
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result);
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main() {
    char expr[100];
    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);
    return 0;
}
