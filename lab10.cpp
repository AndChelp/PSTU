#include <iostream>

using namespace std;

//Обертка для матрицы
class Matrix {
    int rows = 0;
    int cols = 0;
    int **array{};

public:
    int getRowsCount() const { return rows; }

    int getColumnsCount() const { return cols; }

    int getValue(int row, int col) { return array[row][col]; }

    void setValue(int row, int col, int val) { array[row][col] = val; }

    void deleteRow(int rowIndex) {
        rows--;
        for (int row = rowIndex; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                array[row][col] = array[row + 1][col];
            }
        }
        delete[] array[rows];
    }

    void clear() {
        for (int row = 0; row < rows; row++)
            delete array[row];
        delete[] array;
        cols = 0;
        rows = 0;
    }

    Matrix(int rowsCount, int colsCount) : rows(rowsCount), cols(colsCount) {
        array = new int *[rowsCount];
        for (int i = 0; i < rowsCount; i++) {
            array[i] = new int[colsCount];
        }
    }

    //Вызовется при завершении программы
    ~Matrix() { clear(); }
};

int intInput(const string &str) {
    int value;
    cout << str << ": ";
    cin >> value;
    return value;
}

void printMatrix(Matrix &matrix) {
    for (int i = 0; i < matrix.getRowsCount(); i++) {
        for (int j = 0; j < matrix.getColumnsCount(); j++) {
            cout << matrix.getValue(i, j) << "\t";
        }
        cout << "\n";
    }
}

void fillMatrixRandom(Matrix &matrix) {
    for (int i = 0; i < matrix.getRowsCount(); i++) {
        for (int j = 0; j < matrix.getColumnsCount(); j++) {
            matrix.setValue(i, j, rand() % 100 + 1);
        }
    }
}

int main() {
    int rows = intInput("Rows");
    int cols = intInput("Cols");

    srand(rows + cols);

    Matrix matrix(rows, cols);
    fillMatrixRandom(matrix);
    cout << "До удаления: \n";
    printMatrix(matrix);

    int delRowIndex = intInput("\nИндекс удаляемого ряда");
    matrix.deleteRow(delRowIndex);
    cout << "После удаления: \n";
    printMatrix(matrix);
}








