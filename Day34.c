#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* expression) {
    struct Node* stack = NULL;
    char* token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&stack, atoi(token));
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            switch (token[0]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                default: printf("Invalid operator\n"); exit(1);
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    char expression[] = "2 3 1 * + 9 -";
    int result = evaluatePostfix(expression);
    printf("%d\n", result);
    return 0;
}
