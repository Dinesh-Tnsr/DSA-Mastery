#include <stdio.h>
#include <stdlib.h>

void bubble_swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// 1. Bubble Sort
void bubble_sort(int *A, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(*(A + j) > *(A + j + 1)) {
                bubble_swap((A + j), (A + j + 1));
            }
        }
    }
}

// 2. Selection Sort
void selection_sort(int *A, int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_index = i;
        for(int j = i + 1; j <= n - 1; j++) {
            if(*(A + j) < *(A + min_index)) {
                min_index = j;
            }
        }
        if(min_index != i) {
            swap((A + i), (A + min_index));
        }
    }
}

// 3. Insertion Sort
void insertion_sort(int *A, int n) {
    for(int i = 1; i < n; i++) {
        int key = *(A + i);
        int j = i - 1;
        while(j >= 0 && *(A + j) > key) {
            *(A + j + 1) = *(A + j);
            j--;
        }
        *(A + j + 1) = key;
    }
}

// 4. Merge Sort (Divide & Merge)
void merge(int *a, int low, int mid, int high) {
    int *t = malloc((high + 1) * sizeof(int));
    int i = low, k = mid + 1, j = low;
    while(i <= mid && k <= high) {
        if(*(a + i) < *(a + k)) { *(t + j) = *(a + i); i++; }
        else { *(t + j) = *(a + k); k++; }
        j++;
    }
    while(i <= mid) { *(t + j) = *(a + i); i++; j++; }
    while(k <= high) { *(t + j) = *(a + k); k++; j++; }
    for(int i = low; i <= high; i++) { *(a + i) = *(t + i); }
    free(t);
}

void merge_sort_divide(int *a, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        merge_sort_divide(a, low, mid);
        merge_sort_divide(a, mid + 1, high);
        merge (a, low, mid, high);
    }
}

// 5. Quick Sort (Partition & Quick)
int partition(int *a, int low, int high) {
    int pivot = *(a + low);
    int i = low, j = high;
    while(i < j) {
        while(*(a + i) <= pivot && i < high) { i++; }
        while(*(a + j) > pivot) { j--; }
        if(i < j) { swap(a + i, a + j); }
    }
    swap(a + low, a + j);
    return j;
}

void quick_sort(int *a, int low, int high) {
    if(low < high) {
        int j = partition(a, low, high);
        quick_sort(a, low, j - 1);
        quick_sort(a, j + 1, high);
    }
}

// --- Driver Function ---
int main() {
    int n, choice;
    printf("Enter the limit: ");
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);

    printf("\nChoose Sort: 1.Bubble 2.Selection 3.Insertion 4.Merge 5.Quick\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: bubble_sort(a, n); break;
        case 2: selection_sort(a, n); break;
        case 3: insertion_sort(a, n); break;
        case 4: merge_sort_divide(a, 0, n - 1); break;
        case 5: quick_sort(a, 0, n - 1); break;
        default: printf("Invalid choice!");
    }

    printf("\nSorted array is: [ ");
    for(int i = 0; i < n; i++) printf("%d ", *(a + i));
    printf("]\n");

    free(a);
    return 0;
}