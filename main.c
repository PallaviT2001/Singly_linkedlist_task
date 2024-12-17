#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int count = 0;

struct node* creationandinsertion(struct node* head, int* count) {
    struct node* newnode, *temp = NULL;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (!newnode) {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        (*count)++;
        printf("Press 1 to continue and 0 to exit: ");
        scanf("%d", &choice);
    }
    return head;
}

void display(struct node* head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* insertatbeginning(struct node* head, int* count) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter the data to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    (*count)++;
    return head;
}

struct node* insertatend(struct node* head, int* count) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;

    if (!newnode) {
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter the data to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    (*count)++;
    return head;
}

struct node* insertatposition(struct node* head, int* count) {
    struct node *newnode, *temp = head;
    int position, i;

    printf("Enter position to insert: ");
    scanf("%d", &position);

    if (position < 0 || position > (*count)) {
        printf("Invalid position\n");
        return head;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (position == 0) {
        newnode->next = head;
        head = newnode;
    } else {
        for (i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newnode->next = temp->next;
            temp->next = newnode;
        } else {
            printf("Position not found\n");
            free(newnode);
        }
    }
    (*count)++;
    return head;
}

struct node* insertAfterSpecificPosition(struct node* head, int* count) {
    struct node *newnode, *temp = head;
    int position, i;

    printf("Enter position to insert after: ");
    scanf("%d", &position);

    if (position < 0) {
        printf("Invalid position\n");
        return head;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    for (i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newnode->next = temp->next;
        temp->next = newnode;
        (*count)++;
    } else {
        printf("Position not found\n");
        free(newnode);
    }
    return head;
}

int main() {
    int choice = 1, option;

    while (choice) {
        printf("\n******* Select an operation ********\n");
        printf("1. Create a linked list\n");
        printf("2. Display list\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert at a specific position\n");
        printf("6. Insert after a specific position\n");
        printf("7. Display count of nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            head = creationandinsertion(head, &count);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insertatbeginning(head, &count);
            break;
        case 4:
            head = insertatend(head, &count);
            break;
        case 5:
            head = insertatposition(head, &count);
            break;
        case 6:
            head = insertAfterSpecificPosition(head, &count);
            break;
        case 7:
            printf("The current count of nodes is: %d", count);
            break;
        case 8:
            printf("Exiting\n");
            exit(0);
        default:
            printf("Invalid choice, try again\n");
        }
    }
    return 0;
}
