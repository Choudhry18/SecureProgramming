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

void delete(struct Node ** head, int val){
    if (*head == NULL){
        printf("this linked list is empty. \n");
        return;
    }

    struct Node *current;

    while ((*head)-> val == val){
        current = *head;  
        *head = (*head)->next;
        free(current);
    }

    current = *head;

    while(current != NULL && current->next != NULL){
        if(current->next->val == val){
            struct Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }       
        else
            current = current->next;
    }
}

int main(){
    struct Node * head = NULL;

    insert(&head, 20);
    insert(&head, 40);
    print(head);
    insert(&head, 20);
    print(head);   
    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 20);
    delete(&head, 20);
    insert(&head, 50);
    insert(&head, 20);
    print(head);
    delete(&head, 20);
    print(head);
    clear(head);
    return 0;
}