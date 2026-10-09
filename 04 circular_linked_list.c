#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
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

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    printf("Node inserted successfully.\n");
}

// Delete the first node
void deleteNode() {
    struct node *temp, *last;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
        free(temp);
    }

    printf("Node deleted successfully.\n");
}

// Display the list
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}