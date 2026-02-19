#include <stdio.h>
#include <stdlib.h>

void linearSearch(int *p, int n, int key) {
    int found = -1;
    for(int i = 0; i < n; i++) {
        if(*(p + i) == key) {
            found = i;
            break;
        }
    }
    
    if(found != -1) {
        printf("\n[Linear] The index of number %d is %d\n", key, found);
    } else {
        printf("\n[Linear] Element Not found\n");
    }
}

void binarySearch(int A[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int found = -1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        if(A[mid] == key) {
            found = mid;
            break;
        }
        else if(A[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    if(found != -1) {
        printf("[Binary] Element found at index %d\n", found);
    } else {
        printf("[Binary] Element not found\n");
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *p = malloc(n * sizeof(int));
    if(p == NULL) return 1; 

    printf("Enter the elements (Sorted for Binary Search):\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", p + i);
    }

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    linearSearch(p, n, key);
    binarySearch(p, n, key);

    free(p); 
    return 0;
}