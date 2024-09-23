#include<stdio.h>
#include<ctype.h>
void createpoly(int arr[],int size){
	int c,p,count=0;
	char ch = 'Y';
	while(toupper(ch)=='Y'&&(count<size)){
	printf("enter the exponent: ");
	scanf("%d",&p);
	printf("enter the coefficient: ");
	scanf("%d",&c);
	if(p>=0&&p<size){
	
		arr[p]=c;
		count++;
	}
	
	else{
		printf("exponet out of range try again\n");
	}
	printf("continue(Y/N)?\n");
	while(getchar()!='\n')
	scanf("%c",&ch);
}
}
void addpoly(int poly[],int poly2[],int poly3[],int size){
	int i;
	for(i=0;i<size;i++){
		poly3[i]=poly[i] + poly2[i];
	}
}
void display(int arr[],int size){
	int i;
	for(i=size-1;i>=0;i--){
		if(arr[i]!=0){
		
		printf("%dx^%d + ",arr[i],i);
	}
	}
	printf("\b\b ");
}

int main(){
	int poly[20]={0},poly2[20]={0},poly3[20]={0},size,n;
	printf("enter the highest power: ");
	scanf("%d",&n);
	size=n+1;
	printf("enter the first polynomial:\n");
	createpoly(poly,size);
	printf("enter the second polynomial:\n");
	createpoly(poly2,size);
	addpoly(poly,poly2,poly3,size);
	printf("The first polynomial is: ");
	display(poly,size);
	printf("\nThe second polynomial is: ");
	display(poly2,size);
	printf("\nThe resultant polynomial is: ");
	display(poly3,size);
	return(0);
	
}
