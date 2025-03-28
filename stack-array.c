
//link https://chatgpt.com/share/67e63eee-b4b4-800b-b368-cbf5e605b4d8

#include <stdio.h>
#define MAX 100  // Maximum stack size

// Global variables
int stack[MAX], choice, n, top, x, i;

// Function prototypes
void push(void);
void pop(void);
void display(void);

int main()
 {
    // Initialize top index to -1 to indicate that the stack is empty
    top = -1;
    
    // Get the desired size of the stack from the user (should be <= MAX)
    printf("\nEnter the size of STACK (MAX = %d): ", MAX);
    scanf("%d", &n);
    
    // Display the menu for stack operations
    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t-----------------------------");
    printf("\n\t1. PUSH");
    printf("\n\t2. POP");
    printf("\n\t3. DISPLAY");
    printf("\n\t4. EXIT");

    // Loop until the user chooses to exit
    do 
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        // Process the user choice using a switch-case structure
        switch(choice) 
        {
            case 1:
                // Push an element onto the stack
                push();
                break;
            case 2:
                // Pop an element from the stack
                pop();
                break;
            case 3:
                // Display the elements in the stack
                display();
                break;
            case 4:
                // Exit the program
                printf("\n\tExiting program. Goodbye!\n");
                break;
            default:
                // Handle invalid choices
                printf("\n\tPlease enter a valid choice (1/2/3/4).");
        }
    } while (choice != 4);

    return 0;
}

// Function to push an element onto the stack
void push()
 {
    // Check if the stack is full (overflow)
    if (top >= n - 1) 
    {
        printf("\n\tSTACK overflow! Cannot push element.");
    } else 
    {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;           // Increment the top index
        stack[top] = x;  // Add the element to the stack
    }
}

// Function to pop an element from the stack
void pop() 
{
    // Check if the stack is empty (underflow)
    if (top <= -1)
    {
        printf("\n\tSTACK underflow! Cannot pop element.");
    } else 
    {
        printf("\n\tThe popped element is %d", stack[top]);
        top--;  // Decrement the top index to remove the element
    }
}

// Function to display the elements in the stack
void display() 
{
    // Check if the stack has any elements
    if (top >= 0) 
    {
        printf("\nThe elements in the STACK are:\n");
        // Print all elements from the top to the bottom
        for (i = top; i >= 0; i--) 
        {
            printf("%d\n", stack[i]);
        }
        printf("\nPress Next Choice");
    } 
    else 
    {
        printf("\nThe STACK is empty.");
    }
}
