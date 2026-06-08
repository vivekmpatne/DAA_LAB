#include <stdio.h>
#include <time.h>

// quick sort
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi+1, high);
    }
}

// end quick sort

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

   
    quickSort(arr, 0, n-1);

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