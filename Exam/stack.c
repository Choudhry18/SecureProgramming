#include <stdio.h>
#include <stdlib.h>


struct Node{
    int val;
    struct Node * next;
};

void insert(struct Node ** head, int val){
    struct Node * current = (struct Node *) malloc(sizeof(struct Node));
    current->val = val;
    current->next = *head;
    *head = current;
}

void print(struct Node * head){
    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void clear(struct Node * head){
    while (head != NULL){
        struct Node * temp = head->next;
        free(head);
        head = temp;
    }
}

void pop(struct Node ** head){
    if (*head == NULL){
        printf("The stack is empty. \n");
        return;
    }

    struct Node *current;

    current = *head;  
    *head = (*head)->next;
    printf("Popped %d\n", current->val);
    free(current);
}


int main(){
    struct Node * head = NULL;
    insert(&head, 20);
    pop(&head);
    pop(&head);
    clear(head);
    return 0;
}