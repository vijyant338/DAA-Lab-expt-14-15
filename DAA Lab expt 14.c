//Name : Vijyant
//  Roll no : 25/DA/063

#include <stdio.h>
#include <stdlib.h>

// A utility function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    
    // Allocate memory for the 2D DP table of size (n + 1) x (W + 1)
    int** K = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i <= n; i++) {
        K[i] = (int*)malloc((W + 1) * sizeof(int));
    }

    // Build the DP table K[][] in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            // Base case: if no items are considered or knapsack capacity is 0
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            // If the weight of the current item is less than or equal to current capacity w
            else if (wt[i - 1] <= w) {
                // Max of:
                // 1. Including the current item (value + value of remaining capacity)
                // 2. Excluding the current item
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            // If the weight of the current item exceeds the current capacity w, exclude it
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // Store the final result
    int maxVal = K[n][W];

    // Free dynamically allocated memory to prevent memory leaks
    for (i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);

    return maxVal;
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Items available:\n");
    printf("Item\tWeight\tValue\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, wt[i], val[i]);
    }
    printf("Knapsack Capacity: %d\n\n", W);

    int maxProfit = knapsack(W, wt, val, n);
    printf("Maximum value that can be accumulated = %d\n", maxProfit);

    return 0;
}