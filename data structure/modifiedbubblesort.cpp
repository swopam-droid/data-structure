#include<stdio.h>
void createarray(int arr[20],int size){
	int i;
	printf("enter the elements:\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
}
void bubble_sort(int arr[20],int size){
	int i,flag=0,j,temp;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
			
		}
		if(flag==0){
			break;
			
		}
	}
}
void display(int arr[20],int size){
	int i;
	printf("sorted elemets:\n");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[20],n;
	printf("enter the number of elements: ");
	scanf("%d",&n);
	createarray(arr,n);
	bubble_sort(arr,n);
	display(arr,n);
}
