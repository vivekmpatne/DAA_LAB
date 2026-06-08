#include <stdio.h>

int combo[50];

void findWays(int coins[], int n, int index, int sum, int target, int size) {

    if(sum == target) {
        printf("Combination: ");
        for(int i = 0; i < size; i++) {
            printf("%d ", combo[i]);
        }
        printf("\n");
        return;
    }

    if(index == n || sum > target)
        return;
    combo[size] = coins[index];

    findWays( coins, n, index + 1, sum + coins[index], target, size + 1 );

    findWays( coins, n, index + 1, sum, target, size );
}

int main() {

    int n, target;

    printf("Enter number of denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter denominations:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter target amount: ");
    scanf("%d", &target);

    printf("\nPossible combinations:\n");

    findWays(coins, n, 0, 0, target, 0);

    return 0;
}