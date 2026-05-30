#include<stdio.h>
int main(){

    int A[4][4] = {0};

    A[0][1]=A[1][0]=1;
    A[0][2]=A[2][0]=1;
    A[1][2]=A[2][1]=1;
    A[2][3]=A[3][2]=1;

    int visited[4] = {0};
    
    int queue[100];
    int front=0;
    int rear=0;

    int struct_node = 0;
    visited[struct_node]=1;

    queue[rear] = struct_node;
    rear++;
    
    printf("BFS traversal:");

    while(front<rear){
        int current = queue[front];
        front++;
        printf("%d ",current);

        for(int j=0;j<4;j++){
            if(A[current][j]==1 && visited[j]==0){
                visited[j]=1;
                queue[rear]=j;
                rear++;
            }
        }
    }
    printf("\n");

    return 0;
}