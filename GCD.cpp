#include <iostream>
using namespace std;

// a) GCD using recursion
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

// b) GCD without recursion (iterative)
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;

    cout << "GCD (recursive): " << gcdRecursive(num1, num2) << endl;
    cout << "GCD (iterative): " << gcdIterative(num1, num2) << endl;

    return 0;
}
