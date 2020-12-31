#include <iostream>
#include <set>

#define STR_LENGTH 50

using namespace std;

int intInput(const string &str) {
    int value;
    cout << str;
    cin >> value;
    return value;
}

FILE *openFile(const char *path, const char *mode) {
    FILE *file = fopen(path, mode);
    if (file == nullptr) {
        cout << "\nCannot open file!\n";
        exit(1);
    }
    return file;
}

int main() {
    const char *srcPath = "lab9src.txt";
    const char *trgPath = "trg.txt";
    char buffer[STR_LENGTH];

    //Копирование с N по K строку
    FILE *srcFile = openFile(srcPath, "rt");
    FILE *trgFile = openFile(trgPath, "wt");
    int n = intInput("С: ");
    int k = intInput("По: ");
    int currentLine = 0;
    while (fgets(buffer, STR_LENGTH, srcFile)) {
        if (++currentLine >= n && currentLine <= k) {
            fputs(buffer, trgFile);
        }
    }
    fclose(srcFile);
    fclose(trgFile);

    //Подсчет гласных
    set<char> vowels = {'A', 'a', 'E', 'e', 'I', 'i', 'Y', 'y', 'U', 'u', 'O', 'o'};
    int vowelCount = 0;
    trgFile = openFile(trgPath, "rt");
    while (fgets(buffer, STR_LENGTH, trgFile)) {
        for (auto &symb:buffer) {
            if (vowels.contains(symb)) {
                vowelCount++;
            }
        }
    }
    cout << "Количество гласных: " << vowelCount;
}








