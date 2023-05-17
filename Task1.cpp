#include <iostream>
#include <iomanip>
#define N 10
#define M 10

int main()
{
    std::setlocale(LC_ALL, "ua");
    int n, m, a, b;
    int MatrixA[N][M], MatrixB[N][M];

    std::cout << "Введіть кількість рядків матриці: ";
    std::cin >> n;
    std::cout << "Введіть кількість стовпців матриці: ";
    std::cin >> m;

    if (std::cin.fail() || n != m ||  m > M)
    {
        std::cout << "\nНеправильне значення! Кількість рядків та стовпців повинна збігатися та бути цілим числом, не більшим за 10";
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

    std::cout << "Матриця A:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            MatrixA[i][j] = rand() % (b - a + 1) + a;
            std::cout << std::setw(6) << MatrixA[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Матриця B:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            MatrixB[i][j] = MatrixA[i][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        MatrixB[j][m-1] = MatrixA[0][j] + MatrixA[n-1][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(6) << MatrixB[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}