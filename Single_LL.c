#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *head = NULL; // Global head pointer

// Function to create a new node with given data
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Insert a node at the beginning of the list
void insertAtBeginning(int data) {
    Node *newNode = createNode(data);
    newNode->link = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

// Insert a node at the end of the list
void insertAtEnd(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->link)
            temp = temp->link;
        temp->link = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}

// Insert a node at a given position (1-based index)
void insertAtPosition(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }
    newNode->link = temp->link;
    temp->link = newNode;
    printf("Inserted %d at position %d.\n", data, pos);
}

// Delete a node from the beginning of the list
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    head = head->link;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete a node from the end of the list
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->link == NULL) { // Only one node
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head, *prev = NULL;
    while (temp->link) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

// Delete a node from a given position (1-based index)
void deleteAtPosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("List is empty or invalid position.\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    Node *temp = head, *prev = NULL;
    int i;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->link = temp->link;
    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}

// Print the list from beginning to end
void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Recursively print the list from end to beginning
void printListReverse(Node *node) {
    if (node == NULL)
        return;
    printListReverse(node->link);
    printf("%d ", node->data);
}

// Search for a node with given data
void searchData(int data) {
    Node *temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == data) {
            printf("Data %d found at position %d.\n", data, pos);
            return;
        }
        temp = temp->link;
        pos++;
    }
    printf("Data %d not found in the list.\n", data);
}

// Update the data of a node at a given position
void updateNode(int pos, int newData) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    Node *temp = head;
    int i;
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    temp->data = newData;
    printf("Node at position %d updated to %d.\n", pos, newData);
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Print list (forward)\n");
        printf("8. Print list (reverse)\n");
        printf("9. Search data\n");
        printf("10. Update node data\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter position and data (position data): ");
                scanf("%d %d", &pos, &data);
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                printList();
                break;
            case 8:
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("List in reverse: ");
                    printListReverse(head);
                    printf("\n");
                }
                break;
            case 9:
                printf("Enter data to search: ");
                scanf("%d", &data);
                searchData(data);
                break;
            case 10:
                printf("Enter position and new data (position newData): ");
                scanf("%d %d", &pos, &data);
                updateNode(pos, data);
                break;
            case 11:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
