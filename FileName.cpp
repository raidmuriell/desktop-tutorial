#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

    const int SIZE = 10;
    int arr[SIZE];

    // Заполнение массива случайными числами 0..10
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 11;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // Подсчёт повторов через map
    std::map<int, int> freq;
    for (int i = 0; i < SIZE; i++) {
        freq[arr[i]]++;
    }

    std::cout << "Повторяющиеся элементы и их количество:\n";
    for (auto& p : freq) {
        if (p.second > 1) {
            std::cout << p.first << " встречается " << p.second << " раз(а)\n";
        }
    }

    return 0;
}
