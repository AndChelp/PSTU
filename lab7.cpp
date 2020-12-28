#include <iostream>
#include <cstring>

using namespace std;

int intInput(const string &str) {
    int value;
    cout << str;
    cin >> value;
    return value;
}

template<class T>
void printArray(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << "\t";
    }
    cout << "\n";
}

template<class T>
void fillRandom(T *array, int size) {
    int seed = size;
    srand(seed);
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100 + 1;
    }
    printArray(array, size);
}

void _2_findOddMax(int n, ...) {
    int *p = &n;
    int index = 0;
    int max = *(++p);
    for (; n > 0; n--) {
        if (index++ % 2 != 0 && max < *(p)) {
            max = *(p);
        }
        p++;
    }
    cout << max << "\n";
}

template<class T>
int findMinPos(T *array, int size) {
    T minItem = array[size];
    int minPos = size--;
    for (; size >= 0; size--) {
        if (array[size] < minItem) {
            minItem = array[size];
            minPos = size;
        }
    }
    return minPos;
}

template<class T>
void _3_abstractArraySort(T *array, int size) {
    size--;
    for (; size >= 0; size--) {
        int minItemPos = findMinPos(array, size);
        T a = array[size];
        array[size] = array[minItemPos];
        array[minItemPos] = a;
    }
}

void _3_arraySort(int *array, int size) {
    _3_abstractArraySort(array, size);
}

void _3_arraySort(char *array, int size) {
    _3_abstractArraySort(array, size);
}

void _3_arraySort(double *array, int size) {
    _3_abstractArraySort(array, size);
}

int main() {
    cout << "-----------------------------------\n";
    cout << "2) ";
    _2_findOddMax(11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10); //нечетные позиции с учетом нулевого индекса
    cout << "-----------------------------------\n";
    cout << "3) ";
    int size = intInput("Размер массива: ");

    cout << "Int: \n";
    int *intArray = new int[size];
    fillRandom(intArray, size);
    _3_arraySort(intArray, size);
    printArray(intArray, size);

    cout << "Char: \n";
    char *charArray = new char[size];
    fillRandom(charArray, size);
    _3_arraySort(charArray, size);
    printArray(charArray, size);

    cout << "Double: \n";
    double *doubleArray = new double[size];
    fillRandom(doubleArray, size);
    _3_arraySort(doubleArray, size);
    printArray(doubleArray, size);
    cout << "-----------------------------------\n";
    cout << "4) ";

}