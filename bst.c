/* BINARY SEARCH TREE AND OPERATIONS */


#include <stdio.h>
#include <stdlib.h>

//Node Structure
struct node
{
    int data;
    struct node *ptrLeft;
    struct node *ptrRight;
};
typedef struct node DLLNode;

DLLNode *root = NULL; // Root Node
DLLNode *new_node;

// Function Prototyping
void insert(int);
DLLNode *delete (DLLNode *, int);
int search(int);
void inorder(DLLNode *);
void postorder(DLLNode *);
void preorder(DLLNode *);
DLLNode *smallest_node(DLLNode *);
DLLNode *largest_node(DLLNode *);
int get_data();

int main()
{
    int userChoice;
    int userActive = 'Y';
    int data;
    DLLNode* result = NULL;

    while (userActive == 'Y' || userActive == 'y')
    {
        printf("----------- Binary Search Tree ------");
        printf("\n1. Insert \n2. Delete \n3. Search\n4. Get Larger Node Data\n5. Get Smaller Node Data\n6. In-order Traversal\n7. Pre-order Traversal \n8. Post-order Traversal");
        printf("\n---------------------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d",&userChoice);
    
        switch(userChoice)
        {
            case 1:
                printf("Enter Data: ");
                scanf("%d",&data);
                insert(data);
                break;

            case 2:
                printf("Enter Data: ");
                scanf("%d",&data);
                root = delete(root, data);
                break;

            case 3:
                printf("Enter Data: ");
                scanf("%d",&data);
                if (search(data) == 1)
                {
                    printf("Data Found!\n");
                }
                else
                {
                    printf("Data Not Found!\n");
                }
                break;

            case 4:
                result = largest_node(root);
                if (result != NULL)
                {
                    printf("\nLargest Data: %d\n", result->data);
                }
                break;

            case 5:
                result = smallest_node(root);
                if (result != NULL)
                {
                    printf("\nSmallest Data: %d\n", result->data);
                }
                break;

            case 6:
                inorder(root);
                break;

            case 7:
                preorder(root);
                break;

            case 8:
                postorder(root);
                break;

            default:
                printf("\n\tInvalid Choice\n");
                break;
        }

        printf("--> TO CONTINUE, ENTER 'Y' else 'N' :");
        fflush(stdin);
        scanf(" %c", &userActive);
    }

    return 0;
}

// Data Insertion in BST
void insert(int data)
{
     new_node = (DLLNode*)malloc(sizeof(DLLNode));
     new_node->data = data;
     new_node->ptrLeft = NULL;
     new_node->ptrRight = NULL;

        if (root == NULL)
        {
            root = new_node;
            printf("Node Inserted in Tree\n", data);
            return;
        }

        DLLNode *temp = root;
        DLLNode *prev = NULL;

        // Traverse through the BST to get the correct position for insertion
        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->ptrRight;
            }
            else
            {
                temp = temp->ptrLeft;
            }
        }

        // Insert the new node in the location found
        
        if (data > prev->data)
        {
            prev->ptrRight = new_node;
        }
        else
        {
            prev->ptrLeft = new_node;
        }

        printf("Node Inserted in Tree\n", data);
    
}

// Deletion of a Node from BST
DLLNode *delete (DLLNode *root, int key)
{
    if (root == NULL)
        return root;
    
    // Step 1: Search for the node to delete
    if (key < root->data)
    {
        root->ptrLeft = delete (root->ptrLeft, key);
    }
    else if (key > root->data)
    {
        root->ptrRight = delete (root->ptrRight, key);
    }
    else
    {
	// Step 2: Node with 0 or 1 child
        if (root->ptrLeft == NULL)
        {
            DLLNode *temp = root->ptrRight;
            free(root);
            return temp;
        }
        else if (root->ptrRight == NULL)
        {
            DLLNode *temp = root->ptrLeft;
            free(root);
            return temp;
        }

        // Step 3: Node with two children
        DLLNode *temp = smallest_node(root->ptrRight); // Find inorder successor - the smallest value in the right sub tree
        root->data = temp->data; // Copy successor's value
        root->ptrRight = delete (root->ptrRight, temp->data); // After copying the successor's value, delete it
    }
    return root;

}

// Searches the Data in BST
int search(int key)
{
    DLLNode *temp = root;

    while (temp != NULL)
    {
        if (key == temp->data)
        {
            return 1;
        }
        else if (key > temp->data)
        {
            temp = temp->ptrRight;
        }
        else
        {
            temp = temp->ptrLeft;
        }
    }
    return 0;
}

// Finds the Smallest Data in BST
DLLNode *smallest_node(DLLNode *root)
{
    DLLNode *temp = root;
    while (temp != NULL && temp->ptrLeft != NULL)
   {
        temp = temp->ptrLeft;
    }
    return temp;
}

// Finds the Largest Data in BST
DLLNode *largest_node(DLLNode *root)
{
    DLLNode *temp = root;
    while (temp != NULL && temp->ptrRight != NULL)
    {
        temp = temp->ptrRight;
    }
    return temp;
}

// Inorder Traversal of the BST
void inorder(DLLNode *root)
{
    //Condition to avoid infinite recursion
    if (root == NULL)
    {
        return;
    }
    inorder(root->ptrLeft);
    printf("%d ",  root->data);
    inorder(root->ptrRight);
}

// Preorder Traversal of the BST
void preorder(DLLNode *root)
{
    //Condition to avoid infinite recursion
    if (root == NULL) 
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->ptrLeft);
    preorder(root->ptrRight);
}

// Postorder Travsersal of the BST
void postorder(DLLNode *root)
{
    //Condition to avoid infinite recursion
    if (root == NULL)
    {
        return;
    }
    postorder(root->ptrLeft);
    postorder(root->ptrRight);
    printf("%d ", root->data);
}



