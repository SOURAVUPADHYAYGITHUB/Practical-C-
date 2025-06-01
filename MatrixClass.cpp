#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Matrix {
    int rows, cols;
    vector<vector<int>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}

    void input() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> data[i][j];
    }

    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << "\n";
        }
    }

    Matrix add(const Matrix& m) {
        if (rows != m.rows || cols != m.cols)
            throw string("Matrices must have same dimensions for addition.");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }

    Matrix multiply(const Matrix& m) {
        if (cols != m.rows)
            throw string("Number of columns of first matrix must equal rows of second.");
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < m.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k)
                    sum += data[i][k] * m.data[k][j];
                result.data[i][j] = sum;
            }
        return result;
    }

    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[j][i] = data[i][j];
        return result;
    }
};

int main() {
    int choice;
    Matrix* mat1 = nullptr;
    Matrix* mat2 = nullptr;

    while (true) {
        cout << "\nMenu:\n"
             << "1. Create Matrix 1\n"
             << "2. Create Matrix 2\n"
             << "3. Add Matrices\n"
             << "4. Multiply Matrices\n"
             << "5. Transpose Matrix 1\n"
             << "6. Transpose Matrix 2\n"
             << "7. Display Matrix 1\n"
             << "8. Display Matrix 2\n"
             << "9. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    int r, c;
                    cout << "Enter rows and cols for Matrix 1: ";
                    cin >> r >> c;
                    delete mat1;
                    mat1 = new Matrix(r, c);
                    mat1->input();
                    break;
                }
                case 2: {
                    int r, c;
                    cout << "Enter rows and cols for Matrix 2: ";
                    cin >> r >> c;
                    delete mat2;
                    mat2 = new Matrix(r, c);
                    mat2->input();
                    break;
                }
                case 3:
                    if (!mat1 || !mat2) throw string("Create both matrices first.");
                    {
                        Matrix result = mat1->add(*mat2);
                        cout << "Sum:\n";
                        result.display();
                    }
                    break;
                case 4:
                    if (!mat1 || !mat2) throw string("Create both matrices first.");
                    {
                        Matrix result = mat1->multiply(*mat2);
                        cout << "Product:\n";
                        result.display();
                    }
                    break;
                case 5:
                    if (!mat1) throw string("Create Matrix 1 first.");
                    {
                        Matrix result = mat1->transpose();
                        cout << "Transpose of Matrix 1:\n";
                        result.display();
                    }
                    break;
                case 6:
                    if (!mat2) throw string("Create Matrix 2 first.");
                    {
                        Matrix result = mat2->transpose();
                        cout << "Transpose of Matrix 2:\n";
                        result.display();
                    }
                    break;
                case 7:
                    if (!mat1) throw string("Create Matrix 1 first.");
                    cout << "Matrix 1:\n";
                    mat1->display();
                    break;
                case 8:
                    if (!mat2) throw string("Create Matrix 2 first.");
                    cout << "Matrix 2:\n";
                    mat2->display();
                    break;
                case 9:
                    delete mat1;
                    delete mat2;
                    return 0;
                default:
                    cout << "Invalid choice.\n";
            }
        } catch (const string& e) {
            cout << "Error: " << e << endl;
        }
    }
}
