#include<stdio.h>
void swap(int* a , int* b){
    int t= *a;
        *a = *b;
        *b = t;
}

int partition( int A[],int low,int high){
    int pivot = A[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(A[j]<pivot){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[high]);
    return i+1;
}

void QuickSort( int A[],int low,int high){
    if(low<high){
        int pi = partition( A,low,high);

        QuickSort(A,low,pi-1);

        QuickSort(A,pi+1,high);

    }
}

void display( int A[], int n){

    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){
    int A[]={ 10,67,43,68,90,23,54,45};
    int n=8;

    printf("Original array:\n");
    display(A,n);

    printf("sorted array:\n");
    QuickSort(A,0,n-1);
    display(A,n);

    return 0;
}