#pragma once
#include<iostream>

//Задача 1: Напишете програма, която приема две естествеи числа и връща най - големият им общ делител.
//
//Вход : 16 24, Изход : 8

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


//Задача 2: Напишете програма, която приема естествено число и връща дали числото е просто.
//
//Вход : 17, Изход : Prime
//
//Вход : 25, Изход : not prime

bool isPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}

	for (int i = 2; i * i <= n; i++) 
	{
		if (n % i == 0) 
		{
			return false;
		}
	}
	return true;
}


//Задача 3 : Напишете програма, която приема естествено число и отпечатва разбиването му на прости множители, сортирани низходящо.
//
//Вход : 50 Изход : 5 ^ 2 2 ^ 1

void primeFactors(int n) 
{

	for (int i = 2; i < n; i++) 
	{

		int count = 0;
		while (n % i == 0)
		{
			count++;
			n /= i;
		}
		if (count > 0) 
		{
			std::cout << i << "^" << count << " ";
		}
	}
	std::cout << std::endl;
}


//Задача 4 : Напишете програма, която приема цяло число и връща най - често срещаната цифра.Ако има няколко най - често срещани, то да се отпечата най - малката.
//
//Вход : 2881, Изход : 8
//
//Вход : 456, Изход : 4

void  mostrepeated() 
{
	int n; std::cin >> n;
	int moscommondigit = -1;
	int mostCommondigitoccurences = 0;//like counter
	for (int currentDigit = 0; currentDigit <= 9; currentDigit++)
	{
		int copyofN = n;
		int currentdigitoccurences = 0;

		while (copyofN != 0)
		{
			int lastDigit = copyofN % 10;
			if (lastDigit == currentDigit)
			{
				currentdigitoccurences++;
			}
			copyofN /= 10;
		}
		if (currentdigitoccurences > mostCommondigitoccurences)
		{
			moscommondigit = currentDigit;
			mostCommondigitoccurences = currentdigitoccurences;
		}
	}
	std::cout << moscommondigit;
}


//Задача 5: Напишете програма, която приема нечетно естествено число и отпечатва следния пясъчен часовник.
//
//Вход : 3

void print()
{
	int n;
	std::cin >> n;
	if (n % 2 != 1)
	{
		std::cout << "Please enter an odd natural number." << std::endl;
		return;
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			std::cout << " ";
		}
		for (int k = 0; k < 2 * (n - i) - 1; k++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;

	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << " ";
		}
		for (int k = 0; k < 2 * (n - i) - 1; k++) 
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}


//Задача 6: Да се напише програма, която приема поток от числа.Числата се събират, докато не се 
//въведе числото 0. Тогава трябва да се отпечата акумулираният резултат и да програмата да приключи.
//
//Вход : 1 2 3 4 5 6 0, Изход : 21
//
//Вход : 9 9 1 0, Изход : 19
//
//Вход : 5 4 3 0 Изход : 12

int sumTillZero() 
{
	int n;
	int sum = 0;
	do 
	{
		std::cin >> n;
		sum += n;
	} while (n != 0);
	return  sum;
}


//Задача 7: Да се напише програма, която приема 2 числа.Да се отпечатат всички общи делители сортиран наобратно.
//
//Вход : 28 21, Изход : 7 1
//
//Вход : 60 30 Изход : 30 15 10 6 5 3 2 1
//
//Вход : 19 17 Изход : 1

void printCommonDivisor()
{
	int a, b;
	std::cin >> a >> b;
	int smallerNum = (a < b) ? a : b;
	for (int i = smallerNum; i >= 1; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			std::cout << i << ' ';
		}
	}
	std::cout << std::endl;

}


//Задача 8: Да се напише програма, която приема число и премахва среднaта цифра, ако числото
//има нечетен брой цифри или премахва средните две цифри, ако числото има четен брой цифри.След това да се отпечата числото увеличено с 1 - ца.
//
//Вход : 1234, Изход : 14, 15
//
//Вход : 123 Изход : 13, 14
//
//Вход : 51234 Изход : 5134, 5135
//12345 ->1245 1246
//Вход : 5 Изход : 0, 1

void printNumbersWithoutMiddle()
{
	int num; std::cin >> num;
	int temp = num;
	int counter = 0;

	int index = 0;
	int array[10];
	while (num > 0)
	{
		int digit = num % 10;
		array[index] = digit;
		++index;
		num /= 10;

	}
	do 
	{
		temp /= 10;
		counter++;

	} while (temp != 0);

	int newnum = 0;
	int othernum = 0;

	if (counter % 2 == 0 && counter >= 2) 
	{
		for (int i = index - 1; i > counter / 2; --i) 
		{
			newnum = newnum * 10 + array[i];
		}
		std::cout << newnum;

		for (int i = counter / 2 - 2; i >= 0; i--)
		{
			othernum = othernum * 10 + array[i];
		}
		std::cout << othernum;
		std::cout << ' ' << newnum << othernum + 1;
	}

	else {

		for (int i = index - 1; i > counter / 2; --i) 
		{
			newnum = newnum * 10 + array[i];

		}
		for (int i = counter / 2 - 1; i >= 0; i--) 
		{
			othernum = othernum * 10 + array[i];
		}
		std::cout << newnum << othernum;
		std::cout << ' ' << newnum << othernum + 1;

	}

}


//Задача 9: Да се напише програма, която приема 2 числa - a и b и отпечатва всички прости числа в интервала[a, b].
//
//Вход : 10 20, Изход : 11 13 17 19
//
//Вход : 20 1, Изход :
//
//	Вход : 1 20 Изход : 2 3 5 7 11 13 17 19

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

void inIntervalPrime()
{
	int a, b;
	std::cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		if (isprime(i))
		{
			std::cout << i;
		}
	}
}


//Задача 10: Да се напише програма, която приема цяло число и отпечатва дали е степен на 2 - ката.
//
//Вход : 1, Изход : true
//
//Вход : 20 Изход : false
//
//Вход : 1024 Изход : true

bool isPowOfTwo() {
	int a;
	std::cin >> a;

	// A power of 2 has only one bit set to 1.
	// By subtracting 1, all the bits following the rightmost 1 will be set to 1.
	// Taking a bitwise AND of the original number and the number minus 1 should be 0.
	return (a != 0) && ((a & (a - 1)) == 0);
}


//Задача 11: Въвеждат се 5 цели числа - a, b, c, d, e.Разглеждаме полинома f(x) = a * x ^ 4 + b * x ^ 3 + c * x ^ 2 + d * x + e.
//Отпечатайте всички цели решения на f(x) >= 0 където x e в интервала[-100, 100]
//
//Вход : -1 4 0 8 1, Изход : 0 1 2 3 4
//
//Вход : 0 0 - 1 5 - 6 Изход : 2 3
//
//!!Задачите надолу са за рисуване на конзолата.Във файла drawing_examples.txt има изходите като текст.!!


//Задача 12: Да се напише програма, която приема цяло положително число n и отпечатва следната пирамида от доларчета
void draw() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout << '$';
		}
		std::cout << '\n';
	}

}


//Задача 13: Да се напише програма, която приема цяло положително число n и отпечатва следната пирамида от числа(подравнена надясно)

void drawPyramidOfNums() 
{
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 0; j < n - i; ++j) 
		{
			std::cout << " ";//printing spaces for alignment
		}
		for (int k = i; k >= 1; --k) 
		{
			std::cout << k << " ";//printing numbers in descending order
		}
		std::cout << std::endl;
	}
	// Lower half of the pyramid
	for (int i = n - 1; i >= 1; --i) 
	{
		// Print spaces for alignment
		for (int j = 0; j < n - i; ++j)
		{
			std::cout << "  ";
		}

		// Print numbers in descending order
		for (int k = i; k >= 1; --k) 
		{
			std::cout << k << " ";
		}

		std::cout << std::endl;
	}

}
//Задача 14: Да се напише програма, която приема цяло положително число n(n >= 2) и след това n цели числа.Да се отпечатат най - голямато и второто по големина.
//
//Вход : 10 9 1 4 5 10 99 34 0 44 1, Изход : 99 44
//
//Вход : 4 1 3 3 1, Изход : 4 3

void theBiggest()
{
	int n;
	std::cin >> n;
	int arr[1024];
	for (int i = 0; i < n; i++) 
	
	{
		std::cin >> arr[i];
	}
	int max = 0;
	int second = 0;
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] > max) {
			second = max;
			max = arr[i];
		}
		else if (arr[i] > second && arr[i] != max) {
			second = arr[i];
		}

	}
	std::cout << max << " " << second;
}
