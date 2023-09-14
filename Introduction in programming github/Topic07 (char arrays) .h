#pragma once
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)


//Задача 1: Напишете функция, която приема 3 стринга - text, where и what и земства в text всяко срещане на where с what.
//
//Да се реши без допълнителна памет(in - place).
//Вход : "I am the best of the best", "best", "worst", Изход : "I am the worst of the worst"
//

void replace(char text[], const char where[], const char what[])
{
    int txtLen = strlen(text);
    int whereLen = strlen(where);
    int whatLen = strlen(what);
    int shift = whatLen - whereLen;

    for (int i = 0; i <= txtLen; i++)
    {
        if (strcmp(&text[i], where) == 0)
        {
            if (shift > 0) 
            {
                for (int j = txtLen + shift; j >= i + whereLen; j--)
                {
                    text[j] = text[j - shift];
                }
            }
            else if (shift < 0) 
            {
                for (int j = i + whereLen; j <= txtLen + shift; j++)
                {
                    text[j] = text[j - shift];
                }
            }
            strcpy(&text[i], what);
            txtLen += shift;
        }
    }
}

//Задача 2 Напишете функции toUpper и toLower, които приемат стринг и променят всички главни букви в малки / всички малки букви в главни.

void toUpper(char str[]) 
{
    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

}

void toLower(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] += 32;
        }
    }
}


//other solution

//void toUpper(char str[]) {
//	int length = std::strlen(str);
//	for (int i = 0; i < length; i++) {
//		if (str[i] >= 'a' && str[i] <= 'z') {
//			str[i] = str[i] - 'a' + 'A';
//		}
//	}
//}
//
//void toLower(char str[]) {
//	int length = std::strlen(str);
//	for (int i = 0; i < length; i++) {
//		if (str[i] >= 'A' && str[i] <= 'Z') {
//			str[i] = str[i] - 'A' + 'a';
//		}
//	}
//}



//Задача 3 Напишете функция, която приема стринг и връща броя на думите в него. (Думите са разделени с произволен брой интервали, табулации и препинателни знаци)
//
//Вход : "Me? Why always me?, Изход: 4

int numOfWords(char str[]) 
{

    int index = 0;

    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] == ' ')
        {
            index++;
        }
    }
    return index;

}

//another solution::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// 
//int numOfWords(const char str[]) {
//	int count = 0;
//	bool isWord = false;
//	for (int i = 0; str[i] != '\0'; i++) {
//		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
//			isWord = false;
//		}
//		else if (!isWord) {
//			isWord = true;
//			count++;
//		}
//	}
//	return count;
//}


//Задача 4 Напишете функция, която приема стринг и връща най - често срещаната дума.(Думите са разделени с произволен брой интервали, табулации и препинателни знаци).Игнорираме разликата между главни и малки букви за задачата.

//Вход : "Me? Why always me?, Изход: me
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!REVIEW

bool isPunctuation(char c) {
    return (c >= '!' && c <= '/') || (c >= ':' && c <= '@') ||
        (c >= '[' && c <= '`') || (c >= '{' && c <= '~');
}

char toLowercase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

void mostCommon(const char* sentence) {
    char cleanedSentence[100];
    int cleanedIndex = 0;

    // Remove punctuation and convert to lowercase
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (!isPunctuation(sentence[i])) {
            cleanedSentence[cleanedIndex] = toLowercase(sentence[i]);
            cleanedIndex++;
        }
    }
    cleanedSentence[cleanedIndex] = '\0';

    // Find the most common word
    char mostCommonWord[100];
    int frequency = 0;

    int i = 0;
    while (cleanedSentence[i] != '\0') {
        char word[100];
        int wordIndex = 0;
        while (cleanedSentence[i] != ' ' && cleanedSentence[i] != '\0') {
            word[wordIndex] = cleanedSentence[i];
            wordIndex++;
            i++;
        }
        word[wordIndex] = '\0';

        int count = 1;
        int j = i + 1;
        while (cleanedSentence[j] != '\0') {
            // Compare word with other words
            char otherWord[100];
            int otherWordIndex = 0;
            while (cleanedSentence[j] != ' ' && cleanedSentence[j] != '\0') {
                otherWord[otherWordIndex] = cleanedSentence[j];
                otherWordIndex++;
                j++;
            }
            otherWord[otherWordIndex] = '\0';

            // Check if the words are the same
            bool isSameWord = true;
            for (int k = 0; k < wordIndex; k++) {
                if (word[k] != otherWord[k]) {
                    isSameWord = false;
                    break;
                }
            }

            if (isSameWord) {
                count++;
            }

            j++;
        }

        if (count > frequency) {
            frequency = count;
            for (int k = 0; k <= wordIndex; k++) {
                mostCommonWord[k] = word[k];
            }
        }

        i++;
    }

    mostCommonWord[frequency] = '\0';

    std::cout << "The most common word is: " << mostCommonWord << std::endl;
}



//Задача 5 Напишете функция, която приема стринг и връща лексикографско най - малка дума.
//
//Вход : "Me? Why always me?, Изход: always

