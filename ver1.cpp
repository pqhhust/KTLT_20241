#include <iostream>
#include <cstring>

using namespace std;

#define MAX_NAME_LENGTH 30
#define MAX_STUDENTS 300

int cntStudents = 0;
char **students;

void init() {
    students = new char* [MAX_STUDENTS];
    char *tmp = new char[MAX_STUDENTS * (MAX_NAME_LENGTH + 1)];
    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i] = tmp;
        tmp += MAX_NAME_LENGTH + 1;
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
        if (cntStudents == MAX_STUDENTS) {
            cout << "Da du sinh vien\n";
            break;
        }
        char *tmp = new char[MAX_NAME_LENGTH + 1];
        cin.getline(tmp, MAX_NAME_LENGTH + 1);
        if (*tmp == '\0') {
            break;
        }
        students[cntStudents] = tmp;
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