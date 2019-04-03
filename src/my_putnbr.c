/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene0.c
*/

#include "prototypes.h"

static char *my_evil_str(char *str)
{
    int count = 0;
    int i = 0;
    int midcount;
    int inter;

    while (str[count] != '\0') {
        count++;
    }
    midcount = count/2;
    while (count > midcount) {
        inter = str[count-1];
        str[count-1] = str[i];
        str[i] = inter;
        i++;
        count--;
    }
    return (str);
}

char *my_put_nbr(int nbr)
{
    int temp;
    int i = 0;
    char *result = malloc(sizeof(char) * 4);

    if (!result)
        return (NULL);
    if (nbr == 0) {
        result[i] = '0';
        i++;
    }
    while (nbr > 0) {
        temp = nbr % 10;
        result[i] = temp + 48;
        nbr /= 10;
        i++;
    }
    result[i] = '\0';
    result = my_evil_str(result);
    return (result);
}