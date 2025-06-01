#include <iostream>
using namespace std;

// a. Show address of each character
void showAddresses(char* str) {
    cout << "Character addresses:\n";
    for (int i = 0; *(str + i) != '\0'; i++) {
        cout << "Char '" << *(str + i) << "' at address: " << (void*)(str + i) << endl;
    }
}

// b. Concatenate two strings (result in first string, assuming enough space)
void concatenate(char* str1, const char* str2) {
    // Move to end of str1
    while (*str1 != '\0') str1++;

    // Copy str2 at end of str1
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

// c. Compare two strings
int compare(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// d. Calculate length (using pointers)
int length(const char* str) {
    const char* ptr = str;
    while (*ptr) ptr++;
    return ptr - str;
}

// e. Convert lowercase to uppercase (in place)
void toUpperCase(char* str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - ('a' - 'A');
        }
        str++;
    }
}

// f. Reverse string (in place)
void reverse(char* str) {
    int len = length(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// g. Insert string2 into string1 at position pos (1-based index)
void insertString(char* str1, const char* str2, int pos) {
    int len1 = length(str1);
    int len2 = length(str2);

    if (pos < 1 || pos > len1 + 1) {
        cout << "Invalid position.\n";
        return;
    }

    // Move the part of str1 after pos to the right by len2 places
    for (int i = len1; i >= pos - 1; i--) {
        str1[i + len2] = str1[i];
    }

    // Copy str2 into str1 at pos
    for (int i = 0; i < len2; i++) {
        str1[pos - 1 + i] = str2[i];
    }
}

int main() {
    const int MAX = 200;
    char str1[MAX], str2[MAX];
    int choice;

    while (true) {
        cout << "\n--- String Manipulation Menu ---\n";
        cout << "1. Show address of each character\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of a string\n";
        cout << "5. Convert to uppercase\n";
        cout << "6. Reverse string\n";
        cout << "7. Insert a string at a position\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear newline

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin.getline(str1, MAX);
                showAddresses(str1);
                break;

            case 2:
                cout << "Enter first string (enough space for concatenation): ";
                cin.getline(str1, MAX);
                cout << "Enter second string to concatenate: ";
                cin.getline(str2, MAX);
                concatenate(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;

            case 3:
                cout << "Enter first string: ";
                cin.getline(str1, MAX);
                cout << "Enter second string: ";
                cin.getline(str2, MAX);
                {
                    int cmp = compare(str1, str2);
                    if (cmp == 0) cout << "Strings are equal.\n";
                    else if (cmp < 0) cout << "First string is less than second.\n";
                    else cout << "First string is greater than second.\n";
                }
                break;

            case 4:
                cout << "Enter a string: ";
                cin.getline(str1, MAX);
                cout << "Length of string: " << length(str1) << endl;
                break;

            case 5:
                cout << "Enter a string: ";
                cin.getline(str1, MAX);
                toUpperCase(str1);
                cout << "Uppercase string: " << str1 << endl;
                break;

            case 6:
                cout << "Enter a string: ";
                cin.getline(str1, MAX);
                reverse(str1);
                cout << "Reversed string: " << str1 << endl;
                break;

            case 7:
                cout << "Enter the main string (enough space for insertion): ";
                cin.getline(str1, MAX);
                cout << "Enter string to insert: ";
                cin.getline(str2, MAX);
                int pos;
                cout << "Enter position to insert at (1-based index): ";
                cin >> pos;
                cin.ignore();
                insertString(str1, str2, pos);
                cout << "String after insertion: " << str1 << endl;
                break;

            case 8:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
