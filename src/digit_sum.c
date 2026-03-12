#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int num) {
    int sum = 0;
    num = abs(num);
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void findNumbersWithMaxDigitSum(int arr[], int n) {
    int maxSum = -1;
    int sums[n];
    for (int i = 0; i < n; i++) {
        sums[i] = sumOfDigits(arr[i]);
        if (sums[i] > maxSum) {
            maxSum = sums[i];
        }
    }
    printf("Числа с максимальной суммой цифр (%d): ", maxSum);
    for (int i = 0; i < n; i++) {
        if (sums[i] == maxSum) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {123, 45, 678, 99, 111, 999};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    findNumbersWithMaxDigitSum(arr, n);
    return 0;
}
