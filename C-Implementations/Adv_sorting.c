#include<stdio.h>

void merge( int A[],int low, int mid ,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int B[100];

    while( i<=mid && j<=high){
        if( A[i] < A[j]){
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while( i <= mid){
        B[k]=A[i];
        i++;
        k++;
    }
    while( j <= high){
        B[k] = A[j];
        j++;
        k++;
    }

    for(int x=low;x<=high;x++){
        A[x]=B[x];
    }
}

void mergesort(int A[], int low, int high){
    if(low<high){
        int mid = (high+low)/2;

        mergesort( A,low,mid);
        mergesort( A,mid+1,high);
        merge(A,low,mid,high);
    }
}

void display( int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){
    int A[]={38, 27, 43, 3, 9, 82, 10};
    int n=7;
    int low = 0;
    int high = n-1;

    printf("Original array:");
    display(A,n);
    mergesort(A,low,high);
    printf("After merge sorting:");
    display(A,n);

    return 0;
}