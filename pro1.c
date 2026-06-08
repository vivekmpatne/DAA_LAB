#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

    }
}

int main(){
    

    // the static ( stack ) array worked for 5k, 50k, 90k, 1 lakh elements. but didn't run for 5 lakh ( TLE , Stack overflow )

    // now creat dynamic ( heap ) memory and check for n = 5 lakh 

    // result didn't run for 500k. why ? lets check and update here
    
    // Reason:
    // NOT because of memory.
    // Memory required = 500000 * 4 bytes = ~2 MB only,
    // which is easily handled by heap memory.

    // Actual problem:
    // Selection Sort has O(n²) time complexity.

    int n; 
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //int arr[n];
    
    // here creat dynamic ( malloc )
    int *arr = (int *)malloc(n * sizeof(int)); // one line 

    for(int i=0; i<n; i++){
        arr[i] = rand();
    }

    clock_t start = clock();

    selSort(arr, n);

    clock_t end = clock();

    double timeTaken = (double)(end-start) / CLOCKS_PER_SEC;

    printf("after sorting :  \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("Time taken = %lf second \n", timeTaken);

    // when use dynamic then need to clear also the heap allocation
    free(arr);

    return 0;
}