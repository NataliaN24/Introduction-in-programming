﻿#pragma once
#include<iostream>

//Задача 1: Въвежда се цяло число.Отпечатайте 1, ако числото е четно и 0, ако е нечетно.
//
//Вход : 265, Изход : 0
//
//Вход : 290, Изход : 1

bool evenOrOdd(int n)
{
	return n % 2 == 0 ? 1 : 0;
}


//Задача 2: Въвежда се трицифрено цяло число n.Да се отпечата обърнатото число събрано с единица.
//
//Вход : 265, Изход : 563
//
//Вход : 289, Изход : 983

int reversedPlusOne(int n) 
{
	int digit = 0;
	while (n != 0)
	{
		int reversed = n % 10;
		digit = digit * 10 + reversed;
		n /= 10;
	}
	return digit + 1;

}


//Задача 3: Въвежа се символ.Да се отпечата 1, ако е английска гласна буква, и 0, ако не е.
//
//Вход : а, Изход : 1
//
//Вход : Е, Изход : 1
//
//Вход : В, Изход : 0

bool symbolOrNo(char symbol) 
{
	return symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u' || symbol == 'A' || 
		symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U';

}


//Задача 4: Въвежа се цяло число.Да се отпечата 1, ако числото е валидна оценка от училище, и 0, ако не е валидна.
//
//Вход : 5, Изход : 1
//
//Вход : 3, Изход : 1
//
//Вход : 9, Изход : 0

bool isValidGrade(int n) 
{
	return n >= 3 && n <= 6;
}


//Задача 5: Въвежа се цяло число.Да се отпечата без последната цифра.
//
//Вход : 513, Изход : 51
//
//Вход : 1234, Изход : 123
int withoutLasttDigit(int n)
{
	return n / 10;
}


//Задача 6: Напишете програма, която въвежда две числа - a и b и извежда като резултат(a + b) ^ 4 - (a - b) ^ 2
//
//Вход : 5 7, Изход : 20732

int result(int a, int b) 
{
	return ((a + b) * (a + b) * (a + b) * (a + b)) - ((a - b) * (a - b));
}


//Задача 7: Въвежда се цяло число n - n лева.Да се изведе на конзолата как може да 
// се разпределят по банкноти, така че да имаме минимален брой банкноти.В условието приемаме, че имаме банкноти от 1 и 2 лева.
//
//Вход : 193, Изход : 1x100lv 1x50lv 2x20lv 0x5lv 1x2lv 1x1lv
//
void  banknotes(int num)
{

	int hundreds = num / 100;//193/100=1
	num %= 100;//93

	int fifty = num / 50;//1
	num %= 50;//
	int twenty = num / 20;
	num %= 20;
	int five = num / 5;
	num %= 5;
	int two = num / 2;
	int one = num %= 2;
	std::cout << hundreds << "x100lv " << fifty << "x50lv " << twenty << "x20lv "
		<< five << "x5lv " << two << "x2lv " << one << "x1lv" << std::endl;

}

//Задача 8 : Въвеждат се две числа.Да се отпечата по - голямото от двете.
//
//Вход : 265, 44, Изход : 265
int biggest(int a, int b)
{
	return a < b ? b : a;
}

