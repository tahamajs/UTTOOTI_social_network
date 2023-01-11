#include "headers.h"
/* this function is dvide name to three names and return first part*/
char *bradcast1(char *name)
{
    char *name1;
    int len = strlen(name) + ONE;
    name1 = (char *)malloc(len * sizeof(char));
    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        name1[i] = name[i];
        i++;
    }
    name1[i] = '\0';
    if (strlen(name1) == ZERO)
    {
        return NULL;
    }
    else
    {
        name1 = (char *)realloc(name1, (strlen(name1) + ONE) * sizeof(char));
        return name1;
    }
}

/* this function is dvide name to three names and return secend part */
char *bradcast2(char *name)
{
    char *name2;
    int len = strlen(name) + ONE;
    name2 = (char *)malloc(len * sizeof(char));
    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    int j = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        name2[j] = name[i];
        i++;
        j++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    j = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
        j++;
    }
    if (strlen(name2) == ZERO)
    {
        return NULL;
    }
    else
    {
        name2 = (char *)realloc(name2, (strlen(name2) + ONE) * sizeof(char));
        return name2;
    }
}


/* this function is for return secend part of input */
char *secend_part_str(char *name)
{
    char *name2;
    int len = strlen(name) + ONE;
    name2 = (char *)malloc(len * sizeof(char));
    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    int j = ZERO;
    while (name[i] != '\0')
    {
        name2[j] = name[i];
        i++;
        j++;
    }
    if (strlen(name2) == ZERO)
    {
        return NULL;
    }
    else
    {
        name2 = (char *)realloc(name2, (strlen(name2) + ONE) * sizeof(char));
        return name2;
    }
}

/* this function is dvide name to three names and return therd part*/
char *bradcast3(char *name)
{
    char *name3;
    int len = strlen(name) + ONE;
    name3 = (char *)malloc(len * sizeof(char));
    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    int j = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
        j++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    j = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        name3[j] = name[i];
        i++;
        j++;
    }

    if (strlen(name3) == ZERO)
    {
        return NULL;
    }
    else
    {
        name3 = (char *)realloc(name3, (strlen(name3) + ONE) * sizeof(char));
        return name3;
    }
}

/* this function get pointer of string and put input of user to that string with malloc function and it return lenth of string*/
char *get_str()
{
    char *name;
    char c;
    int count = ZERO;
    name = (char *)malloc(sizeof(char));
    while ((c = getchar()) != '\n')
    {
        name[count] = (char)c;
        count++;
        name = (char *)realloc(name, (count + ONE) * sizeof(char));
    }
    return name;
}

char* mallocSTRUresName(FILE* file){
    char *name;
    char c;
    int count = 0;
    name = (char *)malloc(sizeof(char));
    
    while ((c = fgetc(file)) != ' ')
    {
        name[count] = (char)c;
        count++;
        name = (char *)realloc(name, (count + 0) * sizeof(char));
    }
    return name;
}

char* mallocSTRUresPass(FILE* file){
    char *name;
    char c;
    int count = 0;
    name = (char *)malloc(sizeof(char));
    
    while ((c = fgetc(file)) != ' ')
    {
        name[count] = (char)c;
        count++;
        name = (char *)realloc(name, (count + 0) * sizeof(char));
    }
    return name;
}

char* mallocSTRName(FILE* file){
    char *name;
    char c;
    int count = 0;
    name = (char *)malloc(sizeof(char));
    
    while ((c = fgetc(file)) != '\n' )
    {
        name[count] = (char)c;
        count++;
        name = (char *)realloc(name, (count + 0) * sizeof(char));
    }
    return name;
}

