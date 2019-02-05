//
// Created by gnber on 03/02/2019.
//

#ifndef AED_STRINGUTILS_H
#define AED_STRINGUTILS_H
#include "string.h"

char * listOfLetters(){
    int pace = 26;
    char * letters = (char *) malloc(pace * sizeof(char));
    char theLetter = 'a';
    for (int k = 0; k < pace; k++) {
        letters[k] = theLetter;
        theLetter++;
    }
    return letters;
}

int countTheChars(int num){
    if(num < 10){
        return num;
    }
    else{
        int aux = num/10, resto = num%10;
        int prev = countTheChars(aux) + countTheChars(resto);
        if(prev < 10){
            return prev;
        }
        else{
            return countTheChars(prev);
        }
    }
}

char * addNewCharacter(char * str){
    int strNumber = (strlen(str)+1);
    char * nextStr = (char *) realloc (str,  strNumber * sizeof(char));
    if (nextStr != NULL)
    {
        str = nextStr;
        str[strNumber-1] = '\n';
        return str;
    }
    else
    {
        printf ("\nError during allocation");
        exit (1);
    }
}

#endif //AED_STRINGUTILS_H
