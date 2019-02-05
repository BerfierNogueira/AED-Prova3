//
// Created by gnber on 03/02/2019.
//

#ifndef AED_STRINGINSERTWITHTREE_H
#define AED_STRINGINSERTWITHTREE_H

#include "stringutils.h"
#include "time.h"
#include "string.h"
#include "ctype.h"
#include "stdio.h"
#include "Tree.h"

int getLetterCode(char type){
    if(isalpha(type)){
        int num = (int) type;
        num = num - 64;
        return num%9;
    }
    else return 0;
}

void counterTree(char *str){
    char * letters = listOfLetters();
    int total = 0, pace = 0, current = 0;
    clock_t start, end;
    double cpu_time_used;
    //str = addNewCharacter(str);
    srand(time(NULL));

    Root root = raisesTree();

//    for (int k = 0; k < (str); k++) {
//        insertNodeTree(root, letters[k]);
//    }
    int size = strlen(letters);
    while(size > 1){
        size--;
        int remover = rand() % (size);
        char newNode = letters[remover];
        char temp = letters[size];
        letters[size] = newNode;
        letters[remover] = temp;
        insertNodeTree(root, newNode);
    }
    insertNodeTree(root, letters[0]);

    printYggdrasil(root, 0);
    printf("\n\nTotal de nos: %d", totalOfNodes(root));
    start = clock();

    for (int i = 0; i < strlen(str); ++i) {
        if(!isspace(str[i]) && isalpha(str[i])){
            pace += calculateInTree(root, str[i]);
        }
        else
        {
            current ++;
            printf("\nValor do %d° nome: %d", current, pace);
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


#endif //AED_STRINGINSERTWITHTREE_H
