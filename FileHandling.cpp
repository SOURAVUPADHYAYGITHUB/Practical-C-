#include <iostream>
#include <fstream>
#include <cctype> // for isspace()

using namespace std;

int main() {
    ifstream inputFile("input.txt");   // Input file
    ofstream outputFile("output.txt"); // Output file

    if (!inputFile) {
        cerr << "Error: Could not open input.txt for reading.\n";
        return 1;
    }

    if (!outputFile) {
        cerr << "Error: Could not open output.txt for writing.\n";
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (!isspace(static_cast<unsigned char>(ch))) {
            outputFile << ch;
        }
    }

    cout << "File copied successfully without whitespaces.\n";

    inputFile.close();
    outputFile.close();

    return 0;
}
