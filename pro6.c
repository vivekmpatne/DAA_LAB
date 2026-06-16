#include <stdio.h>

struct Item {
    int value;
    int weight;
};

int main() {
    int n;
    float capacity;
    float totalValue = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    float ratio[n];

    printf("Enter value and weight of each item:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);

        ratio[i] = (float)items[i].value / items[i].weight;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(ratio[j] < ratio[j + 1])   {
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                struct Item tempItem = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tempItem;
            }
        }
    }
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for(int i = 0; i < n; i++) {
        if(items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else  {
            totalValue += items[i].value * (capacity / items[i].weight) ;
            break;
        }
    }
    printf("\nMaximum value = %.2f\n",
           totalValue);

    return 0;
}