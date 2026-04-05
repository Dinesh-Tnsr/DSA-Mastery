#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node *createlist(int n){
    struct node* head=NULL;
    struct node *tail=NULL;
    for(int i=0;i<n;i++){
    struct node *ptr=malloc(sizeof(struct node));
    int new_data;
    printf("Enter element %d:",i+1);
    scanf("%d",&new_data);
    ptr->data=new_data;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        tail=ptr;
    }
    else{
        tail->next=ptr;
        tail=ptr;
    }
    }
    return head;
}
void display(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node *LLreversal(struct node *head){
    struct node *prev;
    struct node *curr;
    struct node *next;
    prev=NULL;
    curr=head;
    next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main(){
    int n;
    printf("enter the limit of linked list:\n");
    scanf("%d",&n);
    struct node* head;
    head=createlist(n);
    printf("list before reverse:\n");
    display(head);
    printf("list after reverse:\n");
    head=LLreversal(head);
    display(head);
}