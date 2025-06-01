#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge until one array is exhausted
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    // Copy remaining elements from arr1
    while (i < size1)
        merged[k++] = arr1[i++];

    // Copy remaining elements from arr2
    while (j < size2)
        merged[k++] = arr2[j++];
}

int main() {
    int n1, n2;
    cout << "Enter size of first sorted array: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int merged[n1 + n2];
    mergeArrays(arr1, n1, arr2, n2, merged);

    cout << "Merged sorted array:\n";
    for (int i = 0; i < n1 + n2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
