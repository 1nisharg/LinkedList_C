#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

// Linking first and second node
    head->data=7;
    head->next=second;

    //Linking second and third node
    head->data=11;
    second->next=third;

    //terminating the list
    third->data=66;
    third->next=NULL;
}
