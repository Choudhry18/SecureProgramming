#include <stdlib.h>
#include <stdio.h>
#include <float.h>
struct Node
{
    int val;
    struct Node * next;
};

void insert(struct Node ** head, int value){
        struct Node * new_node = malloc(sizeof(struct Node));
        new_node -> val = value;
        new_node -> next = *head;
        *head = new_node;
}

void print(struct Node *head){
    int i = 0;
    while(head!= NULL){
        printf("%d\n", head -> val);
        head = head -> next;
        i++;
    }
}

void delete(struct Node ** head, int data) {
    if (*head == NULL) {
        return;
    }
    struct Node * current;

    while ((*head)->val == data){
        current = *head;
        *head = (*head)->next;
        free(current);
    }
    current = *head;
    while (current != NULL && current->next != NULL) {
        if(current->next->val == data){
            struct Node *temp=current->next;
            current->next = current->next->next;
            free(temp);
        }
        else {
            current = current->next;
        }
    }
}

void reverse(struct Node **head){
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while(current != NULL){
        next = current ->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

double add(double a, double b){
    if(((a>0 && b>0) || (a<0 && b<0)) && abs(a) > DBL_MAX - abs(b)){
        print("overflow");
        return -1;
    }
    return a+b;
    }
double sub(double a, double b){return add(a, -1 * b);}
double mul(double a, double b){return a*b;}
double divi(double a, double b){return a/b;}
int main(){
    double i, j;
    double (* opp)(double, double);
    scanf("%lf %lf", &i, &j);

    int select;
    printf("What is the opperation, \n");
    scanf("%d", &select);
    switch(select){
        case 1:
        opp = add;
        break;
        case 2:
        opp = sub;
        break;
        case 3:
        opp = mul;
        break;
        case 4:
        opp = divi;
        break;
    }

    printf("%lf", opp(i,j));
    return 0;
}
