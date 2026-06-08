#include <stdio.h>
#include <time.h>

//  merge sort
void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for(i=0; i<n1; i++) L[i] = arr[left+i];
    for(j=0; j<n2; j++) R[j] = arr[mid + 1 + j];

    i = 0, j=0, k = left;

    while(i<n1 && j < n2){
        if(L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }

    while( i < n1){arr[k] = L[i]; i++; k++; }
    while( j < n2){arr[k] = R[j]; j++; k++; }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// end merge sort


int main(){
    int n, i; 
    int arr[10000];
    
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements:  ");
    for(i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    start = clock();

    mergeSort(arr, 0, n-1);

    // end function 

    end = clock();

    time_taken = ((double)(end-start))/ CLOCKS_PER_SEC;

    // print the sorted array
    printf("\nSorted array: ");
    for(i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;

}