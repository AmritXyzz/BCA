#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; // Element found
        }
        if (arr[mid] < x) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) ;
    int x = 4;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element not found\n") : printf("Element found at index %d\n", result);
    return 0;
}