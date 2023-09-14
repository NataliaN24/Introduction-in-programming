#pragma once
#include<iostream>

//Задача 1: Да се напише функция, която приема масив, в който всяко 
// число се среща 2 пъти с изключение на едно число, което се среща веднъж.
// Напишете функция, която приема такъв масив и връща кое е това число. (Подсказка : използвайте побитови операции, за да постигнете линейно решение)
//
//Вход : [9 18 9 12 18 15 12] , Изход : 15

int getNotTwice(const int arr[], int size) 
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result ^= arr[i];
    }
    return result;

}
//For each element, we perform the XOR operation between the current resultand the element arr[i].
//XORing two numbers results in 0 if they are the same, and a non - zero value if they are different.
//
//Since all the numbers occur twice except for one number, the duplicates will cancel 
//each other out.Only the number occurring once will remain in the result variable after the XOR operation.


//Задача 2 : Напишете функция, която приема цяло число и връща броя на 1 - ците в двоичния му запис.
//
//Вход : 189, Изход : 6
//
int numberofonesBINARY(int num) 
{
    int count = 0;
    while (num != 0)
    {
        if (num & 1)
        {
            count++;
        }
        num >>= 1;
    }
    return count;
}


//We use a while loop to iterate until the number becomes 0. Inside the 
//loop, we check the least significant bit(LSB) of the number by performing a bitwise AND operation 
//with 1 (num & 1).If the LSB is 1, we increment the count variable.
//
//Then, we shift the bits of the number to the right by 1 (num >>= 1) to move to the next bit.This process continues until the number becomes 0.


//Задача 3 : Напишете функция, която приема цяло число и обръща най - десния бит в него, който е единица.
//
//Вход : 12, Изход : 8
//
//Вход : 15, Изход : 14

int themostRIGHT(int num)
{
    return num & (num - 1);
}

//Задача 4 : Напишете функция, която по подадено цяло число n и цяло число k и връща числото, което е "закодирано" в последните k бита на n.
//
//Вход : 15 2, Изход : 3
//
//Вход : 189 3, Изход : 5
//
//Вход : 189 4, Изход : 13

int encodeNum(int n, int k)
{
    int bitmask = (1 << k) - 1;
    int result = n & bitmask;

    return result;

}


//Задача 5 : Напишете функция, която приема цяло число n и цяло число k и връща дали k в двоичен запис(разглеждайки го без водещите 0 - ли) е част от двоичния запис на n.
//
//Вход : 15 3, Изход : true
//
//Вход : 13 5 Изход : true
//
//Вход : 13 7, Изход : false


bool isBinaryMatch(int n, int k)
{
    int shiftedK = k;
    int lengthK = 0;

    // Calculate the length of k in binary representation
    while (shiftedK > 0)
    {
        shiftedK >>= 1;
        lengthK++;
    }

    // Shift n to check for substrings of lengthK

    int shiftedN = n;
    for (int i = 0; i <= 32 - lengthK; i++) {
        // Extract a substring from n of lengthK
        int subN = shiftedN & ((1 << lengthK) - 1);

        if (subN == k)
        {
            return true;
        }

        shiftedN >>= 1;
    }

    return false;
}


//Задача 6 : Напишете функция, която приема масив(разглеждаме го като множество) и отпечатва всички негови подмножества.
//
//Вход : [1, 2, 3] , Изход : [] , [1], [2], [3], [1, 2], [2, 3], [1, 3], [1, 2, 3]
//
//Вход : [5, 3] Изход : [] , [5], [3], [5, 3]


void printSubsets(int arr[], int size) 
{
    int totalSubsets = 1 << size;

    for (int i = 0; i < totalSubsets; i++) {
        std::cout << "{ ";
        for (int j = 0; j < size; j++) {
            if ((i & (1 << j)) != 0) {
                std::cout << arr[j] << " ";
            }
        }
        std::cout << "}\n";
    }
}
