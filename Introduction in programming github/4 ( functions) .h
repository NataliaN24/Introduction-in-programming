#pragma once
#include<iostream>

//Задача 2 : Напишете функция, която приема неотрицателно число n и връща числото обърнато
//
//Вход : 288, Изход : 882

int reversedNum(int num) {

	int reversed = 0;
	while (num != 0) 
	{
		reversed = reversed * 10 + num % 10;
		num /= 10;
	}
	return reversed;
}

//Задача 3 : Напишете функция, която приема неотрицателно число и връща дали числото е палиндром.
//
//Вход : 2882 Изход : true

bool isPalindrome() 
{

	int num;
	std::cin >> num;
	if ((reversedNum(num) == num))
	{
		return true;
	}
	return false;

}

//Задача 4 : Напишете функция, която приема неотрицателни числа n и k и връща дали k е суфикс на n.
//
//Вход : 288, 88, Изход : true

bool suffix() 
{
	int num;
	std::cin >> num;
	int k;
	std::cin >> k;
	while (k > 0) 
	{
		if (num % 10 != k % 10) {
			return false;
		}
		num /= 10; k /= 10;
	}return true;

}


//Задача 5 : Напишете функция, която приема неотрицателни числа n и k и връща дали k е префикс на n.
//Вход : 288, 28, Изход : true

bool preffix()
{

	int num;
	std::cin >> num;
	int k;
	std::cin >> k;

	if (num / 10 != k) {
		return false;
	}
	return true;

}

//Задача 6 : Напишете функция, която приема неотрицателни числа n и k и връща дали k е инфикс в n.
//
//Вход : 2831, 83, Изход : true

bool inffix()
{

	int num;
	std::cin >> num;
	int k;
	std::cin >> k;

	while (num > 0) {
		if (num % 10 == k % 10)
		{
			int temp = num;
			int sectemp = k;
			bool ismatching = true;
			while (sectemp > 0) {
				if (temp % 10 != sectemp % 10) 
				{
					ismatching = false;
					break;
				}
				temp /= 10; sectemp /= 10;
			}
			if (ismatching) {
				return true;
			}
		}
		num /= 10;
	}
	return false;

}

//Задача 7 : Напишете функция, която приема две естествени числа и връща n^ k.
//
//Вход : 4 5, Изход : 1024

int powerOfNum()
{
	int num, k;
	std::cin >> num >> k;
	if (k == 0) 
	{
		return 1;
	}
	else if (k == 1)
	{
		return num;
	}
	else 
	{
		int result = 1;
		while (k > 0) {
			if (k % 2 == 1) {
				result *= num;
			}
			num *= num;
			k /= 2;
		}
		return result;

	}
}

//Задача 8: Напишете функция, която приема цяло число и връща модула му.
//
//Вход : 4, Изход : 4

//Вход : -4, Изход : 4

int modul(int num)
{
	return (num >= 0) ? num : -num;
}

//Задача 9 : Напишете функция, която приема цяло число и връща броя на цифрите му.
//
//Вход : 4, Изход : 1
//
//Вход : -4, Изход : 1
//
//Вход : 5430 Изход : 4

int length(int number) {
	int counter = 0;
	while (number != 0) 
	{
		number /= 10;
		counter++;
	}
	return counter;
}



//Задача 10: Напишете функция, която приема 6 целочислени координати(3 точки) и връща обиколката на триъгълника по тези точки.
//
//Вход : 1 1 4 7 0 10, Изход : 20.764

int distance(int x, int x2, int y, int y2) 
{
	int dx = (x - x2) * (x - x2) + (y - y2) * (y - y2);
	return dx;
}

int triangle() 
{
	int x, y, x1, y1, x2, y2;
	std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;

	//find the slopes
	int dx1 = sqrt(distance(x, x1, y, y1));
	int dx2 = sqrt(distance(x, x2, y, y2));
	int dx3 = sqrt(distance(x1, x2, y1, y2));
	return dx1 + dx2 + dx3;

}

//Задача 11 : Да се напише функция, която приема две естествени числа и връща ново число, което е тяхната конкатенация.
//
//Вход : 19 32, Изход : 1932

int concat(int x, int y)
{
	int temp = y;
	while (temp != 0)
	{
		x *= 10;
		temp /= 10;
	}
	return x + y;

}

//Задача 12 : Напишете функция, която дадено по подадено
//  естествено число N, връща число, което е резултат от конкатенацията на обърнатото число на N с подаденото N.
//
//Вход : 1234 Изход : 43211234

int concatReversed(int num)
{
	int temp = num;
	int reversed = 0;
	while (temp != 0) {
		reversed = reversed * 10 + temp % 10;
		temp /= 10;
	}
	int newnum = concat(reversed, num);
	return newnum;

}

//Задача 13: Да се напише функция, която приема три естествени числа a и b и k и връща броя на числата в интервата[a...b], които имат 
// точно k различни прости делитела.
//
//Вход : 19 32 3, Изход : 1
//
//Вход : 19 42 3, Изход : 2

bool isprime(int num)
{
	if (num < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) 
		{
			return false;
		}
	}
	return true;
}

int countNumberPrime(int a, int b, int c) 
{
	int count = 0;
	for (int i = a; i <= b; ++i) {
		int num = i;
		int primedivisors = 0;
		for (int j = 2; j * j <= num; j++) 
		{

			if (isprime(j) && num % j == 0)
			{
				primedivisors++;
				while (num % j == 0) {
					num /= j;
				}
			}
		}
		if (num > 1) 
		{
			primedivisors++;
		}
		if (primedivisors == c)
		{
			count++;

		}
	}
	return count;


}

//Задача 14 : Напишете функция, която приема естествено число и връща дали цифрите му са сортирани(във възходящ или в низходящ ред).
//
//Вход : 122239, Изход : true

bool isSorted(int num)
{
	int prevDigit = num % 10;
	num /= 10;
	bool asc = true;
	bool desc = true;
	while (num != 0) {
		int digit = num % 10;
		if (digit > prevDigit) {
			desc = false;
		}
		if (digit < prevDigit) {
			asc = false;
		}
		prevDigit = digit;
		num /= 10;
	}
	return asc || desc;
}


//Задача 15 : Напишете функция, която приема естествено число и връща дали цифрите му са еднакви.
//
//Вход : 111111, Изход : true
//

bool isSame(int num) 
{
	int prevDigit = num % 10;
	num /= 10;

	while (num != 0)
	{
		int digit = num % 10;
		if (digit == prevDigit)
		{
			return true;
		}
		num /= 10;
	}
	return false;
}

//Задача 16 : Напишете функция, която приема естествено число и връща ново число, което има същите цифри, но в сортиран вид.
//
//Вход : 531261, Изход : 112356
//

int sort(int num) 
{
	int arr[10] = { 0 };

	//count the occurence of each digit
	while (num != 0) {
		int digit = num % 10;
		arr[digit]++;
		num /= 10;
	}
	int sortednum = 0;
	for (int i = 0; i < 10; i++) 
	{
		while (arr[i] > 0) {
			sortednum = sortednum * 10 + i;
			arr[i]--;
		}
	}

	return sortednum;
}

//Задача 17 : Напишете функция, която приема символ и дали символа е главна буква.
//
//Вход : 'А', Изход : true
//
//Вход : '!', Изход : false //или грешка

bool isUpper(char symbol) {
	if (symbol >= 'A' && symbol <= 'Z') {
		return true;
	}
	return false;
}

//Задача 18: Напишете функция, която приема символ и връща съответната главна буква(ако подадения символ е малък символ)
//
//Вход : 'а', Изход : 'А'
//
//Вход : '!', Изход : '!' //или грешка
//

char symbolToUpper(char symbol) {
	if (symbol >= 'A' && symbol <= 'Z') 
	{
		return symbol;
	}
	else if (symbol >= 'a' && symbol <= 'z')
	{
		return symbol - 32;
	}

}

//Задача 19 : Напишете функция, която приема символ и ако символът е цифра, да върне съответната цифра.Ако символът не е цифра, то да върне - 1
//
//Вход : '7', Изход : 7
//
//Вход : '!', Изход : -1 //или грешка

int  symbolToNum(char symbol) 
{
	if (symbol >= '0' && symbol <= '9') 
	{
		return symbol - '0';//convert to its corrisponding int //if fc was char just return symbol without substracting '0' from symbol.
	}
	else {
		return-1;
	}

}


//Задача 1: Въвежда се неотрицателно число n.Да се отпечатат всички двойки прости числа, които са във вида 6k - 1 и 6k + 1.
//
//- решена без функции и решена с функции.

//Задача 8 : Напишете функция, която приема неотрицателно числа n и k връща log_k(n) (закръглено надолу)
//
//Вход : 90 3 Изход : 4
//
//Задача 9 : Напишете функция, която приема 4 цели числа - a, b, c, d и връща дали точката <a, b> и точката <c, d> лежат на една окръжност с център <0, 0>.
//
//Вход : 1 0 0 1 Изход : true
