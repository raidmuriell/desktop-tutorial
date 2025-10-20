#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    const int ROWS = 4, COLS = 5;
    const int SIZE = ROWS * COLS;
    int arr[ROWS][COLS];

    // 1. Заполняем массив случайными числами 
    cout << "Исходный массив:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 16;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    // 2. Находим минимум и максимум
    int minVal = arr[0][0], maxVal = arr[0][0];
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            minVal = min(minVal, arr[i][j]);
            maxVal = max(maxVal, arr[i][j]);
        }

    cout << "\nМинимум: " << minVal << "\nМаксимум: " << maxVal << "\n";

    // 3. Циклический сдвиг вправо на k элементов
    int k = 3;
    vector<int> flat;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            flat.push_back(arr[i][j]);

    k %= SIZE;
    rotate(flat.rbegin(), flat.rbegin() + k, flat.rend());

    int idx = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = flat[idx++];

    cout << "\nПосле сдвига на " << k << " вправо:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    // 4. Сортировка
    sort(flat.begin(), flat.end());
    idx = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = flat[idx++];

    cout << "\nПосле сортировки:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    // 5. Уникальные случайные числа
    vector<int> uniqueNums(SIZE);
    iota(uniqueNums.begin(), uniqueNums.end(), 1);
    random_shuffle(uniqueNums.begin(), uniqueNums.end());

    idx = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = uniqueNums[idx++];

    cout << "\nМассив с уникальными числами:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    // 6. Подсчёт повторов
    map<int, int> freq;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            freq[arr[i][j]]++;

    cout << "\nПовторяющиеся значения:\n";
    bool hasDuplicates = false;
    for (auto& p : freq)
        if (p.second > 1) {
            cout << p.first << " встречается " << p.second << " раза\n";
            hasDuplicates = true;
        }

    if (!hasDuplicates)
        cout << "Повторов нет.\n";

    return 0;
}
