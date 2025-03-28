/* 
 * Evaluating Postfix Expressions in C
 * Using a linked list to implement a stack
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 
 // Define a node structure for the linked list stack
typedef struct node {
     int data;               // Data stored in the node (operand)
     struct node* link;   // Pointer to the next node in the stack
 }Node;
 
 
 // Global pointer to the top of the stack
 Node* top = NULL;
 
 // Function to push a data value onto the stack
 void push(int ip) {
     // Allocate memory for a new node
     Node* temp = (Node*)malloc(sizeof(Node));
     if (temp == NULL) {
         printf("Memory allocation failed!\n");
         exit(EXIT_FAILURE);
     }
     temp->data = ip;      // Set the data
     temp->link = top;    // Link the new node to the current top
     top = temp;             // Update the top pointer to the new node
 }
 
 // Function to pop the top element from the stack and return its value
 int pop() {
     // Check for stack underflow
     if (top == NULL) {
         printf("Stack underflow!\n");
         exit(EXIT_FAILURE);
     }
     int value = top->data;   // Retrieve the data from the top node
     Node* temp = top;     // Save the current top for freeing memory
     top = top->link;      // Update top pointer to the next node
     free(temp);              // Free the memory of the popped node
     return value;            // Return the popped value
 }
 
 // Function to evaluate a postfix expression
 int evaluatePostfix(char* exp) 
 {
     for (int i = 0; exp[i] != '\0'; i++) {
         // If the current character is a digit, convert it to an integer and push onto stack
         if (isdigit(exp[i])) {
             push(exp[i] - '0');
         } else {
             // For an operator, pop the top two elements from the stack
             int operand2 = pop();  // Note: operand2 is popped first
             int operand1 = pop();
             // Perform the operation based on the operator
             switch (exp[i]) {
                 case '+':
                     push(operand1 + operand2);
                     break;
                 case '-':
                     push(operand1 - operand2);
                     break;
                 case '*':
                     push(operand1 * operand2);
                     break;
                 case '/':
                     push(operand1 / operand2);
                     break;
                 default:
                     // If an invalid operator is encountered, display an error and exit
                     printf("Invalid operator encountered: %c\n", exp[i]);
                     exit(EXIT_FAILURE);
             }
         }
     }
     // The final result is the only element left in the stack
     return pop();
 }
 
 // Main function to drive the program
 int main() {
     char exp[100];
     
     // Prompt the user for a postfix expression
     printf("Enter a postfix expression: ");
     scanf("%s", exp);
     
     // Evaluate the postfix expression and display the result
     int result = evaluatePostfix(exp);
     printf("Result: %d\n", result);
     
     return 0;
 }
 