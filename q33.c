#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the Stack structure
typedef struct Stack {
    int top;
    int capacity;
    char* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Standard Stack operations
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // Return a dummy character if empty
}

char peek(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top];
    return '$';
}

// Function to return the precedence of operators
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3; // Exponentiation has the highest precedence
    }
    return -1;
}

// Core Algorithm: Convert Infix to Postfix
void infixToPostfix(char* exp) {
    int i, k;
    int len = strlen(exp);
    Stack* stack = createStack(len);
    
    // We will overwrite the original string to save space, 
    // using 'k' to track the index of our postfix output.
    for (i = 0, k = -1; i < len; ++i) {
        
        // 1. If the scanned character is an operand, add it to output.
        if (isalnum(exp[i])) {
            exp[++k] = exp[i];
        }
        // 2. If the scanned character is an '(', push it to the stack.
        else if (exp[i] == '(') {
            push(stack, exp[i]);
        }
        // 3. If the scanned character is an ')', pop and output from the stack 
        // until an '(' is encountered.
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                exp[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack); // Discard the '('
            }
        }
        // 4. If an operator is scanned
        else {
            while (!isEmpty(stack) && getPrecedence(exp[i]) <= getPrecedence(peek(stack))) {
                // Handle right-to-left associativity for exponentiation specially if needed.
                // For standard + - * /, left-to-right applies.
                exp[++k] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }
    
    // 5. Pop all the remaining operators from the stack
    while (!isEmpty(stack)) {
        exp[++k] = pop(stack);
    }
    
    // Null-terminate the resulting string
    exp[++k] = '\0';
    
    printf("%s\n", exp);
    
    // Clean up memory
    free(stack->array);
    free(stack);
}

int main() {
    char exp[1000];
    
    // Read the infix expression
    if (scanf("%s", exp) == 1) {
        infixToPostfix(exp);
    }
    
    return 0;
}