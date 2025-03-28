
//link https://chatgpt.com/share/67e63f5e-529c-800b-9554-96b666b6fb1e

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct node 
{
    int data;            // Data part of the node
    struct node *link;    // Pointer to the next node
} *top, *top1, *temp;     // Global pointers to manage the stack

// Global count of stack elements
int count = 0;

// Function prototypes
int topelement();
void push(int in);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();

void main() 
{
    int no, ch, e;

    // Display menu options
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Stack Count");
    printf("\n 8 - Destroy stack");

    // Initialize the stack
    create();

    // Loop indefinitely to process user choices
    while (1) 
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);

        // Switch based on user's choice
        switch (ch)
        {
            case 1:
                // Push operation
                printf("Enter data : ");
                scanf("%d", &no);
                push(no);
                break;

            case 2:
                // Pop operation
                pop();
                break;

            case 3:
                // Get the top element
                if (top == NULL)
                    printf("No elements in stack");
                else {
                    e = topelement();
                    printf("\n Top element : %d", e);
                }
                break;

            case 4:
                // Check if stack is empty
                empty();
                break;

            case 5:
                // Exit the program
                exit(0);

            case 6:
                // Display all stack elements
                display();
                break;

            case 7:
                // Display the count of elements in the stack
                stack_count();
                break;

            case 8:
                // Destroy the stack
                destroy();
                break;

            default:
                printf("Wrong choice, Please enter correct choice ");
                break;
        }
    }
}

/* Create an empty stack */
void create() {
    top = NULL;
}

/* Display the number of elements in the stack */
void stack_count() {
    printf("\n No. of elements in stack : %d", count);
}

/* Push data into the stack */
void push(int in) {
    // If stack is empty, create the first node
    if (top == NULL) {
        top = (struct node *)malloc(sizeof(struct node));
        top->link = NULL;      // Next pointer is NULL since it's the only element
        top->data = in;     // Assign data to the node
    } else {
        // Create a new node and add it to the top of the stack
        temp = (struct node *)malloc(sizeof(struct node));
        temp->link = top;      // New node's pointer now points to the current top
        temp->data = in;    // Assign data to the new node
        top = temp;           // Update top to the new node
    }
    count++; // Increase count of stack elements
}

/* Display all stack elements */
void display() {
    top1 = top;
    if (top1 == NULL) {
        printf("Stack is empty");
        return;
    }
    // Traverse the stack and print each element
    while (top1 != NULL) {
        printf("%d ", top1->data);
        top1 = top1->link;
    }
}

/* Pop the top element from the stack */
void pop() {
    top1 = top;
    if (top1 == NULL) {
        printf("\n Error : Trying to pop from empty stack");
        return;
    } else {
        // Move the top pointer to the next node
        top1 = top1->link;
        // Print the value that is being popped
        printf("\n Popped value : %d", top->data);
        free(top);   // Free the memory of the popped node
        top = top1;  // Update top to the new top of the stack
        count--;     // Decrease count of stack elements
    }
}

/* Return the top element of the stack */
int topelement() {
    return(top->data);
}

/* Check if the stack is empty or not */
void empty() {
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}

/* Destroy the entire stack */
void destroy() {
    top1 = top;
    // Loop to free all nodes in the stack
    while (top1 != NULL) {
        top1 = top->link;   // Move top1 to the next node
        free(top);         // Free the current top node
        top = top1;        // Update top to the new node
        // The following line is unnecessary because top1 is already updated
        // top1 = top1->link;
    }
    top = NULL;
    printf("\n All stack elements destroyed");
    count = 0;  // Reset count to 0
}
