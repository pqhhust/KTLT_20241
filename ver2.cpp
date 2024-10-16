#include <iostream>
#include <cstring>

using namespace std;

#define MAX_NAME_LENGTH_INIT 30
int maxStudents = 50;

int cntStudents = 0;
char **students;

void init() {
    students = new char* [maxStudents];
    for (int i = 0; i < maxStudents; i++) {
        students[i] = nullptr;
    }
}

void mergeSort(char **str, int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    mergeSort(str, l, m);
    mergeSort(str, m, r);
    int i = l;
    int j = m;
    int k = 0;
    char **tmp = new char *[r - l];
    while (i < m || j < r) {
        if (i == m) {
            tmp[k] = str[j];
            j++;
            k++;
        } else if (j == r) {
            tmp[k] = str[i];
            i++;
            k++;
        } else if (strcmp(str[i], str[j]) < 0) {
            tmp[k] = str[i];
            i++;
            k++;
        } else {
            tmp[k] = str[j];
            j++;
            k++;
        }
    }
    for (int x = l; x < r; x++) {
        str[x] = tmp[x - l];
    }
    delete[] tmp;
}

void addStudents() {
    cin >> ws;
    while (true) {
        if (cntStudents == maxStudents) {
            int oldMaxStudents = maxStudents;
            maxStudents += 50;
            char **tmp = new char* [maxStudents];
            for (int i = 0; i < oldMaxStudents; i++) {
                if (students[i] == nullptr) {
                    tmp[i] = nullptr;
                    continue;
                }
                tmp[i] = new char[strlen(students[i]) + 1];
                strcpy(tmp[i], students[i]);
            }
            for (int i = 0; i < oldMaxStudents; i++) {
                delete[] students[i];
            }
            delete[] students;
            students = tmp;
        }

        int length = 0;
        int bufferSize = 30;
        char* bufferName = new char[bufferSize];
        while (true) {
            cin.get(bufferName[length]);
            if (bufferName[length] == '\n') {
                bufferName[length] = '\0';
                break;
            }
            length++;
            if (length == bufferSize - 1) {
                bufferSize *= 2;
                char* tmp = new char[bufferSize];
                strcpy(tmp, bufferName);
                delete[] bufferName;
                bufferName = tmp;
            }
        }
        if (length == 0) {
            delete[] bufferName;
            break;
        }
        students[cntStudents] = bufferName;
        cntStudents++;
    }
}

void sortStudents() {
    mergeSort(students, 0, cntStudents);
}

void printStudents() {
    for (int i = 0; i < cntStudents; i++) {
        cout << students[i] << "\n";
    }
}

void menu() {
    while (true) {
        cout << "Hay chon 1 chuc nang\n" << "1. Bo sung sinh vien\n" << "2. Sap xep danh sach sinh vien\n" << "3. In ra danh sach sinh vien\n" << "4. Hoan thanh\n";
        int choice = 0;
        cin >> choice;
        if (choice == 1) {
            addStudents();
        } else if (choice == 2) {
            sortStudents();
        } else if (choice == 3) {
            printStudents();
        } else {
            break;
        }
    }
}

int main() {
    init();
    menu();
}