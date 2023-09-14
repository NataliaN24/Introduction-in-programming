#pragma once
#include<iostream>
using namespace std;
//Задача 1: Напишете функция, която приема матрица NxN и транспонира матрицата.

void transposedMatrix(int matrix[][50], const int size)
{

    int transposedmatrix[50][50];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            transposedmatrix[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            std::cout << transposedmatrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

//Задача 2 : Напишете функция, която приема матрица NxN и проверява дали релацията, която представлява матрицата, е релация на еквивалентност.

//Задача 3 : Напишете функция, която приема матрица NxM и матрица MxK и умножава първата матрица по втората.

void multiplyMatrices(int matrix1[][50], int matrix2[][50], int n, int m, int k) 
{
    int result[50][50] = { 0 };  

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            for (int l = 0; l < m; l++) 
            {
                result[i][j] += matrix1[i][l] * matrix2[l][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++) 
        {
            std::cout << result[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

//Задача 4 : Напишете функция, която приема матрица NxN и връща обратната матрица(ако дадената е обратима).Ако матрицата не 
// е обратима, да се отпечата подходящо съобщение.
//(the solution is not mine)
// Function to calculate the determinant of a matrix

double determinant(double** matrix, int n) {
    // Base case for 2x2 matrix
    if (n == 2) 
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;

    // Calculate the determinant using cofactor expansion
    for (int col = 0; col < n; col++) 
    {
        double** submatrix = new double* [n - 1];

        for (int i = 0; i < n - 1; i++) 
        {
            submatrix[i] = new double[n - 1];
        }

        for (int i = 1; i < n; i++)
        {
            int subCol = 0;
            for (int j = 0; j < n; j++) 
            {
                if (j != col)
                {
                    submatrix[i - 1][subCol++] = matrix[i][j];
                }
            }
        }

        double sign = (col % 2 == 0) ? 1.0 : -1.0;
        det += sign * matrix[0][col] * determinant(submatrix, n - 1);

        for (int i = 0; i < n - 1; i++) 
        {
            delete[] submatrix[i];
        }
        delete[] submatrix;
    }

    return det;
}

// Function to calculate the cofactor matrix
void cofactor(double** matrix, int n, double** cofactorMatrix) 
{
    for (int row = 0; row < n; row++) 
    {
        for (int col = 0; col < n; col++)
        {
            double** submatrix = new double* [n - 1];

            for (int i = 0; i < n - 1; i++)
            {
                submatrix[i] = new double[n - 1];
            }

            int subRow = 0;
            for (int i = 0; i < n; i++) 
            {
                if (i != row) 
                {
                    int subCol = 0;
                    for (int j = 0; j < n; j++)
                    {
                        if (j != col)
                        {
                            submatrix[subRow][subCol++] = matrix[i][j];
                        }
                    }
                    subRow++;
                }
            }

            double sign = ((row + col) % 2 == 0) ? 1.0 : -1.0;
            cofactorMatrix[col][row] = sign * determinant(submatrix, n - 1);

            for (int i = 0; i < n - 1; i++) 
            {
                delete[] submatrix[i];
            }
            delete[] submatrix;
        }
    }
}

// Function to calculate the inverse of a matrix
void inverse(double** matrix, int n) 
{
    double det = determinant(matrix, n);

    if (det == 0)
    {
        cout << "The matrix is not invertible." << endl;
        return;
    }

    double** cofactorMatrix = new double* [n];

    for (int i = 0; i < n; i++) 
    {
        cofactorMatrix[i] = new double[n];
    }

    cofactor(matrix, n, cofactorMatrix);

    cout << "The inverse of the matrix is:" << endl;

    for (int row = 0; row < n; row++) 
    {
        for (int col = 0; col < n; col++)
        {
            double inverseValue = cofactorMatrix[row][col] / det;
            cout << inverseValue << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) 
    {
        delete[] cofactorMatrix[i];
    }
    delete[] cofactorMatrix;
}

 //...........................................................................................................................
 
//Задача 5 : Напишете функция, която приема матрица NxN + 1 и решава системата от линейни уравнения, репрезентирана в матрицата.
//
//Вход :
//
//	3 2 5 0
//
//	2 - 3 4 10
//
//	2 1 1 4
//
//	Изход: 4, -11.14, -12.85
//
//	Тук се решава системата :
//
//-3x + 2y - 5z = 0
//
//2x - 3y + 4z = 10
//
//2x + y + z = 4
//
//Тя има решение : x = 14, y = -78 / 4 (-11.14), z = -90 / 7 (-12.85).
//
//Важно!
//
//Програмата трябва да засича, ако системата няма решение или има безкраен брой решения и да отпечата подходящо съобщение в този случай.

// ......................................................................................................................................


//int** multiplyMatrices(int matrix1[][50], int matrix2[][50], int n, int m, int k) {
//    int** result = new int* [n];  // Dynamic allocation of result matrix
//
//    for (int i = 0; i < n; i++) {
//        result[i] = new int[k];
//        for (int j = 0; j < k; j++) {
//            result[i][j] = 0;  // Initialize result matrix with zeros
//            for (int l = 0; l < m; l++) {
//                result[i][j] += matrix1[i][l] * matrix2[l][j];
//            }
//        }
//    }
//
//    return result;
//}
//
//void deallocateMatrix(int** matrix, int n) {
//    for (int i = 0; i < n; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}
//
//int main() {
//    int n, m, k;
//    std::cin >> n >> m >> k;
//
//    int matrix1[50][50];
//    int matrix2[50][50];
//
//    // Input the elements of matrix1
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            std::cin >> matrix1[i][j];
//        }
//    }
//
//    // Input the elements of matrix2
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < k; j++) {
//            std::cin >> matrix2[i][j];
//        }
//    }
//
//    int** result = multiplyMatrices(matrix1, matrix2, n, m, k);
//
//    // Print the resulting matrix
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < k; j++) {
//            std::cout << result[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }
//
//    // Deallocate the memory used by the resulting matrix
//    deallocateMatrix(result, n);
//
//    return 0;
//}