#include "libmx.h"

void swap(char **a, char **b) {
    char *t = *a;
    *a = *b;
    *b = t;
}
int partition(char **arr, int low, int high, int *swap_counter) {
    char *pivot = arr[high];  
    int i = (low - 1);  
    for (int j = low; j <= high; j++) {
        if (mx_strlen(arr[j]) < mx_strlen(pivot)) {
            i++;  
            swap(&arr[i], &arr[j]);   
            *swap_counter = *swap_counter + 1;
        }
        if (mx_strlen(arr[j]) == mx_strlen(pivot)) {
            if (mx_strcmp(arr[j], pivot) < 0) {
                i++;  
                swap(&arr[i], &arr[j]);
                *swap_counter = *swap_counter + 1;
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int mx_quicksort(char **arr, int left, int right) {
    static int swap_counter = 0;
    if (left < right) {
        int pi = partition(arr, left , right, &swap_counter);
        mx_quicksort(arr, left, pi - 1);
        mx_quicksort(arr, pi + 1, right);
    }
    return swap_counter;
}
