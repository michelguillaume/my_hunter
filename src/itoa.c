/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** itoa
*/

#include "my.h"

char * my_rev_str(char *str)
{
    char *rev = malloc(sizeof(char) * 7);
    rev[6] = '\0';

    for (int i = 0, j = 5; i < 6; i++, j--){
        rev[i] = str[j];
    }
    return (rev);
}

char *my_itoa(int num)
{
    char * nw_str = malloc(sizeof(char) * 7);
    nw_str[6] = '\0';

    for (int i = 0; i < 6; i++){
        nw_str[i] = '0';
    }

    for (int i = 0; num > 0; i++){
        nw_str[i] = '0' + (num % 10);
        if (num != 0)
            num = num / 10;
    }
    nw_str = my_rev_str(nw_str);
    return (nw_str);
}

int my_str_to_nbr(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i]; i++){
        nbr += str[i] - 48;
        if (nbr != 0 && str[i + 1])
            nbr *= 10;
    }
    return (nbr);
}
