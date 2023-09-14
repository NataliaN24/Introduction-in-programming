#pragma once
#include <iostream>

//Задача 1: Да се реализира рекурсивна функция, която пресмята n!

int factoriel(int n)
{
	if (n < 0) 
	{
		return -1;
	}
	if (n == 0)
	{
		return 1;
	}
	return n * (factoriel(n - 1));

}

//Задача 2 : Да се реализира рекурсивна функция, която пресмята n - тото число на фибоначи.

int fibonacci(int n)
{
	if (n == 0 || n == 1) 
	{
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}


//Задача 3 : Да се реализира рекурсивна функция, която вдига число на дадена степен.

int power(int n, int k)
{
	if (k == 0) 
	{
		return 1;
	}
	else if (k % 2 == 1)
	{
		return n * power(n * n, k / 2);
	}
	else
	{
		return power(n * n, k / 2);
	}


}

//or
int power(int n, int k)
{
	if (k == 0)
		return 1;
	return n * power(n, k - 1);
}


//Задача 4 : Да се реализира рекурсивна функция, която приема масив от цели числа и връща сумата на елементите в него.
int sumArray(const int* arr, int size) 
{
	if (size == 0) 
	{
		return 0;
	}
	return arr[0] + sumArray(arr + 1, size - 1);
}


//Задача 5 : Да се реализира рекурсивна функция, която приема произволен масив и число и връща дали числото се съдържа в масива. (Линейно търсене).
bool linearSearch(const int* arr, size_t size, int searched)
{
	if (size == 0)
		return false;
	return arr[0] == searched || linearSearch(arr + 1, size - 1, searched);
}

//Задача 6 : Да се реализира рекурсивна функция, която приема сортиран масив и число и връща дали числото се съдържа в масива. (Двоично търсене).

bool binarySearch(const int* arr, size_t size, int searched)
{
	if (size == 0)
		return false;

	int mid = size / 2;
	if (arr[mid] == searched)
		return true;
	if (arr[mid] > searched)
		return binarySearch(arr, mid, searched);
	else
		return binarySearch(arr + mid + 1, size - mid - 1, searched);
}
//Задача 7 : Да се реализира рекурсивна функция, която приема стринг и връща дали стрингът е палиндром.
//
//Задача 8 : Да се реализира рекурсивна функция, която стринг и връща броя на малките и големите символи в него.

bool isCapital(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

void getLowerAndUpperCount(const char* str, int& lowerCount, int& capitalCount)
{
	if (*str == '\0')
	{
		lowerCount = capitalCount = 0;
		return;
	}

	getLowerAndUpperCount(str + 1, lowerCount, capitalCount);

	if (isCapital(str[0]))
		capitalCount++;
	else if (isLower(str[0]))
		lowerCount++;
}
