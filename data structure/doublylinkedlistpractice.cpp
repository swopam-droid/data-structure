#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
void createnode(struct node **head,struct node **tail){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data: \n");
	scanf("%d",&newnode->data);
	newnode->prev=0;
	newnode->next=0;
	if(*head==0){
		*head=*tail=newnode;
	}
	else{
		(*tail)->next=newnode;
		newnode->prev=*tail;
		*tail=newnode;
	}
}

void display(struct node *head){
	while(head!=0){
		printf("%d ->",head->data);
		head=head->next;
	}
	printf("NULL");
}

void insertbegin(struct node **head){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data: \n");
	scanf("%d",&newnode->data);
	newnode->prev=0;
	newnode->next=0;
	if(*head==0){
		*head=newnode;
	}
	else{
		(*head)->prev=newnode;
		newnode->next=*head;
		*head=newnode;
		
	}
}
void insertend(struct node **head,struct node **tail){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data: \n");
	scanf("%d",&newnode->data);
	newnode->prev=0;
	newnode->next=0;
	if(*head==0){
		*head=newnode;
	}
	else{
		(*tail)->next=newnode;
		newnode->prev=*tail;
		*tail=newnode;
	}
}
void insertatposition(struct node **head){
	struct node *newnode,*temp;
	temp=*head;
	int i=1,pos;
	printf("enter position: \n");
	scanf("%d",&pos);
	if(pos==1){
		(*head)->prev=newnode;
		newnode->next=*head;
		*head=newnode;
	}
	else{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("enter data: \n");
		scanf("%d",&newnode->data);
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
	
		
	}

}
int main(){
	struct node *head=0,*tail;
	printf("create node: \n");
	createnode(&head,&tail);
	createnode(&head,&tail);
	printf("\ninsert begin node: \n");
	insertbegin(&head);
	printf("\ninsert end node: \n");
	insertend(&head,&tail);
	printf("\ninsert position node: \n");
	insertatposition(&head);
	display(head);
	return(0);
}
