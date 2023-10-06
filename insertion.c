#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1
struct Node * InsertFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node)); //extra memory needed to store data..
    ptr->data = data;
 
    ptr->next = head;
    return ptr; 
}

//Case 2
struct Node * InsertIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node)); //extra memory for storing in between..
    struct Node * p = head;
    int i=0;

    while(i!=index-1){ //keeping 'p' before the location we want to add node..
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

//Case 3
struct Node * InsertEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node)); //extra memory needed to store data..
    ptr->data = data;
    struct Node * p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next=NULL;
    return head; 
}

//Case 4
struct Node * InsertAfterNode(struct Node *head,struct Node *prevnode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node)); //extra memory needed to store data..
    ptr->data = data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head; 
}
 
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
 
    linkedListTraversal(head);
    printf("After Operations:-\n ");
    //head = InsertFirst(head, 56);
    //head = InsertIndex(head, 66, 1);
    //head = InsertEnd(head, 8);
    head = InsertAfterNode(head, second, 2);
    linkedListTraversal(head);
    return 0;
}
