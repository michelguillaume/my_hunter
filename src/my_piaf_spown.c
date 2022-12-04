/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_piaf_spown
*/

#include "my.h"

list_t *my_piaf_spawn(all_t *all, anime_t *anim)
{
    list_t *tmp = all->list;
        while (all->list != NULL) {
        all->list->pigeon->pos2d.x = 750 + rand() % 250;
        all->list->pigeon->pos2d.y = 10000;
        all->list->pigeon->t = rand() % 2;
        my_swap_orient(all);
        sfSprite_setTextureRect(all->list->pigeon->sprite,
        all->list->pigeon->rect);
        sfSprite_setPosition(all->list->pigeon->sprite,
        all->list->pigeon->pos2d);
        all->list = all->list->next;
        }
    anim->spon = 1;
    all->list = tmp;
    return (all->list);
}
