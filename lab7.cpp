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

void _1_defaultParams(const string &surname = "Фамилия", const string &address = "Адрес", short age = 20) {
    cout << surname << ", " << address << ", " << age << "\n";
}

void _2_findOddMax(int n, ...) {
    int *p = &n;
    int pos = 0;
    int max = *(++p);
    for (; n > 0; n--) {
        if (pos++ % 2 != 0 && max < *(p)) {
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

double _4_equation(double x) {
    return 0.25 * pow(x, 3) + x - 1.2502;
}

void _4_solveEquation(double (*eq)(double)) {
    double a = 0, b = 2;
    double e = 1.0001;
    double c;
    do {
        c = (a + b) / 2;
        if (((*eq)(a) * (*eq)(c)) < 0) {
            b = c;
        } else {
            a = c;
        }
    } while (fabs(b - a) > e);

    cout << c;
}


int main() {
    cout << "1)\n";
    cout << "Явные параметры: ";
    _1_defaultParams("ф", "а", 0);
    cout << "Дефолтные параметры: ";
    _1_defaultParams();
    cout << "Частичные параметры: ";
    _1_defaultParams("ф");
    cout << "-----------------------------------\n";
    cout << "2)\n"
         << "Максимальное число на нечетной позиции\n"
         << "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]: ";
    _2_findOddMax(11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    cout << "-----------------------------------\n";
    cout << "3) ";
    int size = intInput("Размер массива: ");

    cout << "Int: \n";
    int *intArray = new int[size];
    fillRandom(intArray, size);
    _3_arraySort(intArray, size);
    printArray(intArray, size);
    delete[] intArray;

    cout << "Char: \n";
    char *charArray = new char[size];
    fillRandom(charArray, size);
    _3_arraySort(charArray, size);
    printArray(charArray, size);
    delete[] charArray;

    cout << "Double: \n";
    double *doubleArray = new double[size];
    fillRandom(doubleArray, size);
    _3_arraySort(doubleArray, size);
    printArray(doubleArray, size);
    delete[] doubleArray;
    cout << "-----------------------------------\n";
    cout << "4)\nКорень уравнения: ";

    _4_solveEquation(&_4_equation);
}