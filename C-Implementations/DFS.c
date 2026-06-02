#include<stdio.h>
int visited[4] = {0};
int A[4][4] = {0};

void DFS(int current){
    printf("%d ",current);
    visited[current] = 1;
    
    for(int j=0;j<4;j++){
        if(A[current][j] == 1 && visited[j]==0){
            DFS(j);
        }
    }
}

int main(){
    A[0][1] = 1; A[1][0] = 1;
    A[0][2] = 1; A[2][0] = 1;
    A[1][2] = 1; A[2][1] = 1;
    A[2][3] = 1; A[3][2] = 1;

    printf("DFS traversal: ");
    DFS(0);

    printf("\n");

    return 0;
}