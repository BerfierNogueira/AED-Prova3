//
// Created by gnber on 03/02/2019.
//

#ifndef AED_STRINGETTERS_H
#define AED_STRINGETTERS_H
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char * getStringName ()
{
    size_t sizeChar = sizeof (char);
    int count = 0;
    char *str = (char *) malloc (sizeChar), *nextStr = NULL, input;
    while (input != '\n')
    {
        count++;

        input = getchar ();
        nextStr = (char *) realloc (str, count * sizeChar);
        if (nextStr)
        {
            str = nextStr;
            str[count - 1] = input;
        }
        else
        {
            printf ("\nError during allocation");
            exit (1);
        }
    }

    return str;
}


char * cleaner (char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if (str == NULL)
    {
        return NULL;
    }
    if (str[0] == '\0')
    {
        return str;
    }

    len = strlen (str);
    endp = str + len;

    /* Move the front and back pointers to address the first non-whitespace
     * characters from each end.
     */
    while (isspace ((unsigned char) *frontp))
    {
        ++frontp;
    }
    if (endp != frontp)
    {
        while (isspace ((unsigned char) *(--endp)) && endp != frontp)
        {
        }
    }

    if (str + len - 1 != endp)
        *(endp + 1) = '\0';
    else if (frontp != str && endp == frontp)
        *str = '\0';

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = str;
    if (frontp != str)
    {
        while (*frontp)
        {
            *endp++ = *frontp++;
        }
        *endp = '\0';
    }


    return str;
}
#endif //AED_STRINGETTERS_H
