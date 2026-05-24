#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Разделение массива относительно опорного элемента.
// Возвращает индекс опорного элемента после разделения.
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // опорный элемент
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Рекурсивная быстрая сортировка.
// arr --- сортируемый массив, low --- левая граница, high --- правая граница.
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5, 77, 43};

    std::cout << "До сортировки: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "После сортировки: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Время выполнения: " << duration.count() << " мкс\n";

    return 0;
}
