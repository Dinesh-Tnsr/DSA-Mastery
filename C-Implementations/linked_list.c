#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void traversal(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

struct node* createlist(int n){
    struct node* head=NULL;
    struct node* tail=NULL;
    for(int i=0;i<n;i++){
        struct node* ptr=malloc(sizeof(struct node));
        printf("Enter element %d:\n",i+1);
        scanf("%d",&ptr->data);
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
int main(){
    int n;
    printf("Enter the limit of linked list:\n");
    scanf("%d",&n);
    struct node* head=createlist(n);
    printf("dynamically built list:");
    traversal(head);
    return 0;
}