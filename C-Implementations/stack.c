#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *push(struct node *top,int new_data){
    struct node* ptr=malloc(sizeof(struct node));
    ptr->data=new_data;
    ptr->next=top;
    return ptr;
}
struct node *pop(struct node *top){
    if(top==NULL){
        printf("stack under flow\n");
    }
    else{
    struct node* temp=top;
    top=top->next;
    free(temp);
    }
    return top;
}
void display(struct node *top){
    struct node *ptr;
    ptr=top;
    printf("stack:");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    struct node *top=NULL;
    top=push(top,10);
    top=push(top,45);
    top=push(top,50);
    display(top);
    top=pop(top);
    display(top);
    return 0;
}
