#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stringutils.h"
#include "stringiteratorwithfor.h"
#include "stringinsertwithtree.h"
#include "strinGetters.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("\nPor favor, ponha seu nome para podermos descobrir o valor dele e tal\n");
    char * name = getStringName();
    printf("\nName: %s", name);
    name = cleaner(name);
    printf("\nName: %s", name);
    counter(name);
    counterTree(name);
    return 0;
}