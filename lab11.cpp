#include <iostream>

using namespace std;

struct ListItem {
    int key{};
    ListItem *next{};
    ListItem *prev{};

    explicit ListItem(int key) : key{key} {}

    ListItem() = default;
};

ListItem *listCursor;

ListItem *makeList(int size) {
    ListItem *current = nullptr, *newItem;
    while (size-- > 0) {
        newItem = new (ListItem);
        newItem->key = size;
        newItem->next = current;
        newItem->prev = nullptr;
        current ? current->prev = newItem : nullptr;
        current = newItem;
    }
    return current;
}

void printList(const char *text, ListItem *item) {
    cout << text;
    if (item == nullptr) {
        cout << "Список пуст" << "\n";
        return;
    }
    while (item != nullptr) {
        cout << item->key << " ";
        item = item->next;
    }
    cout << "\n";
}

void deleteList(ListItem *item) {
    while (item->next != nullptr) {
        item = item->next;
        delete item->prev;
    }
    delete item;
    listCursor = nullptr;
}

void removeAt(ListItem *item, int index) {
    for (int i = 0; i < index; ++i) {
        item = item->next;
    }
    if (item->prev != nullptr) {
        item->prev->next = item->next;
    } else {
        listCursor = listCursor->next;
    }
    if (item->next != nullptr) {
        item->next->prev = item->prev;
    }
    delete item;
}

void addFirst(ListItem *item) {
    listCursor->prev = item;
    item->next = listCursor;
    listCursor = item;
}

void saveToFile(ListItem *item) {
    FILE *file = fopen("file.txt", "wt");
    while (item != nullptr) {
        fwrite(&item->key, sizeof(int), 1, file);
        item = item->next;
    }
    fclose(file);
}

void restoreFromFile() {
    FILE *file = fopen("file.txt", "rt");
    int a;
    ListItem *current = nullptr, *newItem;

    while (fread(&a, sizeof(int), 1, file) > 0) {
        newItem = new ListItem();
        newItem->key = a;
        newItem->next = nullptr;
        newItem->prev = current;
        current ? current->next = newItem : nullptr;
        current = newItem;
        if (!listCursor) {
            listCursor = newItem;
        }
    }
    fclose(file);
}

int main() {
    listCursor = makeList(3);
    printList("Изначальный список: ", listCursor);
    removeAt(listCursor, 1);
    printList("Удаление по индексу: ", listCursor);
    addFirst(new ListItem(listCursor->key - 1));
    printList("Добавление в начало: ", listCursor);
    saveToFile(listCursor);
    deleteList(listCursor);
    printList("Полное очищение списка: ", listCursor);
    restoreFromFile();
    printList("Восстановленный список: ", listCursor);
    deleteList(listCursor);
}
