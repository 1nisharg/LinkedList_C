#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* head){
   struct Node *ptr = head;
    printf("elements is %d \n", ptr);
    ptr = ptr->next;
    
    do{
    printf("elements is %d \n", ptr);
    ptr = ptr->next;
   }while(ptr!=head);
}

struct Node * Insertfirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head->next;
    ptr->data=data;
}
int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

// Linking first and second node
    head->data=4;
    head->next=second;

    //Linking second and third node
    head->data=3;
    second->next=third;

    //third to fourth 
    third->data=6;
    third->next=fourth;

    //fourth to head
    fourth->data = 1;
    fourth->next=head;

    linkedListTraversal(head);
    printf("-------------------\n");
    head = Insertfirst(head, 8);
    linkedListTraversal(head);
}
