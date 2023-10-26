// 1 Write a program to convert the expression a+b in to ab+


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a stack data structure for characters
struct CharStack {
    int top;
    unsigned capacity;
    char* array;
};

// Create a new character stack
struct CharStack* createCharStack(unsigned capacity) {
    struct CharStack* stack = (struct CharStack*)malloc(sizeof(struct CharStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Check if the stack is empty
int isEmpty(struct CharStack* stack) {
    return stack->top == -1;
}

// Push a character onto the stack
void push(struct CharStack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Pop a character from the stack
char pop(struct CharStack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0'; // Null character signifies an empty stack
}

// Get the top character from the stack without popping
char peek(struct CharStack* stack) {
    return stack->array[stack->top];
}

// Function to check if a character is an operator (+ or -)
int isOperator(char ch) {
    return (ch == '+' || ch == '-');
}

// Function to convert infix expression to postfix notation
char* infixToPostfix(char* infix) {
    int i, j;
    int len = strlen(infix);
    struct CharStack* stack = createCharStack(len);
    char* postfix = (char*)malloc((len + 1) * sizeof(char));

    if (!stack || !postfix) {
        printf("Memory allocation error\n");
        exit(1);
    }

    for (i = 0, j = 0; i < len; i++) {
        char ch = infix[i];
        if (ch >= 'a' && ch <= 'z') {
            postfix[j++] = ch;
        } else if (isOperator(ch)) {
            while (!isEmpty(stack) && isOperator(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    return postfix;
}

int main() {
    char infix[] = "a+b";
    char* postfix = infixToPostfix(infix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    free(postfix); // Free allocated memory
    return 0;
}
