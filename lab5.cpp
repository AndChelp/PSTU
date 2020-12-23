#include <iostream>

#define _Y 5
#define _X 5

//сокращения для определения к какой оси массива применять цикл
#define _X_or_Y_ isX ? _X : _Y
#define _XorY isX ? i : a
#define _YorX isX ? a : i

using namespace std;

int intInput(const string &str) {
    int value;
    cout << str;
    cin >> value;
    return value;
}

void fillRandom(int (&array)[_X][_Y]) {
    int seed = intInput("Seed: ");
    srand(seed);
    for (auto &i : array) {
        for (int &k : i) {
            k = rand() % 100 + 1;
        }
    }
}

void fillStatic(int (&targetArray)[_X][_Y]) {
    int sourceArray[_X][_Y] = {
            {1, 2, 5, 4, 3},
            {0, 1, 6, 1, 2},
            {6, 9, 7, 3, 2},
            {9, 6, 8, 5, 7},
            {1, 6, 9, 2, 4}
    }; // седловые точки: x=2, y=0; x=3, y=3
    for (int i = 0; i < _X; i++) {
        for (int j = 0; j < _Y; j++) {
            targetArray[j][i] = sourceArray[i][j];
        }
    }
}

void printArray(int (&array)[_X][_Y]) {
    cout << "\n";
    for (int i = 0; i < _Y; ++i) {
        for (int j = 0; j < _X; ++j) {
            cout << array[j][i] << "\t";
        }
        cout << "\n";
    }
}

/*универсальная функция поиска минимума или максимума по оси X или Y
isMin==true => ищет минимум, isX==true => ищет по X*/
int abstractMinOrMax(int (&array)[_X][_Y], int a, bool isMin, bool isX) {
    int result = 0, i = 0, item = array[_XorY][_YorX];
    for (; i < (_X_or_Y_); ++i) {
        int current = array[_XorY][_YorX];
        if (isMin && current < item || !isMin && current > item) {
            item = current;
            result = i;
        }
    }
    return result;
}

int findMinX(int (&array)[_X][_Y], int y) {
    return abstractMinOrMax(array, y, true, true);
}

int findMaxX(int (&array)[_X][_Y], int y) {
    return abstractMinOrMax(array, y, false, true);
}

int findMinY(int (&array)[_X][_Y], int x) {
    return abstractMinOrMax(array, x, true, false);
}

int findMaxY(int (&array)[_X][_Y], int x) {
    return abstractMinOrMax(array, x, false, false);
}

void findSaddlePoint(int (&array)[_X][_Y]) {
    for (int i = 0; i < _Y; ++i) {
        //Поиск седловой точки минимум в строке, максимум в столбце
        int minX = findMinX(array, i);
        int maxY = findMaxY(array, minX);
        //Поиск седловой точки минимум в стобце, максимум в строке
        int maxX = findMaxX(array, i);
        int minY = findMinY(array, maxX);

        if (maxY == i) {
            cout << "x=" << minX << " y=" << maxY << "\n";
        }
        if (minY == i) {
            cout << "x=" << maxX << " y=" << minY << "\n";
        }
    }
}

int main() {
    int array[_X][_Y];
    fillStatic(array);
    //fillRandom(array);
    printArray(array);
    findSaddlePoint(array);
}
