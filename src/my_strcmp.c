/*
** EPITECH PROJECT, 2022
** MY_LS
** File description:
** my_strcmp
*/

#include "my.h"

int my_strlen (char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int my_strcmp (char const *str1, char const *str2)
{
    int a = my_strlen(str1);
    int b = my_strlen(str2);
    int compteur = 0;

    if (a != b)
        return (1);
    for (int i = 0; str1[i]; i++) {
        if (str1[i] == str2[i]) {
            compteur++;
        }
    }
    if (compteur != a) {
        return (1);
    } else {
        return (0);
    }
}
