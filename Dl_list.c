#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the doubly linked list
struct node {
    struct node* prev;  // Pointer to the previous node
    int data;           // Data stored in the node
    struct node* next;  // Pointer to the next node
};

// Global head pointer for the list
struct node* head = NULL;

int main() {
    char user_active = 'Y';
    int user_choice;
    int data, position;

    // Main loop: Continue until the user chooses to exit
    while (user_active == 'Y' || user_active == 'y') {
        // Display the menu options
        printf("\n\n------ Doubly Linked List -------\n");
        printf("\n1. Insert a node at the beginning");
        printf("\n2. Insert a node at the end");
        printf("\n3. Insert a node at the given position");
        printf("\n\n4. Delete a node from the beginning");
        printf("\n5. Delete a node from the end");
        printf("\n6. Delete a node from the given position");
        printf("\n\n7. Print list from the beginning");
        printf("\n8. Print list from the end");
        printf("\n9. Search a node data");
        printf("\n10. Update a node data");
        printf("\n11. Sort the list");
        printf("\n12. Exit");
        printf("\n\n------------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);
        printf("\n------------------------------\n");

        switch (user_choice) {
            case 1:
                // Inserting a node at the beginning
                printf("\nEnter Data: ");
                scanf("%d", &data);
                {
                    // Allocate memory for a new node
                    struct node* new_node = (struct node*)malloc(sizeof(struct node));
                    if (new_node == NULL) {
                        printf("\nMemory was not allocated!\n");
                        break;
                    }
                    new_node->prev = NULL;
                    new_node->data = data;
                    new_node->next = NULL;

                    // If list is empty, new node becomes the head
                    if (head == NULL) {
                        head = new_node;
                    } else {
                        head->prev = new_node;
                        new_node->next = head;
                        head = new_node;
                    }
                    printf("\n* Node with data %d was inserted \n", data);
                }
                break;

            case 2:
                // Inserting a node at the end
                printf("\nEnter Data: ");
                scanf("%d", &data);
                {
                    struct node* new_node = (struct node*)malloc(sizeof(struct node));
                    if (new_node == NULL) {
                        printf("\nMemory was not allocated!\n");
                        break;
                    }
                    new_node->prev = NULL;
                    new_node->data = data;
                    new_node->next = NULL;

                    // If list is empty, new node becomes the head
                    if (head == NULL) {
                        head = new_node;
                    } else {
                        // Traverse to the end of the list
                        struct node* temp = head;
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        temp->next = new_node;
                        new_node->prev = temp;
                    }
                    printf("\n* Node with data %d was inserted \n", data);
                }
                break;

            case 3:
                // Inserting a node at a given position
                printf("\nEnter Data: ");
                scanf("%d", &data);
                printf("\nEnter Position: ");
                scanf("%d", &position);
                {
                    struct node* new_node = (struct node*)malloc(sizeof(struct node));
                    if (new_node == NULL) {
                        printf("\nMemory was not allocated!\n");
                        break;
                    }
                    
                    // Calculate the current size of the list
                    struct node* temp = head;
                    int size = 0;
                    while (temp != NULL) {
                        size++;
                        temp = temp->next;
                    }
                    
                    // Check if the given position is valid
                    if (position < 1 || position > size + 1) {
                        printf("\nInvalid position!\n");
                        break;
                    }
                    
                    new_node->prev = NULL;
                    new_node->data = data;
                    new_node->next = NULL;
                    
                    // Insert at the beginning if position is 1
                    if (position == 1) {
                        new_node->next = head;
                        if (head != NULL) {
                            head->prev = new_node;
                        }
                        head = new_node;
                    } else {
                        // Traverse to the node just before the desired position
                        temp = head;
                        for (int i = 1; i < position - 1; i++) {
                            temp = temp->next;
                        }
                        new_node->next = temp->next;
                        if (temp->next != NULL) {
                            temp->next->prev = new_node;
                        }
                        temp->next = new_node;
                        new_node->prev = temp;
                    }
                    printf("\n* Node with data %d was inserted at position %d\n", data, position);
                }
                break;

            case 4:
                // Deleting a node from the beginning
                if (head == NULL) {
                    printf("\nList is Empty!\n");
                    break;
                }
                {
                    struct node* temp = head;
                    head = head->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                    free(temp);
                    printf("\n* Node was deleted from beginning \n");
                }
                break;

            case 5:
                // Deleting a node from the end
                if (head == NULL) {
                    printf("\nList is Empty!\n");
                    break;
                }
                {
                    struct node* temp = head;
                    // Traverse to the last node
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    if (temp->prev == NULL) {
                        // Only one node exists
                        head = NULL;
                    } else {
                        temp->prev->next = NULL;
                    }
                    free(temp);
                    printf("\n* Node was deleted from end \n");
                }
                break;

            case 6:
                // Deleting a node from a given position
                printf("\nEnter Position: ");
                scanf("%d", &position);
                if (head == NULL) {
                    printf("\nList is Empty!\n");
                    break;
                }
                {
                    struct node* temp = head;
                    int size = 0;
                    // Calculate the size of the list
                    while (temp != NULL) {
                        size++;
                        temp = temp->next;
                    }
                    // Validate the given position
                    if (position < 1 || position > size) {
                        printf("\nInvalid position!\n");
                        break;
                    }
                    if (position == 1) {
                        // Deleting the first node
                        temp = head;
                        head = head->next;
                        if (head != NULL) {
                            head->prev = NULL;
                        }
                        free(temp);
                    } else {
                        // Traverse to the node at the given position
                        temp = head;
                        for (int i = 1; i < position; i++) {
                            temp = temp->next;
                        }
                        if (temp->prev != NULL) {
                            temp->prev->next = temp->next;
                        }
                        if (temp->next != NULL) {
                            temp->next->prev = temp->prev;
                        }
                        free(temp);
                    }
                    printf("\n* Node was deleted from position %d \n", position);
                }
                break;

            case 7:
                // Print the list from beginning to end
                if (head == NULL) {
                    printf("\nList is Empty!\n");
                    break;
                }
                {
                    struct node* temp = head;
                    printf("\nList (from beginning): ");
                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("NULL\n");
                }
                break;

            case 8:
                // Print the list from end to beginning
                if (head == NULL) {
                    printf("\nList is Empty!\n");
                    break;
                }
                {
                    struct node* temp = head;
                    // Traverse to the last node
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    printf("\nList (from end): ");
                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->prev;
                    }
                    printf("NULL\n");
                }
                break;

            case 9:
                // Search for a node with the specified data
                printf("\nEnter Data to search: ");
                scanf("%d", &data);
                {
                    struct node* temp = head;
                    int pos = 1;
                    int found = 0;
                    while (temp != NULL) {
                        if (temp->data == data) {
                            printf("\nNode found at position %d\n", pos);
                            found = 1;
                            break;
                        }
                        temp = temp->next;
                        pos++;
                    }
                    if (!found) {
                        printf("\nNode with data %d not found\n", data);
                    }
                }
                break;

            case 10:
                // Update the data of a node at a given position
                printf("\nEnter new Data: ");
                scanf("%d", &data);
                printf("\nEnter Position to update: ");
                scanf("%d", &position);
                {
                    struct node* temp = head;
                    int size = 0;
                    // Determine the size of the list
                    while (temp != NULL) {
                        size++;
                        temp = temp->next;
                    }
                    // Check if the position is valid
                    if (position < 1 || position > size) {
                        printf("\nInvalid position!\n");
                        break;
                    }
                    // Traverse to the desired node
                    temp = head;
                    for (int i = 1; i < position; i++) {
                        temp = temp->next;
                    }
                    temp->data = data;
                    printf("\nNode data at position %d updated to %d\n", position, data);
                }
                break;

            case 11:
                // Sort the list using an insertion sort technique
                if (head == NULL) {
                    printf("\nList is Empty!\n");
                    break;
                }
                {
                    struct node* temp1 = head;
                    struct node* temp2;
                    int key;
                    // Iterate over the list, sorting as you go
                    while (temp1 != NULL) {
                        key = temp1->data;
                        temp2 = temp1;
                        // Shift nodes until the correct position is found
                        while (temp2->prev != NULL && temp2->prev->data > key) {
                            temp2->data = temp2->prev->data;
                            temp2 = temp2->prev;
                        }
                        temp2->data = key;
                        temp1 = temp1->next;
                    }
                    printf("\nList sorted successfully!\n");
                }
                break;

            case 12:
                // Exit the program
                printf("\nProgram terminated\n");
                return 0;

            default:
                printf("\nInvalid Choice\n");
        }
        
        // Ask the user if they want to continue
        printf("\nDo you want to continue? (Y/N): ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }
    return 0;
}
