//
// Created by gnber on 03/02/2019.
//

#ifndef AED_STRINGITERATORWITHFOR_H
#define AED_STRINGITERATORWITHFOR_H

#include "stringutils.h"
#include <time.h>

void counter(char *str){
    char * letters = listOfLetters();
    int total = 0, pace = 0, current = 0;
    clock_t start, end;
    double cpu_time_used;
    str = addNewCharacter(str);
    start = clock();
    for (int i = 0; i < strlen(str); ++i) {
        if(!isspace(str[i]) && isalpha(str[i])){

            char match = tolower(str[i]);

            for (int j = 0; j < strlen(letters); j++) {
                if(match == letters[j]){
                    pace += ((j+1)%9);
                }
            }
        }

        else
        {
            current ++;
            printf("\nValor do %d° nome: %d\n", current, pace);
            total += countTheChars(pace);
            pace = 0;
        }
    }

    int valueOfName = countTheChars(total);
    printf("\nValor do nome no total: %d", valueOfName);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nEsta função demorou %f clocks por segundos", cpu_time_used);
}



#endif //AED_STRINGITERATORWITHFOR_H
