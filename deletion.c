#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
   while(ptr!=NULL){
    printf("Elements: %d\n", ptr->data);
    ptr = ptr->next;
   } 
}
//Case 1
struct Node* deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head=head->next;
    free(ptr);
    return head;   
}

//Case 2
struct Node* deleteBtw(struct Node * head, int index){
      struct Node *p = head;
      struct Node *q = head->next;
      for(int i=0; i<index-1;i++)
      {
        p = p->next;
        q = q->next;

      }
      p->next=q->next;
      free(q);
      return head;
}

//Case 3
struct Node* deleteLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q!=NULL)
    p->next=NULL;
    free(q);
    return head;


}

//Case 4
struct Node* deleteNode(struct Node * head, int value){
      struct Node *p = head;
      struct Node *q = head->next;
      while(q->data!=value && q->next!=NULL)
      {
        p = p->next;
        q = q->next;

      }
      if(q->data == value){
        p->next=q->next;
        free(q);
      }
      return head;
}
int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

// Linking first and second node
    head->data=4;
    head->next=second;

    //Linking second and third node
    head->data=3;
    second->next=third;

    //terminating the list
    third->data=8;
    third->next=NULL;

    linkedListTraversal(head);
    printf("List after Deletion:-\n");
    //head = deleteFirst(head); //Case 1
    //head = deleteBtw(head, 1); //Case 2
    //head = deleteLast(head); //Case 3
    head = deleteNode(head, 1);
    linkedListTraversal(head);
}
