#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ===================== ЗАВДАННЯ 1 =====================

// власна реалізація rfind
int my_rfind(const char* str, const char* substr) {
    int len = 0, sublen = 0;

    while (str[len] != '\0') len++;
    while (substr[sublen] != '\0') sublen++;

    for (int i = len - sublen; i >= 0; i--) {
        bool found = true;

        for (int j = 0; j < sublen; j++) {
            if (str[i + j] != substr[j]) {
                found = false;
                break;
            }
        }

        if (found) return i;
    }

    return -1;
}

void runTask1() {
    char cstr[100];
    char csubstr[100];

    cin.ignore();
    cout << "Введіть рядок: ";
    cin.getline(cstr, 100);

    cout << "Введіть підрядок: ";
    cin.getline(csubstr, 100);

    string str = cstr;
    string substr = csubstr;

    size_t pos = str.rfind(substr);
    int my_pos = my_rfind(cstr, csubstr);

    cout << "\nstring::rfind: ";
    if (pos != string::npos)
        cout << pos << endl;
    else
        cout << "не знайдено\n";

    cout << "my_rfind: ";
    if (my_pos != -1)
        cout << my_pos << endl;
    else
        cout << "не знайдено\n";
}

// ===================== ЗАВДАННЯ 2 =====================

// A. обробка рядка
string getSubstringBetweenSpaces(const string& str) {
    size_t first = str.find(' ');
    if (first == string::npos) return "";

    size_t second = str.find(' ', first + 1);
    if (second == string::npos) return "";

    return str.substr(first + 1, second - first - 1);
}

// B. перевірка
bool isValid(const string& str) {
    size_t first = str.find(' ');
    if (first == string::npos) return false;

    size_t second = str.find(' ', first + 1);
    return second != string::npos;
}

void runTask2() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open()) {
        cout << "Помилка відкриття input.txt\n";
        return;
    }

    string line;

    while (getline(fin, line)) {
        if (isValid(line))
            fout << getSubstringBetweenSpaces(line) << endl;
        else
            fout << "" << endl;
    }

    fin.close();
    fout.close();

    cout << "Результат записано у output.txt\n";
}

// ===================== МЕНЮ =====================

int main() {
    int choice;

    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Завдання 1 (rfind)\n";
        cout << "2. Завдання 2 (робота з рядками і файлом)\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                runTask1();
                break;
            case 2:
                runTask2();
                break;
            case 0:
                cout << "Вихід...\n";
                break;
            default:
                cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}
