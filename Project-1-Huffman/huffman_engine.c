#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct HuffmanNode{
    char data;
    int frq;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

struct HuffmanNode* createnode(char value,int freq){
    struct HuffmanNode* root = malloc(sizeof(struct HuffmanNode));
    root->data=value;
    root->frq = freq;
    root->left = NULL;
    root->right = NULL;

    return root;
}

void printArray(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void  printCodes(struct HuffmanNode* root, int A[], int top){
    if( root->left!=NULL){
        A[top]=0;
        printCodes(root->left,A,top+1);
    }

    if(root->right!=NULL){
        A[top]= 1;
        printCodes(root->right,A,top+1);
    }

    if(root->left == NULL && root->right == NULL){
        printf("'%c': ",root->data);
        printArray(A,top);
    }
}
int main(){
    char text[] = "engineering is about execution";
    int freq[256] = {0};
    int i = 0;
    int count = 0;
    while(text[i]!='\0'){
        freq[text[i]]++;
        count++;
        i++;
    }

    printf("total count: %d\n",count);

    for(int i=0;i<256;i++){
        if(freq[i]>0){
            printf("count of '%c': %d\n",i,freq[i]);
        }
    }

    struct HuffmanNode* staging[256];
    int size = 0;

    for(int i=0;i<256;i++){
        if(freq[i]>0){
        staging[size] = createnode(i,freq[i]);
        size++;
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size-1-i;j++){
            if(staging[j]->frq > staging[ j+1]->frq){
                struct HuffmanNode* temp = staging[j];
                staging[j] = staging[j+1];
                staging[j+1] = temp;
            }
        }
    }
    printf("\nsorted staging array data and frequency:\n");
    for(int i=0;i<size;i++){

        printf("%c : %d\n",staging[i]->data,staging[i]->frq);
    }

    while(size > 1){
        struct HuffmanNode* left = staging[0];
        struct HuffmanNode* right = staging[1];

        struct HuffmanNode* parent = createnode('$',left->frq+right->frq);

        parent->left = left;
        parent->right = right;

        staging[0] = parent;

        for(int i=1;i<size-1;i++){
            staging[i]=staging[i+1];
        }
        
        size--;

         for(int i=0;i<size;i++){
            for(int j=0;j<size-1-i;j++){
                if(staging[j]->frq > staging[ j+1]->frq){
                struct HuffmanNode* temp = staging[j];
                staging[j] = staging[j+1];
                staging[j+1] = temp;
                }
            }
        }
        
        
    }

    struct HuffmanNode* root = staging[0];
    printf("Final tree root frequency: %d", root->frq);

    int A[100];
    int top=0;
    printf("\nHuffman Binary codes:\n");
    printCodes(root,A,top);

    return 0;
}