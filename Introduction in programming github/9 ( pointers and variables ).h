#pragma once
#include<iostream>
#include<cstring>
#pragma  warning(disable:4996)

//1.Да се напише функция, която приема такъв стринг и връща нов стринг с ТОЧНА ГОЛЕМИНА, в който всички цифри са цензурирани. (Всяко число е заменено с '*')

int length(const char* str) 
{
	int index = 0;
	while (str[index] != '\0') 
	{
		index++;
	}
	return index;
}

bool isdigit(char* str)
{
	int len = length(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= 9) 
		{
			return str[i] - '0';
		}
	}
	return false;
}

char* censored(char* str)
{
	int len = length(str);
	for (int i = 0; i < len; i++) 
	{
		if (isdigit(str[i])) {
			str[i] = '*';
		}
	}
	return str;

}

//2.Да се напише функция, която приема стринг и връща два стринга с ТОЧНА големина.Първият да бъде съставен само от малките букви,
//а другият да бъде съставен само от главните букви.

void twoStrings(const char* str, char* lowercase, char* uppercase) 
{
	int lowerIndex = 0;
	int upperIndex = 0;

	for (int i = 0; i < strlen(str); i++) 
	{
		if (str[i] >= 'A' && str[i] <= 'Z') 
		{
			uppercase[upperIndex++] = str[i];
		}

		else if (str[i] >= 'a' && str[i] <= 'z') 
		{
			lowercase[lowerIndex++] = str[i];
		}
	}
	lowercase[lowerIndex] = '\0';
	uppercase[upperIndex] = '\0';
}

//3.Да се напише функция, която приема два сортирани масива от цели числа и поставя в първия масив елементите от 
//двата масива, но в сортиран вид(приемаме, че в първия има достатъчно място).

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sortArray(int arr[], int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}

}

void mergeTwoSortedArrays(int arr1[], int arr2[], int size1, int size2) 
{

	int size = size1 + size2;
	int arr3[50];

	for (int i = 0; i < size1; i++)
	{
		arr3[i] = arr1[i];
	}
	for (int i = 0; i < size2; i++)
	{
		arr3[size1 + i] = arr2[i];
	}

	sortArray(arr3, size);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr3[i] << " ";
	}

}

//4.Да се напише функция, която приема стринг и връща нов стринг, който е съставен от малките латински букви на подадения, но в сортиран вид.

void  swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}


void sortArrayChar(char  arr[], int size)
{

	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = i + 1; j < size; j++) 
		{
			if (arr[i] > arr[j]) 
			{
				swap(arr[i], arr[j]);
			}
		}
	}

}
void smallLetters(char arr[]) 
{

	char arr2[50] = { 0 };
	int index = 0;

	for (int i = 0; i < strlen(arr); i++) 
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr2[index] = arr[i];
			index++;//bc this will be the new size
		}
	}
	sortArrayChar(arr2, index);
	for (int i = 0; i < index; i++)
	{
		std::cout << arr2[i] << " ";
	}
}

//Задача 5 : Напишете функция, която приема масив от цели числа и цяло число и елемент на масива.Функцията да преподрежда елементите, така че всички 
//по - малки елементи от подадения да са в ляво от него, а всички по - големи - в дясно. (Забележка : Задачата да се реши с помощта на допълнителен масив
//	- същестува и решение без допълнителна памет(Hoare's partition, Lomuto partition и други), но то не се изисква)
//
//	Вход: [1, 5, 6, 3, 0, -1, 2, 9, 7] , 3 Изход : [1, 0, 2, , -1, 3, 6, 5, 9, 7]
//

//from me

void  arrayLeftRight(int arr[], int size, int el)
{

	int newArr[50] = { 0 };

	int index = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < el)
		{
			newArr[index] = arr[i];
			index++;
		}

	}
	int sec = 0;
	int rhsarr[50] = { 0 };

	for (int i = 0; i < size; i++) 
	{
		if (arr[i] > el) 
		{
			rhsarr[sec] = arr[i];
			sec++;
		}

	}

	int mergerd[50] = { 0 };

	for (int i = 0; i < index; i++) 
	{
		mergerd[i] = newArr[i];

	}
	mergerd[index] = el;
	index++;

	for (int i = 0; i < sec; i++)
	{
		mergerd[index + i] = rhsarr[i];
	}

	for (int i = 0; i < index + sec; i++)
	{
		std::cout << mergerd[i] << ",";
	}


}

//other solution not from me

//void arrayLeftRight(int arr[], int size, int el) {
//	int newArr[50] = { 0 };
//	int index = 0;
//
//	// Iterate through the array and copy smaller elements to the new array
//	for (int i = 0; i < size; i++) {
//		if (arr[i] < el) {
//			newArr[index] = arr[i];
//			index++;
//		}
//	}
//
//	// Set the given element in its correct position
//	newArr[index] = el;
//	index++;
//
//	// Iterate through the array and copy larger elements to the new array
//	for (int i = 0; i < size; i++) {
//		if (arr[i] > el) {
//			newArr[index] = arr[i];
//			index++;
//		}
//	}
//
//	// Print the rearranged array
//	for (int i = 0; i < size; i++) {
//		std::cout << newArr[i] << " ";
//	}
//}


//Задача 6 : Напишете функция, която приема масив и връща масив от масиви, на който елементите му са всички непразни подмасиви на дадения.
//
//	Вход : [1, 2, 3]
//
//	Изход : [1] , [2], [3], [1, 2], [2, 3], [1, 3], [1, 2, 3]

void print(int arr[], int start, int end)
{
	std::cout << "[";

	for (int i = start; i <= end; i++) 
	{
		std::cout << arr[i];
		if (i < end) {
			std::cout << ",";
		}
	}
	std::cout << "]" << std::endl;
}


void subArray(int arr[], int size) 
{

	for (int start = 0; start < size; start++) 
	{
		for (int end = start; end < size; end++) 
		{
			print(arr, start, end);
		}
	}
}
