#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    char *fullName;
    char *studentID;
    char *birthday;
    char *studentClass;
    char *faculty;
    Student *next;
};

char* input() {
    cin >> ws;
    int length = 0;
    int bufferSize = 30;
    char* buffer = new char[bufferSize];
    while (true) {
        cin.get(buffer[length]);
        if (buffer[length] == '\n') {
            buffer[length] = '\0';
            break;
        }
        length++;
        if (length == bufferSize - 1) {
            bufferSize *= 2;
            char* tmp = new char[bufferSize];
            strcpy(tmp, buffer);
            delete[] buffer;
            buffer = tmp;
        }
    }
    if (length == 0) {
        delete[] buffer;
        return nullptr;
    }
    return buffer;
}

Student* makeStudent() {
    Student *newStudent = new Student;
    if (newStudent == nullptr) return nullptr;
    cout << "Nhap thong tin sinh vien" << endl;
    cout << "Ho va ten:" << endl;
    newStudent->fullName = input();
    if (newStudent->fullName == nullptr) {
        delete newStudent;
        return nullptr;
    }
    cout << "MSSV:" << endl;
    newStudent->studentID = input();
    if (newStudent->studentID == nullptr) {
        delete[] newStudent->fullName;
        delete newStudent;
        return nullptr;
    }
    cout << "Ngay sinh:" << endl;
    newStudent->birthday = input();
    if (newStudent->birthday == nullptr) {
        delete[] newStudent->fullName;
        delete[] newStudent->studentID;
        delete newStudent;
        return nullptr;
    }
    cout << "Lop:" << endl;
    newStudent->studentClass = input();
    if (newStudent->studentClass == nullptr) {
        delete[] newStudent->fullName;
        delete[] newStudent->studentID;
        delete[] newStudent->birthday;
        delete newStudent;
        return nullptr;
    }
    cout << "Khoa:" << endl;
    newStudent->faculty = input();
    if (newStudent->faculty == nullptr) {
        delete[] newStudent->fullName;
        delete[] newStudent->studentID;
        delete[] newStudent->birthday;
        delete[] newStudent->studentClass;
        delete newStudent;
        return nullptr;
    }
    newStudent->next = nullptr;
    return newStudent;
}

Student* addStudent(Student* headOfStudents) {
    Student* newStudent = makeStudent();
    if (newStudent == nullptr) return headOfStudents;
    if (headOfStudents == nullptr) {
        headOfStudents = newStudent;
        return headOfStudents;
    }
    Student* tmp = headOfStudents;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    } 
    tmp->next = newStudent;
    return headOfStudents;
}

void printStudents(Student* headOfStudents, ostream& out) {
    if (headOfStudents == nullptr) {
        out << "Chua co sinh vien nao trong danh sach\n";
        return;
    }
    Student* tmp = headOfStudents;
    while (tmp != nullptr) {
        out << "Ho va ten: " << tmp->fullName << " MSSV: " << tmp->studentID << " Ngay sinh: " << tmp->birthday << " Lop: " << tmp->studentClass << " Khoa: " << tmp->faculty << "\n";
        tmp = tmp->next;
    }
}

void freeStudents(Student* headOfStudents) {
    while (headOfStudents != nullptr) {
        Student* tmp = headOfStudents;
        headOfStudents = headOfStudents->next;
        delete[] tmp->fullName;
        delete[] tmp->studentID;
        delete[] tmp->birthday;
        delete[] tmp->studentClass;
        delete[] tmp->faculty;
        delete tmp;
    }
}

void menu() {
    Student* headOfStudents = nullptr;
    while (true) {
        cout << "Hay chon 1 chuc nang\n" << "1. Bo sung sinh vien\n" << "2. In ra danh sach sinh vien\n" << "3. Hoan thanh\n";
        int choice = 0;
        cin >> choice;
        if (choice == 1) {
            headOfStudents = addStudent(headOfStudents);
        } else if (choice == 2) {
            printStudents(headOfStudents, cout);
        } else {
            ofstream outFile("students.txt");
            if (outFile.is_open()) {
                printStudents(headOfStudents, outFile);
                outFile.close();
                cout << "Danh sach sinh vien da duoc ghi vao file students.txt\n";
            } else {
                cout << "Khong the mo file de ghi\n";
            }
            break;
        }
    }
    freeStudents(headOfStudents); 
}

int main() {
    menu();
}