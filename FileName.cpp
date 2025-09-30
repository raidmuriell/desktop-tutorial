#include <iostream>
#include <string>
using namespace std;

const int N = 10; // размер массива


void shiftArray(int k, bool left) {
    int arr[N] = { 0,1,2,3,4,5,6,7,8,9 };
    k %= N;
    for (int i = 0; i < N; i++) {
        int idx = left ? (i + k) % N : (i - k + N) % N;
        cout << arr[idx] << " ";
    }
    cout << endl;
}

// куб — выводит массив построчно со сдвигами
void printCube(bool left) {
    for (int row = 0; row < N; row++) {
        shiftArray(row, left);
    }
}

void toBinary(int num) {
    if (num == 0) { cout << "0" << endl; return; }
    string res;
    while (num) { res = char('0' + num % 2) + res; num /= 2; }
    cout << res << endl;
}

void toHex(int num) {
    if (num == 0) { cout << "0" << endl; return; }
    string res;
    const char* d = "0123456789ABCDEF";
    while (num) { res = d[num % 16] + res; num /= 16; }
    cout << res << endl;
}

int main() {
    int choice, k, num;
    cout << "Меню:\n"
        << "1 - Сдвиг массива влево\n"
        << "2 - Сдвиг массива вправо\n"
        << "3 - Куб (сдвиг влево)\n"
        << "4 - Куб (сдвиг вправо)\n"
        << "5 - Десятичное -> Двоичное\n"
        << "6 - Десятичное -> Шестнадцатеричное\n"
        << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1: cout << "Введите количество сдвигов: "; cin >> k; shiftArray(k, true); break;
    case 2: cout << "Введите количество сдвигов: "; cin >> k; shiftArray(k, false); break;
    case 3: printCube(true); break;
    case 4: printCube(false); break;
    case 5: cout << "Введите число: "; cin >> num; toBinary(num); break;
    case 6: cout << "Введите число: "; cin >> num; toHex(num); break;
    default: cout << "Неверный выбор!" << endl;
    }
}
