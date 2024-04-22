#include <stdio.h>

void printSubset(int subset[], int n) {
    for (int i = 0; i < n; i++) {
        if (subset[i]) {
            printf("%d ", subset[i]);
        }
    }
    printf("\n");
}

int findSubset(int arr[], int n, int sum) {
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= sum; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    if (!dp[n][sum]) {
        printf("Подмножество с заданной суммой не существует\n");
        return 0;
    }

    int subset[n];
    int i = n, j = sum;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            subset[i - 1] = arr[i - 1];
            j -= arr[i - 1];
        } else {
            subset[i - 1] = 0;
        }
        i--;
    }

    printf("Подмножество с заданной суммой: ");
    printSubset(subset, n);

    return 1;
}

int main() {
    int arr[] = {-2, -3, 15, 14, 7, -10};
    int sum = 20; // Любая другая сумма
    int n = sizeof(arr) / sizeof(arr[0]);

    findSubset(arr, n, sum);

    return 0;
}