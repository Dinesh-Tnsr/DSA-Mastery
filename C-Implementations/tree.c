#include<stdio.h>
#include<stdlib.h>
struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
};
struct treenode* createtree(int value){
    struct treenode *root=malloc(sizeof(struct treenode));
    root->data=value;
    root->left=NULL;
    root->right=NULL;

    return root;
}
struct treenode* insertNode(struct treenode* root,int new_value){
    if(root==NULL){
        root=createtree(new_value);
    }
    else{
        if(new_value>root->data){
            root->right=insertNode(root->right,new_value);
        }
        else if(new_value<root->data){
            root->left=insertNode(root->left,new_value);
        }
    }
    return root;
}

void inOrderTraversal(struct treenode* root){
    if(root==NULL){ return;}
    else{
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct treenode* root){
    if(root==NULL){ return;}
    else{
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct treenode* root){
    if(root==NULL){ return;}
    else{
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct treenode* root=insertNode(NULL,59);
    root=insertNode(root,67);
    root=insertNode(root,89);
    root=insertNode(root,65);
    root=insertNode(root,47); 
    printf("%d\n",root->data);
    printf("%d\n",root->left->data);
    printf("%d",root->right->data);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    return 0;
}