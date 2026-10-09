#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert a node at the end
void insert() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted successfully.\n");
}

// Delete the first node
void deleteNode() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);

    printf("Node deleted successfully.\n");
}

// Display the list in forward direction
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Display the list in reverse direction
void reverseDisplay() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Reverse List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Reverse Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                reverseDisplay();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:1
        
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}