#include "array_utils.h"

int sum_of_digits(int num) {
    if (num < 0) num = -num;
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void find_max_digit_sum_indices(const int *arr, int size, int *result_indices, int *result_count) {
    if (size <= 0 || arr == NULL || result_indices == NULL || result_count == NULL) {
        *result_count = 0;
        return;
    }

    int max_sum = -1;
    *result_count = 0;

    for (int i = 0; i < size; ++i) {
        int current_sum = sum_of_digits(arr[i]);
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    for (int i = 0; i < size; ++i) {
        if (sum_of_digits(arr[i]) == max_sum) {
            result_indices[*result_count] = i;
            (*result_count)++;
        }
    }
}