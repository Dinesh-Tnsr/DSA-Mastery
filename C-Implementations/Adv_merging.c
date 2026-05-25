#include<stdio.h>

void mergeArray( int A[],int m,int B[],int n,int C[]){
    int i = 0;
    int j = 0;
    int k = 0;

    while( i < m && j < n){

        if(A[i] < B[j]){
            C[k]=A[i];
            i++;
            k++;
        }
        else{
            C[k]=B[j];
            j++;
            k++;
        }
    }
    while( i <= m){
        C[k]=A[i];
        i++;
        k++;
    }
    while( j<= n){
        C[k]=B[j];
        j++;
        k++;
    }
}

int main(){
    int A[] = {2 , 8 , 15};
    int m=3;
    int B[] = {5 , 9 , 12 , 17};
    int n=4;
    int C[7];

    mergeArray( A,m,B,n,C);
    
    for(int i=0; i< m+n ; i++){
        printf("%d ",C[i]);
    }

    return 0;
}