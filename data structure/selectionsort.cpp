#include<stdio.h>
void createarray(int arr[20],int size){
	int i;
	printf("enter the elements:\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
}
void selection_sort(int arr[20],int size){
	int i,j,temp,min;
	for(i=0;i<size-1;i++){
		min =i;
		for(j=i+1;j<size;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
		
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
	selection_sort(arr,n);
	display(arr,n);
	return(0);
}
