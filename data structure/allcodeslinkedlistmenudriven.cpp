#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}node;
void insertBegin(node **p,int data){
    node newnode = (node)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *p;
    *p = newnode;
}
void insertEnd(node **head,int data){
    node *ptr,*temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    if(*head==NULL)
        *head = temp;
    else{
        ptr = *head;
        while(ptr->link!=NULL){
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}
void insert_nth(node **head,int data,int posn){
    node *temp, *ptr;
    int i = 1;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    if(*head==NULL||posn==1){
        temp->link = *head;
        *head = temp;
    } 
    else{
        ptr = *head;
        while(i<=posn-2 && ptr->link!=NULL){
            ptr = ptr->link;
            i++;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}
int displayList(node *head){
    if(head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    else{
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->link;
        }
        printf("NULL\n");
    }
}
int countList(node *head){
    int count = 0;
    if(head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    node *ptr = NULL;
    ptr = head;
    while(ptr!=NULL){
        count++;
        ptr = ptr->link;
    }
    printf("The total number of nodes is %d\n",count);
}
int maxNode(node *head){
    node *ptr,*temp;
    ptr = NULL;
    int max;
    ptr = head;
    if(head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    else{
        ptr = head;
        max = ptr->data;
        ptr = ptr->link;
        while(ptr!=NULL){
            if(ptr->data>max){
                max = ptr->data;
                temp = ptr;
            }
            ptr = ptr->link;
        }
    }
    printf("Maximum data of list is %d and address of the maximum data of list is %d\n",max,temp);
}
int sumNode(node *head){
    node *ptr;
    int sum=0;
    if(head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    else{
        ptr = head;
        while(ptr!=NULL){
            sum += ptr->data;
            ptr = ptr->link;
        }
        printf("Summation of all data: %d\n",sum);
    }
}
int sortingList(node **head){
    int temp;
    node *current, *next;
    current = *head;
    if(head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    else{
        while(current!=NULL){
            next = current->link;
            while(next!=NULL){
                if(current->data>next->data){
                    temp = current->data;
                    current->data = next->data;
                    next->data = temp;
                }
                next = next->link;
            }
            current = current->link;
        }
    }
}
void deleteBegin(node **head){
    node *ptr;
    if(*head==NULL)
        puts("NULL node.Deletion is not possible.\n");
    else{
        ptr = *head;
        *head = ptr->link;
        free(ptr);
        printf("Successfully deleted the first element of the node.\n");
    }
}
void deleteEnd(node **head) {
    node *ptr, *prev;
    if (*head == NULL) {
        puts("List is empty. Deletion is not possible.\n");
        return;
    }
    ptr = *head;
    if (ptr->link == NULL) {
        free(ptr);
        *head = NULL;
        printf("Successfully deleted the only element of the list.\n");
        return;
    }
    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }

    free(ptr->link); 
    ptr->link = NULL;

    printf("Successfully deleted the last element of the list.\n");
}
void deleteAny(node **head,int data){
    node *prev,*cur,*next;
    cur = *head;
    if(*head==NULL)
        puts("NULL node. Deletion is not possible.\n");
    else{
        if(cur->data==data){
            *head = cur->link;
            free(cur);
        }
        else{
            prev = cur;
            cur = cur->link;
            while(cur!=NULL){
                if(cur->data==data)
                    break;
                prev = cur;
                cur = cur->link;
            }
            if(cur==NULL)
                puts("Data is not found in the list.");
            else{
                prev->link = cur->link;
                free(cur);
            }
        }
    }
}
void display_rev(node *head){
    node *ptr;
    if(head!=NULL){
        ptr = head;
        display_rev(head->link);
        printf("%d ",ptr->data);
    }
}
void physically_rev(node **head){
    node *prev = NULL, *cur = *head, *next = NULL;
    while(cur!=NULL){
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
    printf("Reversing is completed in physically.\n");
}
int main(){
    node *head = NULL;
    int ch,data,posn;
    printf("|MAIN MENU|\n");
    printf("---------------------------------------------------\n");
    printf("1. Insert element at the beginning\n");
    printf("2. Insert element at the ending\n");
    printf("3. Insert element at the n-th position\n");
    printf("4. Print the list\n");
    printf("5. Count the number of node\n");
    printf("6. Find the maximum data\n");
    printf("7. Sum of the data in the list\n");
    printf("8. Sorting the linked list.\n");
    printf("9. Delete element at the beginning\n");
    printf("10. Delete element at the ending.\n");
    printf("11. Delete element from any position.\n");
    printf("12. Display the list in reverse order using recursion.\n");
    printf("13. Reverse display the linked list\n");
    printf("14. Exit\n");
    printf("---------------------------------------------------\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                printf("Enter the element to insert at the end: ");
                scanf("%d",&data);
                insertEnd(&head,data);
                break;
            case 3:
                printf("Which position you want to insert: ");
                scanf("%d",&posn);
                if(posn<1){
                    printf("Invalid position. Position must be >= 1.\n");
                    break;
                }
                printf("Enter the element to insert at %d position: ",posn);
                scanf("%d",&data);
                insert_nth(&head,data,posn);
                break;
            case 4:
                printf("List: ");
                displayList(head);
                break;
            case 5:
                countList(head);
                break;
            case 6:
                maxNode(head);
                break;
            case 7:
                sumNode(head);
                break;
            case 8:
                sortingList(&head);
                printf("Sorting list: ");
                displayList(head);
                break;
            case 9:
                deleteBegin(&head);
                break;
            case 10:
                deleteEnd(&head);
                break;
            case 11:
                printf("Enter the value to delete: ");
                scanf("%d",&data);
                deleteAny(&head,data);
                break;
            case 12:
                display_rev(head);
                printf("\n");
                break;
            case 13:
                physically_rev(&head);
                break;
            case 14:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid operation. Please try again..\n");
        }
    }
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    return 0;
}
