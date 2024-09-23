// Converting dense to sparse and print it
#include <stdio.h>
void createMatrix(int a[30][30],int rw,int col){
    int i,j;
    for(i=0;i<rw;i++){
        for(j=0;j<col;j++)
            scanf("%d",&a[i][j]);
    }
}
void displaySparse(int mat[][3],int rw){
   int i,j;
   for(i=0;i<rw;i++){
        for(j=0;j<3;j++)
            printf("%d ",mat[i][j]);
        
        printf("\n");
   }
}
int Original2Sparse(int a[30][30],int rw,int col,int b[][3]){
    int i,j,k=1,c=0;
    for(i=0;i<rw;i++){
        for(j=0;j<col;j++){
            if(a[i][j]!=0){
                b[k][0]= i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
                c++;
            }
        }
    }
    b[0][0] = rw;
    b[0][1] = col;
    b[0][2] = c;

    return c;
}
int main(){
    int count,rw,col,a[30][30]={0}, b[30][3];
    printf("Enter the row and column of the matrix: ");
    scanf("%d %d",&rw,&col);
    
    printf("Enter the element of the matrix: ");
    createMatrix(a,rw,col);

    count = Original2Sparse(a,rw,col,b);

    printf("The matrix is: \n");
    displaySparse(b,count+1);
    return 0;
}
