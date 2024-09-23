#include<stdio.h>

void creatematrix(int mat[10][10], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int sparse(int mat[10][10], int sparse2[10][3], int row, int col) {
    int i, j, k = 1, count = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (mat[i][j] != 0) {
                sparse2[k][0] = i;  // Row index
                sparse2[k][1] = j;  // Column index
                sparse2[k][2] = mat[i][j];  // Non-zero value
                k++;
                count++;
            }
        }
    }
    sparse2[0][0] = row;  // Total rows
    sparse2[0][1] = col;  // Total columns
    sparse2[0][2] = count;  // Total non-zero elements
    
    return count;
}

void display(int sparse2[][3], int c) {
    int i, j;
    for (i = 0; i <= c; i++) {  // Display from 0 to c (inclusive)
        for (j = 0; j < 3; j++) {
            printf("%d ", sparse2[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[10][10] = {0}, sparse2[10][3], row, col, count;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of cols: ");
    scanf("%d", &col);
    creatematrix(mat, row, col);
    count = sparse(mat, sparse2, row, col);
    printf("The resultant sparse matrix is: \n");
    display(sparse2, count);
    return 0;
}

