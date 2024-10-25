#include <iostream>

bool searchIn2DArray(int** arr, int rows, int cols, int target, int row, int col) {
    // Условие выхода из рекурсии: если мы вышли за пределы массива
    if (row >= rows) return false; // Прервем рекурсию, если все строки проверены
    if (col >= cols) return searchIn2DArray(arr, rows, cols, target, row + 1, 0); // Переходим к следующей строке

    // Проверяем текущий элемент
    if (arr[row][col] == target) {
        std::cout << "Элемент найден на индексе: [" << row << "][" << col << "]" << std::endl;
        return true;
    }

    // Рекурсивный вызов для следующего столбца
    return searchIn2DArray(arr, rows, cols, target, row, col + 1);
}

int main() {
    int rows = 3, cols = 3;
    // Создаем пример двумерного массива
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j + 1; // Заполняем массив числами 1-9
        }
    }

    int target;
    std::cout << "Введите число для поиска в массиве: ";
    std::cin >> target;

    if (!searchIn2DArray(arr, rows, cols, target, 0, 0)) {
        std::cout << "Элемент не найден." << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

//Объяснение:
//Функция принимает двумерный массив, количество строк и столбцов, цель для поиска, а также текущие индексы строки и столбца.
//Рекурсивный вызов происходит по столбцам, и если достигается конец строки, функция переключается на следующую строку.