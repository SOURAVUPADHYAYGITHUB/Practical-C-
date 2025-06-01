#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int freq[26] = {0};

    if (argc < 2) {
        cout << "Please provide text as command line arguments.\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        for (char* p = argv[i]; *p != '\0'; ++p) {
            char ch = *p;
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';  // to lowercase
            if (ch >= 'a' && ch <= 'z')
                freq[ch - 'a']++;
        }
    }

    cout << "Letter frequencies:\n";
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0)
            cout << char('a' + i) << ": " << freq[i] << endl;
    }

    return 0;
}
