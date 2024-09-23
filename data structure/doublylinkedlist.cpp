#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void createnode(struct node **head) {
    struct node *newnode, *temp;
    int choice = 1;

    while(choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if (*head == NULL) {  // If list is empty, initialize head
            *head = newnode;
            temp = *head;  // Set temp to the new head
        } else {
            temp->next = newnode;  // Link the new node to the current last node
            newnode->prev = temp;  // Link back to the previous node
            temp = newnode;  // Update temp to the new last node
        }

        printf("Do you want to continue? (1 to continue, 0 to exit): ");
        scanf("%d", &choice);
    }
}

void display(struct node *head) {
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    createnode(&head);
    display(head);
    return 0;
}

