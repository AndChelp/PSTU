#include <iostream>

using namespace std;

int intInput(const string &str) {
    int value;
    cout << str;
    cin >> value;
    return value;
}

void fillRandom(int *array, int &size) {
    int seed = intInput("Seed: ");
    srand(seed);
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100 + 1;
    }
}

void deleteItem(int *array, int &size, int &delIndex) {
    size--;
    for (int i = delIndex; i < size; ++i) {
        array[i] = array[i + 1];
    }
}

void printArray(int *array, int &size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << "\t";
    }
    cout << "\n";
}

void addItem(int *array, int &size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] % 2 == 0) {
            int item = array[i - 1] + 2;
            for (int k = ++size; k > i; --k) {
                array[k] = array[k - 1];
            }
            array[i + 1] = item;
            break;
        }
    }

}

int main() {
    int size = intInput("Размер массива: ");
    int *rndArray = new int[size];
    fillRandom(rndArray, size);
    printArray(rndArray, size);
    int delIndex = intInput("Номер элемента массива для удаления: ") - 1;
    deleteItem(rndArray, size, delIndex);
    addItem(rndArray, size);
    printArray(rndArray, size);
}
