#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void insert_begin(struct node **p,int data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*p;
	*p=newnode;
}
void insert_end(struct node **p,int data){
	struct node *endnode=(struct node*)malloc(sizeof(struct node));
	endnode->data=data;
	endnode->next=NULL;
	struct node *temp;
	if(*p==NULL){
		*p=endnode;
	}
	else{
		temp=*p;
		while(temp->next!=NULL){
			temp=temp->next;
			
		}
		temp->next=endnode;
	}
}
void insert_any(struct node **p,int data,int position){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	struct node *ptr;
	int i=1;
	newnode->data=data;
	if(*p==NULL||position==1){
		
		newnode->next=*p;
		*p=newnode;
	}
	
	else{
		ptr=*p;
		while(i<position-1&&ptr->next!=NULL){
			ptr=ptr->next;
			i++;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;
	}
	
}
int countlist(struct node *p){
	int count =0;
	struct node *temp;
	temp=p;
	if(p==NULL){
		printf("list is empty");
	}
	
	else{
		while(temp!=NULL){
			temp=temp->next;
			count++;
		}
		
	}
	return count;
	
}
int maxnode(struct node *p){
	int max;
	struct node *curr;
	max=p->data;
	curr=p;
	if(p==NULL){
		printf("list is empty");
		return 0;
	}
	else{
		while(curr!=NULL){
			if(curr->data>max){
				max=curr->data;
			}
			curr=curr->next;
		}
	}
	return max;
	
}
int sumnode(struct node *p){
	struct node *temp;
	temp=p;
	int sum =0;
	if(p==NULL){
		printf("list is empty");
		return 0;
	}
	else{
		while(temp!=NULL){
			sum=sum+temp->data;
			temp=temp->next;
		}
	}
	return sum;
}
void display(struct node *p){
	if(p==NULL){
		printf("the list is empty");
	}
	else{
		while(p!=NULL){
			printf("%d ->",p->data);
			p=p->next;
		}
		printf("NULL");
	}
}
void deletebegin(struct node **p){
	struct node *temp;
	temp=*p;
	if(*p==NULL){
		printf("the list is empty deletion not possible");
	}
	else{
		*p=temp->next;
		free(temp);
		
	}
}
//void deleteend(struct node **p){
//	struct node *temp;
//	temp=*p;
//	if(*p==NULL){
//		printf("the list is empty deletion not possible");
//	}
//	else{
//		while(temp->next->next!=NULL){
//			temp=temp->next;
//		}
//		temp->next=NULL;
//		free(temp->next);
//	}
//	
//}
void deleteend(struct node **p){
	struct node *temp,*prevnode;
	temp=*p;
	if(*p==NULL){
		printf("the list is empty deletion not possible");
	}
	else{
		while(temp->next!=NULL){
			prevnode=temp;
			temp=temp->next;
		}
		if(temp==*p){
			*p=NULL;
			free(temp);
		}
		else{
			prevnode->next=NULL;
			free(temp);
		}
	}
	
}
void deleteany(struct node **p,int position){
	struct node *temp,*nextnode;
	temp=*p;
	int i=1;
	while(i<position-1){
		temp=temp->next;
		i++;
	}
	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
	
}
int main(){
	struct node *head=NULL;
	int position =2;
	int count;
	insert_begin(&head,10);
	insert_begin(&head,17);
	insert_end(&head,72);
	insert_end(&head,2);
	insert_end(&head,10);
	display(head);
	printf("\n");
	count = countlist(head);
	printf("the number of node in the linked list is =%d",count);
	insert_any(&head,21,2);
	printf("\n");
	display(head);
	printf("\n");
	count = countlist(head);
	printf("the number of node in the linked list is =%d",count);
	int max =maxnode(head);
	printf("\n");
	printf("max value in the linked list is =%d",max);
	int sum=sumnode(head);
	printf("\n");
	printf("sum value of the linked list is =%d",sum);
	deletebegin(&head);
	printf("\n");
	display(head);
	deleteend(&head);
	printf("\n");
	display(head);
	deleteany(&head,5);
	printf("\n");
	display(head);
}
