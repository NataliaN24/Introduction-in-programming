#pragma once
#include<iostream>
#include<cstring>
#include <ctime>
#pragma warning(disable:4996)
using namespace std;

//Задача 1: Да се напише програма за следене на резултати на до 10 играчи.Всеки играч има Име(низ с дължина до 1024 символа)
//и точки.За низовете да трябва да бъде заделено точно количество памет.Трябва да поддържате операция за добавяне на
//точки на даден играч по име.След всяко добавяне да се отпечатват играчите сортирани по точките.

//> 3
//> Ivan Ivanov
//> Petur
//> Aleksandur Kadiev
//
//Scores :
//Ivan Ivanov 0
//Petur 0
//Aleksandur Kadiev 0
//
//> Petur
//> 10
//
//Scores:
//Petur 10
//Ivan Ivanov 0
//Aleksandur Kadiev 0
//
//> Petur
//> 3
//Scores:
//Petur 13
//Ivan Ivanov 0
//Aleksandur Kadiev 0
//
//> Alexandur Kadiev
//> 40
//
//Scores:
//Aleksandur Kadiev 40
//Petur 13
//Ivan Ivanov 0

const int MAX_PLAYERS = 10;
const int MAX_NAME_LENGTH = 1024;

void addScores(char names[][MAX_NAME_LENGTH], int points[], int size, const char* playerName, int score)
	{
	for (int i = 0; i < size; i++) 
	{
		if (strcmp(names[i], playerName) == 0)
		{
			points[i] += score;
			return;
		}
	}

	// If the player is not found, print an error message
	std::cout << "Player not found!" << std::endl;
}

void printScores(char names[][MAX_NAME_LENGTH], int points[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		std::cout << names[i] << " " << points[i] << std::endl;
	}
}

//Задача 2 : Въвежда се число N и N x N + 1 цели числа.Да се реши системата от уравнения.Примете, че системата е с ненулеви коефициенти и винаги има решение.
//
//2
//2 6 40
//4 1 14
//
//
//Solution :
//	2 6


double** createMatrix(int n, int m)
{
	double** matrix;
	matrix = new double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[m];
	return matrix;
}

void freeMatrix(double** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void divideBy(double* arr, int size, double value)
{
	for (int i = 0; i < size; i++)
		arr[i] /= value;
}

void substractRows(double* first, double* second, double size, double coef)
{
	for (int i = 0; i < size; i++)
		first[i] -= (second[i] * coef);
}

void makeAllZeros(double** matrix, int n, int row)
{
	for (int i = 0; i < n; i++)
	{
		if (i == row)
			continue;
		substractRows(matrix[i], matrix[row], n + 1, matrix[i][row]);

	}
}

void print(double** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
double* solve(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		divideBy(matrix[i], n + 1, matrix[i][i]);
		makeAllZeros(matrix, n, i);
		//print(matrix, n, n + 1);
	}
	double* result = new double[n];
	for (int i = 0; i < n; i++)
		result[i] = matrix[i][n];
	return result;
}


//Задача 3: Да се напише програма, която приема текст само с латински букви, цифри и интервали.Текстът е с дължина до 2048 символа.
//Програмата да позволява промяна на дума по индекс и цензуриране и разцензуриране на вече цензурирана на дума по индекс.На всяка опрация да се отпечатва текста :
//
//	> Hello my 320 friends how are you
//		> censore
//	> 2
//		Hello my * friends how are you
//	> censore
//	> 4
//		Hello my * friends * are you
//
//		> uncensore
//	> 2
//
//		Hello my 320 friends * are you
//	> change
//	> freinds
//	> enemies
//		Hello my 320 enemies * are you
//		Напишете фунцкия, която приема вашата колекция от думи и връща новосъздадения текст, за който да е заделено точно количество памет.



bool isValid(char ch)
{
	return ch >= 'a' && ch <= 'z' ||
		ch >= 'A' && ch <= 'Z' ||
		ch >= '0' && ch <= '9';
}

unsigned int getWordsCount(const char* text)
{
	unsigned int  count = 0;
	while (*text)
	{
		if (!isValid(*text))
			count++;
		text++;
	}
	return count + 1;
}

size_t getFirstNotValidSymbolIndex(const char* text)
{
	size_t i = 0;
	while (*text && isValid(*text))
	{
		i++;
		text++;
	}
	return i;
}
void fillWordsToArrayOfWords(char** textArr, char* text)
{
	size_t wordIndex = 0;
	bool isLast = false;
	while (1)
	{
		size_t wordEnd = getFirstNotValidSymbolIndex(text);

		if (text[wordEnd] == '\0')
			isLast = true;

		text[wordEnd] = '\0'; //temp for strcpy
		textArr[wordIndex] = new char[wordEnd + 3];
		strcpy(textArr[wordIndex], text);
		text[wordEnd] = ' ';
		text += (wordEnd);
		wordIndex++;

		if (isLast)
			return;
		text++;
	}
}

void printTextFromArray(char** textArr, int wordsCount)
{
	for (int i = 0; i < wordsCount; i++)
	{
		cout << textArr[i] << " ";
	}
	cout << endl;
}

void free(char** words, int count)
{
	for (int i = 0; i < count; i++)
		delete[] words[i];
	delete[] words;
}


void censoreOrDiscensore(char** words, int ind)
{
	if (strcmp(words[ind], "*") == 0)
	{
		strcpy(words[ind], words[ind] + 2);
	}
	else
	{
		size_t wordLength = strlen(words[ind]);
		for (int i = wordLength; i >= 0; i--) // shifting so we have the original word saved (in case of discensore)
			words[ind][i + 2] = words[ind][i];
		words[ind][0] = '*';
		words[ind][1] = '\0';
	}
}

void changeWordByIndex(char** text, int ind, const char* word)
{
	delete[] text[ind];
	text[ind] = new char[strlen(word) + 3];
	strcpy(text[ind], word);
}

char* extractText(char** textMatrix, int wordsCount)
{
	size_t textLenght = 0;

	for (int i = 0; i < wordsCount; i++)
		textLenght += strlen(textMatrix[i]);
	textLenght += (wordsCount - 1); //for spaces

	char* resultText = new char[textLenght + 1];

	resultText[0] = '\0'; //for the first strcat to work
	for (int i = 0; i < wordsCount; i++)
	{
		strcat(resultText, textMatrix[i]);
		if (i != wordsCount - 1)
			strcat(resultText, " ");

	}

	return resultText;
}
