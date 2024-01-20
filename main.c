#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Node *next;
    int data;
} Node;

Node *head = NULL;

// add a node to the list
void addNode(int data)
{
    Node *new = malloc(sizeof(Node));
    if (new == NULL) {
        return;
    }
    new->data = data;

    // if it is currently empty list
    if (head == NULL)
    {
        
        head = new;
        new->next = NULL;

    } else {

        new->next = head;
        head = new;
    
    }
}

// remove a node from linked list
int removeNodeByData(int data)
{
    Node *current = head;
    Node *prev = head;

    while (current != NULL) {
        if (current->data == data) {
            if (current == head)
            {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            current = NULL;

            return 1;
        }
        prev = current;
        current = current->next;
    }

    return 0;
}

// remove a node from linked list
void removeNodeByIndex(int index, int lengthLinkedList)
{
    Node *current = head;
    Node *prev = head;
    int counter = 0;
    
    while (current != NULL) {
        counter++;
        if (counter == index) {
            if (current == head)
            {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            current = NULL;
        }
        prev = current;
        current = current->next;
    }
}

//insert data into a specific position in linked list
void insertNode(int index, int data)
{
    Node *current = head;

    int counter = 0;
    while (current != NULL)
    {
        counter++;
        if (counter == index)
        {
            Node *new = malloc(sizeof(Node));
            if (new == NULL)
            {
                return;
            }
            
            new->data = data;
            new->next = current->next;
            current->next = new;
            return;
        }

        current = current->next;
    }
}

// create new linked list
void createNewLinkedList(int total)
{
    if (total < 1)
    {
        return;
    }

    int count = total;
    Node *prev = NULL;

    // Create Linked List from tail
    while (count != 0)
    {
        
        Node *new = malloc(sizeof(Node));
        if (new == NULL)
        {
            return;
        }

        new->data = count;
        if (count == total)
        {
            new->next = NULL;
        } else {
            new->next = prev;
        }
        prev = new;
        count--;
    }
    
    head = prev;

    // Create Linked List from head
    // while (count != 0)
    // {
        
    //     Node *new = malloc(sizeof(Node));
    //     if (new == NULL)
    //     {
    //         return;
    //     }

    //     if (count == total)
    //     {
    //         head = new;
    //     }

    //     new->data = count;
    //     new->next = NULL;
    //     if (prev != NULL)
    //     {
    //         prev->next = new;
    //     }

    //     prev = new;
    //     count--;
    // }
}

// reverse whole linked list
void reverseLinkedList()
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// get total of items in the linked list
int getLinkedListLength()
{
    Node *current = head;
    int counter = 0;
    
    while (current != NULL) {
        counter++;
        current = current->next;
    }

    return counter;
}


// print linked list
void printLinkedList()
{
    if (head == NULL) {
        printf("\nNothing to be printed.\n");
        return;
    }

    Node *current = head;
    
    printf("\n--------------------------\n");
    while (current != NULL) {
        if (current->next == NULL)
        {
            printf("%d", current->data);
        } else {
            printf("%d -> ", current->data);
        }
        current = current->next;
    }
    printf("\n--------------------------\n");
}

// delete whole linked list
void deleteLinkedList()
{
    Node *current = head;

    while (current != NULL) 
    {
        current = current->next;
        free(head);
        head = current;

    }
}

void printMenu()
{
    int option;
    int userData;
    int counter;

    while (option != 9) {
        printf("\nLinked List Operation: \n");
        printf("1. Add to Linked List \n");
        printf("2. Delete Linked List by Data \n");
        printf("3. Delete Linked List by Index \n");
        printf("4. Insert Linked List \n");
        printf("5. Create new Linked List \n");
        printf("6. Reverse Linked List \n");
        printf("7. Print Linked List \n");
        printf("8. Delete Linked List \n");
        printf("9. Exit \n");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\nEnter a number to be added: \n");
                scanf("%d", &userData);
                addNode(userData);
                break;
            case 2:
                if (head == NULL) {
                    printf("\nNothing to be deleted.\n");
                    break;
                }
                printf("\nEnter a number to be deleted: \n");
                scanf("%d", &userData);
                int success = removeNodeByData(userData);
                if (!success) {
                    printf("\nData not found.\n");
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("\nNothing to be deleted.\n");
                    break;
                }

                counter = getLinkedListLength();
                printf("\nThe node's length is %d, only enter number lower than the length and higer than zero\n", counter);
                scanf("%d", &userData);
                if (userData > 0 && userData <= counter) {                    
                    removeNodeByIndex(userData, counter);
                } else {
                    printf("\n%d is not within the range of node's length\n", userData);
                }
                break;
            case 4:
                counter = getLinkedListLength();
                printf("\nEnter a position :");
                printf("\n*The node's length is %d, only enter number lower than the length and higer than zero\n", counter);
                scanf("%d", &userData);
                if (userData > 0 && userData <= counter) {
                    int data;
                    printf("\nEnter data to be inserted:\n", counter);
                    scanf("%d", &data);
                    insertNode(userData, data);
                } else {
                    printf("\n%d is not within the range of node's length\n", userData);
                }
                break;
            case 5:
                if (head != NULL)
                {
                    char deleteConfirmation[1];
                    printf("\nThere is an existing linked list detected, to proceed it needs to be deleted\n");
                    printf("Confirm Delete ? (Enter 'y'/'Y' to delete) ");
                    scanf("%s", &deleteConfirmation);
                    if (deleteConfirmation[0] != 'Y' & deleteConfirmation[0] != 'y')
                    {
                        break;
                    }
                }
                deleteLinkedList();
                printf("\nEnter total of items to add in the Linked List (Content will be automatically created)\n");
                scanf("%d", &userData);
                createNewLinkedList(userData);
                break;
            case 6:
                reverseLinkedList();
                break;
            case 7:
                printLinkedList();
                break;
            case 8:
                deleteLinkedList();
                printLinkedList();
                break;
            default:
            break;
        }
    }   
}

int main() 
{
    printMenu();
    deleteLinkedList();
    return 0;
}