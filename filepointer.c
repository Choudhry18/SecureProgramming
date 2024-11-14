#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name [100];
    int age;
    float score;
}Student;

float averageScores (Student * ptr, int num) {
    int sum = 0;
    if(num <= 0){
        printf("Error; cannot take average of 0 students");
        return 0;
    } else {
    for( int i =0; i < num; i++){
        sum += ptr->score;
        ptr++;
       
    }
    return sum/(float) num;
    }
}

int main()
{
    
    FILE *file = fopen("untitled.txt", "r");
    if (file == NULL) {
        printf("error opening file");
        return 1;
    }
    
    int capacity = 10;
    int count = 0;
    Student *students = malloc(capacity * sizeof(Student));
    if (students == NULL) {
        printf("error allocating memory");
        return 1;
    }
    while(fscanf(file, "%99[^,],%d,%f\n",students[capacity].name, &students[capacity].age, &students[capacity].score) == 3) {
        count++;
        if (count >= capacity) {
            capacity *=2;
            Student *temp = realloc(students, capacity * sizeof(Student));
            if (temp == NULL) {
                printf("error allocating memory");
                return 1;
            }
            students = temp;
            free(temp);
        }
    }
    printf("%d", count);
    printf("Average %f", averageScores(students,count));
    
    fclose(file);

    return 0;
}