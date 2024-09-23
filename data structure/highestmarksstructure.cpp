#include <stdio.h>
#include <string.h>

typedef struct student {
    int roll;
    int marks;
    char name[30];
} stu;

int main() {
    stu s[30];
    int n, max, i, j;
    
    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        // Input roll number
        printf("Enter roll: ");
        scanf("%d", &s[i].roll);
        
        // Clear the input buffer after reading roll number
        getchar();  // This will consume the newline character left by scanf
        
        // Input student name
        printf("Enter name: ");
        fgets(s[i].name, 30, stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';  // Remove newline character
        
        // Input total marks
        printf("Enter total marks: ");
        scanf("%d", &s[i].marks);
    }
    
    // Find the student with the highest marks
    max = s[0].marks;
    j = 0;
    
    for(i = 1; i < n; i++) {
        if(s[i].marks > max) {
            max = s[i].marks;
            j = i;
        }
    }
    
    // Print the student with the highest marks
    printf("Highest marks: %d\n", max);
    printf("Name of the student: %s\n", s[j].name);
    
    return 0;
}
