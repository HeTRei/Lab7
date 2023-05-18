#include <iostream>
#include <iomanip>
int main()
{
    std::setlocale(LC_ALL, "ua");
    int n, m, a, b;
    srand(time(nullptr));

    std::cout << "Введіть кількість рядків матриці: ";
    std::cin >> n;
    std::cout << "Введіть кількість стовпців матриці: ";
    std::cin >> m;

    if (std::cin.fail())
    {
        std::cout << "\nНеправильне значення!";
        return 1;
    }

    std::cout << "Введіть мінімальне значення для генерації чисел: ";
    std::cin >> a;
    std::cout <<"Введіть максимальне значення для генерації чисел: ";
    std::cin >> b;
    if (std::cin.fail() || a > b)
    {
        std::cout << "\nНеправильне значення, або число а більше числа b";
        return 2;
    }
    int **MatrixA = new int *[n];
    for (int i = 0; i < n; i++)
    {
        MatrixA[i] = new int [m];
    }
    std::cout << "Матриця А:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            MatrixA[i][j] = rand() % (b - a + 1) + a;
            std::cout << std::setw(6) << MatrixA[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] MatrixA[i];
    }
    delete[] MatrixA;
    return 0;
}