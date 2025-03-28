#include <stdio.h>

#define MAX 6  // Maximum size of the queue

int queue[MAX];  // Array to hold queue elements
int front = -1;  // Index of the front element in the queue
int rear = -1;   // Index of the rear element in the queue

// Function to insert an element into the circular queue
void enqueue(int element) {
    // Check if the queue is empty
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    // Check if the queue is full
    else if ((rear + 1) % MAX == front) {
        printf("Queue overflow. Cannot insert element.\n");
    }
    else {
        // Move rear pointer to the next position in a circular manner
        rear = (rear + 1) % MAX;
        queue[rear] = element;
    }
}

// Function to remove an element from the circular queue
int dequeue() {
    // Check if the queue is empty
    if (front == -1 && rear == -1) {
        printf("Queue underflow. No element to delete.\n");
        return -1;  // Return error value if queue is empty
    }

    int element = queue[front];  // Element to be dequeued

    // If there is only one element in the queue
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        // Move front pointer to the next position in a circular manner
        front = (front + 1) % MAX;
    }

    printf("Dequeued element is %d\n", element);
    return element;
}

// Function to display the elements in the circular queue
void display() {
    // Check if the queue is empty
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Elements in the queue are: ");
    int i = front;
    
    // Loop through the queue from front to rear
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {  // Break the loop when the rear is reached
            break;
        }
        i = (i + 1) % MAX;  // Move to the next index in a circular manner
    }
    printf("\n");
}

int main() {
    int choice = 1, x;
    
    // Menu-driven program
    while (choice != 0) {
        printf("\nMenu:\n");
        printf("Press 1: Insert an element\n");
        printf("Press 2: Delete an element\n");
        printf("Press 3: Display the elements\n");
        printf("Press 0: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
