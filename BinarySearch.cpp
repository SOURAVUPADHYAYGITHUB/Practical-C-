#include <iostream>
using namespace std;

// (i) Recursive binary search
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, right, key);
    else
        return binarySearchRecursive(arr, left, mid - 1, key);
}

// (ii) Iterative binary search
int binarySearchIterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int resRec = binarySearchRecursive(arr, 0, n - 1, key);
    int resIter = binarySearchIterative(arr, n, key);

    if (resRec != -1)
        cout << "Element found at index (recursive): " << resRec << "\n";
    else
        cout << "Element not found (recursive)\n";

    if (resIter != -1)
        cout << "Element found at index (iterative): " << resIter << "\n";
    else
        cout << "Element not found (iterative)\n";

    return 0;
}
