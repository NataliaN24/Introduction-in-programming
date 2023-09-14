#pragma once
#include<iostream>


//Задача 1: Да се напише функция, която приема масив и връща дали е палиндром.
//
//Вход : [1 2 3 2 1] , Изход : true

bool isPalindrome(const int arr[], int size) // first solution
{
	int flag = 0;
	for (int i = 0; i <= size / 2 && size != 0; i++) 
	{
		if (arr[i] != arr[size - i - 1]) 
		{
			flag = 1;
			break;
		}

	}
	if (flag == 1)
	{
		return false;
	}
	else
	{
		return true;
	}

}


bool ispalindrome2(int arr[], int size) { // seond solution



	for (int i = 0; i <= size / 2; i++) 
	{
		if (arr[i] != arr[size - i - 1]) 
		{
			return false;
		}
	}
	return true;

}

//Задача 2 Да се напише функция, която приема масив и връща най - малкото общо кратно на числата в масива.
//
//Вход : [9 18 6 12] , Изход : 36


////////////////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//Задача 3 Да се напише функция, която приема масив и връща най - големият общ делител на числата в масива.
//
//Вход : [9 18 6 12] , Изход : 3

int gcd(int a, int b)
{
	while (b != 0)
	{
		int reaminder = a % b;
		a = b;
		b = reaminder;
	}
	return a;
}
int gcsInArray(int arr[], int size) 
{

	int result = arr[0];

	for (int i = 1; i < size; i++) 
	{
		result = gcd(arr[i], result);
	}
	return result;
}

//Задача 4 : Да се напише функция, която приема масив и връща дали е конкатенация на два масива, които са палиндроми.
//
//Вход : [1 2 3 2 1 4 5 5 4] , Изход : true
//
//Вход : [1 2 3 4 5] , Изход : false
//
//Вход : [1 2 3 2 1] , Изход : true

int isConcatPalindrome(int arr[], const int size)
{

	int temp[10];
	int secondtemp[10];

	for (int i = 0; i <= size / 2; i++) {
		temp[i] = arr[i];
	}
	for (int i = size / 2 + 1; i <= size - 1; i++) {
		secondtemp[i] = arr[i];
	}
	if (ispalindrome2(temp, 10 / 2) && ispalindrome2(secondtemp, 10 / 2)) {
		return true;
	}
	else {
		return false;
	}

}


//Задача 5 : Въвежда се число N(N <= 1000) и N цели числа(елементи на масив).Да се отпечатат броя на инверсиите в масива.
//
//Инверсия ще наричаме двойка индекси(i, j), където i < j и arr[i] > arr[j]
//
//Вход : 6 5 4 3 2 10 Изход : 15 //в масива [5 4 3 2 1 0] има 15 инверсии.
//
//Вход : 5 10 11 12 13 14 15, Изход : 0


int inverseCounter(int arr[], int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				counter++;
			}
		}
	}
	return counter;
}


//Задача 6 : От даден масив от сортирани последнователни числа са премахнати някои числа.Напишете фунцкия,
//  която приема такъв масив и връща най - малкото премахнато число.
//
//Решението ви трябва да работи с логартмична сложност(а не с линейно минаване през масива).
//
//Вход : [5 6 7 9 10 12 13] , Изход : 8 //премахнатите числа са 8 и 11.
//
//Вход : [10 12 13 14 16] , Изход : 11 //премахнатите числа са 11 и 16.
//
//Модифицирайте функцията, за да отпечатване и най - голямото премахнато число


int theSmallestEreasedNumber(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		bool found = false;
		for (int j = 0; j < size; j++) 
		{

			if (arr[j] == arr[i] + 1) 
			{
				found = true;
				break;
			}
		}
		if (!found) 
		{
			return arr[i] + 1;
		}
	}
	return -1;

}

//int theLargestErasedNumber(int arr[], int size) {
//	for (int i = size - 1; i >= 0; i--) {
//		bool found = false;
//		for (int j = i - 1; j >= 0; j--) {
//			if (arr[j] == arr[i + 1]) {
//				found = true;
//				break;
//			}
//
//		}
//		if (!found) {
//			return arr[i] + 1;
//		}
//	}
//	return -1;
//
//}

int theLargestErasedNumber(int arr[], int size) 
{
	int maxErased = arr[0];
	for (int i = 1; i < size; i++)
	{
		bool found = false;
		for (int j = 0; j < size; j++) 
		{
			if (arr[j] == arr[i] - 1)
			{
				found = true;
				break;
			}
		}
		if (!found) 
		{
			maxErased = arr[i];
		}
	}
	return maxErased - 1;
}
