#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30   // Maximum size of the stack

int top = -1;            // Stack pointer (initially empty)
int stack[MAX];          // Array to implement the stack

// Function prototypes
void push(char item);
char pop();
int match(char a, char b);
int check(char exp[]);

int main() {
    char exp[MAX];
    int valid;
    
    // Prompt the user to enter an algebraic expression
    printf("Enter an algebraic expression: ");
    // Note: 'gets' is unsafe, consider using 'fgets' in production code.
    gets(exp);
    
    // Check if the expression has balanced parentheses
    valid = check(exp);
    
    // Output the result based on validity
    if (valid == 1)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");

    return 0;
}

// Function to check if the parentheses in the expression are balanced
int check(char exp[]) {
    int i;
    char temp;
    
    // Loop through each character in the expression
    for (i = 0; i < strlen(exp); i++) {
        // If an opening parenthesis is encountered, push it onto the stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        
        // If a closing parenthesis is encountered
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            // If stack is empty, there is no matching opening parenthesis
            if (top == -1) {
                printf("Right parentheses are more than left parentheses\n");
                return 0;
            } else {
                // Pop the top element and check if it matches the closing parenthesis
                temp = pop();
                if (!match(temp, exp[i])) {
                    printf("Mismatched parentheses are: %c and %c\n", temp, exp[i]);
                    return 0;
                }
            }
        }
    }
    
    // If the stack is empty, all parentheses matched; otherwise, there are extra left parentheses
    if (top == -1) {
        printf("Balanced Parentheses\n");
        return 1;
    } else {
        printf("Left parentheses more than right parentheses\n");
        return 0;
    }
}

// Function to check if the pair of parentheses match
int match(char a, char b) {
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    return 0;
}

// Function to push an item onto the stack
void push(char item) {
    // Check for stack overflow
    if (top == (MAX - 1)) {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}

// Function to pop an item from the stack
char pop() {
    // Check for stack underflow
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
