#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr);
    int x = 10;
    int result = linearSearch(arr, n, x);
    (result == -1) ? printf("Element not found\n") : printf("Element found at index %d\n", result);
    return 0;
}
