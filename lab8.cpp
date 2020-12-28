#include <iostream>
#include <utility>

#define SUBJ_COUNT 4

using namespace std;

struct Grade {
    char lessonName[30];
    short gradeValue;
};

struct Schoolkid {
    char fio[30]{};
    char classNumber[3]{};
    char phoneNumber[11]{};
    Grade subjectGrades[SUBJ_COUNT] = {"Математика", NULL, "Физика", NULL, "Русский язык", NULL, "Литература", NULL};
};

template<class T>
void input(T &value, const char *strOutput) {
    cout << strOutput << ": ";
    while(!(cin >> value)){
        cout << "Incorrect value!\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

Schoolkid *inputSchoolkid() {
    auto *kid = new Schoolkid();
    input(kid->fio, "ФИО");
    input(kid->classNumber, "Класс");
    input(kid->phoneNumber, "Номер телефона");
    for (auto &grade : kid->subjectGrades) {
        input(grade.gradeValue, grade.lessonName);
    }
    return kid;
}

FILE *openFile(const char *path, const char *mode) {
    FILE *file = fopen(path, mode);
    if (file == nullptr) {
        cout << "\nCannot open file!\n";
        exit(1);
    }
    return file;
}

bool checkKid(Schoolkid kid) {
    for (auto g:kid.subjectGrades) {
        if (g.gradeValue == 2) {
            return false;
        }
    }
    return true;
}

void printFile(const char *path) {
    FILE *fPointer = openFile(path, "rt");
    auto *kidBuffer = new Schoolkid();
    while (fread(kidBuffer, sizeof(Schoolkid), 1, fPointer) > 0) {
        cout << "ФИО: " << kidBuffer->fio << "\n";
        cout << "Класс: " << kidBuffer->classNumber << "\n";
        cout << "Номер телефона: " << kidBuffer->phoneNumber << "\n";
        for (auto &grade : kidBuffer->subjectGrades) {
            cout << grade.lessonName << ": " << grade.gradeValue << "\n";
        }
        cout << "----------------------\n";
    }
    fclose(fPointer);
}

void saveData(const char *path) {
    int count;
    input(count, "Количество записей");
    FILE *fPointer = openFile(path, "wt");
    for (int i = 0; i < count; ++i) {
        fwrite(inputSchoolkid(), sizeof(Schoolkid), 1, fPointer);
        cout << "----------------------\n";
    }
    fclose(fPointer);
}

void deleteData(const char *src) {
    FILE *srcFile = openFile(src, "rt");
    FILE *tmpFile = openFile("tmp.txt", "wt");
    auto *kidBuffer = new Schoolkid();
    while (fread(kidBuffer, sizeof(Schoolkid), 1, srcFile) > 0) {
        //Копируем, елси проходит проверку
        if (checkKid(*kidBuffer)) {
            fwrite(kidBuffer, sizeof(Schoolkid), 1, tmpFile);
        }
    }
    fclose(srcFile);
    fclose(tmpFile);
    tmpFile = openFile("tmp.txt", "rt");
    srcFile = openFile(src, "wt");
    //Копирование в исходный файл
    while (fread(kidBuffer, sizeof(Schoolkid), 1, tmpFile) > 0) {
        fwrite(kidBuffer, sizeof(Schoolkid), 1, srcFile);
    }
    fclose(srcFile);
    fclose(tmpFile);
    remove("tmp.txt");
}

void pushData(const char *src) {
    FILE *srcFile = openFile(src, "rt");
    FILE *tmpFile = openFile("tmp.txt", "wt");
    auto *kidBuffer = inputSchoolkid();
    //Добавление новой записи в начало файла
    fwrite(kidBuffer, sizeof(Schoolkid), 1, tmpFile);
    //Добавление остальных записей
    while (fread(kidBuffer, sizeof(Schoolkid), 1, srcFile) > 0) {
        fwrite(kidBuffer, sizeof(Schoolkid), 1, tmpFile);
    }
    fclose(srcFile);
    fclose(tmpFile);

    tmpFile = openFile("tmp.txt", "rt");
    srcFile = openFile(src, "wt");
    //Копирование в исходный файл
    while (fread(kidBuffer, sizeof(Schoolkid), 1, tmpFile) > 0) {
        fwrite(kidBuffer, sizeof(Schoolkid), 1, srcFile);
    }
    fclose(srcFile);
    fclose(tmpFile);
    remove("tmp.txt");
}

int main() {
    const char *srcPath = "src.txt";
    saveData(srcPath);
    cout << "\nИсходные данные:\n\n";
    printFile(srcPath);
    deleteData(srcPath);
    cout << "\nПосле удаления:\n\n";
    printFile(srcPath);
    cout << "\nНовыя запись:\n\n";
    pushData(srcPath);
    cout << "\nПосле добавления:\n\n";
    printFile(srcPath);
}