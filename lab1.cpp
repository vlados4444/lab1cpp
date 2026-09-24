// task1.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

// Передача массива по ссылке: int (&arr)[10]
void fillArray(int (&arr)[10])
{
    for (auto& x : arr)
        x = std::rand() % 100;   // случайные числа 0..99
}

void printArray(const int (&arr)[10])
{
    for (auto x : arr)           // range-based for + auto
        std::cout << x << " ";
    std::cout << "\n";
}

void swapElements(int (&arr)[10], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void multiplyByTwo(int (&arr)[10])
{
    for (int& x : arr)           // неконстантная ссылка — меняем элементы
        x *= 2;
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int arr[10]{};

    fillArray(arr);
    std::cout << "После fillArray:      ";
    printArray(arr);

    swapElements(arr, 0, 9);
    std::cout << "После swapElements:   ";
    printArray(arr);

    multiplyByTwo(arr);
    std::cout << "После multiplyByTwo:  ";
    printArray(arr);

    return 0;
}