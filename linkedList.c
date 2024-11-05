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

int search(struct Node * head, int value){
    int index = 0;
    while (head != NULL){
         if (head-> val == value){
            return index;
         }
         index++;
    }
    return -1;
}

struct Node * reverse(struct Node * head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    struct Node * prev = reverse(head-> next);
    head -> next -> next = head;
    head -> next = NULL;
    return prev;
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
    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 20);
    insert(&head, 50);
    insert(&head, 20);

    print(head);

    delete(&head, 20);

    print(head);

    head = reverse(head);

    print(head);
    return 0;

}