#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "File not found!" << endl;
        return 1;
    }
    string line;
    int lines = 0;
    while (getline(file, line)) {
        lines++;
    }
    cout << "Lines: " << lines << endl;
    file.close();
    return 0;
}