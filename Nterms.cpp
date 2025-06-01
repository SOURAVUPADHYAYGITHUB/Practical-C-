#include <iostream>
#include <sstream>  // for stringstream
using namespace std;

int main(int argc, char* argv[]) {
    int n;

    if (argc > 1) {
        stringstream ss(argv[1]);
        if (!(ss >> n) || n <= 0) {
            cout << "Invalid command line input. Enter positive integer n: ";
            cin >> n;
        }
    } else {
        cout << "Enter the number of terms n: ";
        cin >> n;
    }

    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        double term = 1.0 / i;
        if (i % 2 == 0) term = -term;
        sum += term;
    }

    cout << "Sum of first " << n << " terms: " << sum << endl;
    return 0;
}
