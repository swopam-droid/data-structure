#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void createnode(struct node **head) {
    struct node *newnode, *temp;
    int choice = 1;

    while(choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (*head == NULL) {  // If list is empty, initialize head
            *head = newnode;
            temp = *head;  // Set temp to the new head
        } else {
            temp->next = newnode;  // Link the new node to the current last node
            temp = newnode;  // Update temp to the new last node
        }
        temp->next=*head;

        printf("Do you want to continue? (1 to continue, 0 to exit): ");
        scanf("%d", &choice);
    }
	printf("this indicates the linked list is circuler linked list %d\n",temp->next->data);
}

void display(struct node *head) {
    struct node *temp = head;
    while(temp->next!=head ) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf(" -> HEAD\n");
}

int main() {
    struct node *head = NULL;
    createnode(&head);
    display(head);
    return 0;
}

