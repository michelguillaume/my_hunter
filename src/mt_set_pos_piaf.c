/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** mt_set_pos_piaf
*/

#include "my.h"

void my_orient_0(all_t *all)
{
    all->list->pigeon->rect.left = 114;
    all->list->pigeon->rect.top = 36;
    all->list->pigeon->rect.width = 33;
    all->list->pigeon->rect.height = 34;
}

void my_orient_1(all_t *all)
{
    all->list->pigeon->rect.left = 69;
    all->list->pigeon->rect.top = 2;
    all->list->pigeon->rect.width = 33;
    all->list->pigeon->rect.height = 34;
}

void my_orient_2(all_t *all)
{
    all->list->pigeon->rect.left = 1;
    all->list->pigeon->rect.top = 37;
    all->list->pigeon->rect.width = 34;
    all->list->pigeon->rect.height = 32;
}

void my_swap_orient(all_t *all)
{
    if (all->list->pigeon->t == 0){
        my_orient_0(all);
    }
    if (all->list->pigeon->t == 1){
        my_orient_1(all);
    }
    if (all->list->pigeon->t == 2){
        my_orient_2(all);
    }
    if (all->list->pigeon->t == 3){
        all->list->pigeon->rect.left = 179;
        all->list->pigeon->rect.top = 0;
        all->list->pigeon->rect.width = 34;
        all->list->pigeon->rect.height = 34;
    }
}
