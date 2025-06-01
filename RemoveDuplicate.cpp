#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // Remove duplicates
    int size = n;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ) {
            if (arr[i] == arr[j]) {
                // Shift elements left
                for (int k = j; k < size - 1; ++k)
                    arr[k] = arr[k + 1];
                --size;  // reduce array size
            } else {
                ++j;
            }
        }
    }

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
