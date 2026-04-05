#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* rear=NULL;
struct node* enqueue(int value){
    struct node* ptr=malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        rear=ptr;
    }
    else{
        rear->next=ptr;
        rear=ptr;
    }
    return head;
}
struct node* dequeue(){
    if(head==NULL){
        printf("Queue under flow\n");
        return NULL;
    }
    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
void display(struct node* head){
    struct node* ptr=head;
    printf("displaying queue:");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    head=enqueue(40);
    head=enqueue(50);
    head=enqueue(60);
    head=enqueue(70);
    printf("Aftrt enqueue\n");
    display(head);
    head=dequeue();
    printf("After dequeue\n");
    display(head);
}