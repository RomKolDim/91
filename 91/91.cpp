#include <iostream>

// Рекурсивная функция для вычисления n-го числа Фибоначчи
int fibonacci(int n) {
    // Базовые случаи: F(0) = 0, F(1) = 1
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Рекурсивный вызов для вычисления F(n)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Введите номер элемента Фибоначчи: ";
    std::cin >> n;
    std::cout << "F(" << n << ") = " << fibonacci(n) << std::endl;
    return 0;
}
