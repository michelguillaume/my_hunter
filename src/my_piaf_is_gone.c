/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_piaf_is_gone
*/

#include "my.h"

void check_gone(anime_t *anim, all_t *all)
{
    if (anim->spon != 0 && all->list->pigeon->pos3d.z != 3){
        if (all->list->pigeon->pos2d.y < -150 ||
        all->list->pigeon->pos2d.x < -150
        || all->list->pigeon->pos2d.x > 1860){
            all->list->pigeon->pos3d.z = 3;
            anim->life += 1;
        }
    }
    all->list = all->list->next;
}

void my_piaf_is_gone(anime_t *anim, all_t *all)
{
    list_t *tmp = all->list;
    while (all->list != NULL){
        check_gone(anim, all);
    }
    all->list = tmp;
}
