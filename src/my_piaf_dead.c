/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_piaf_dead
*/

#include "my.h"

void my_check_wave_clear(anime_t *anim, all_t *all)
{
    int i = 0;
    list_t *tmp = all->list;

    while (all->list != NULL){
        if (all->list->pigeon->pos3d.z == 3)
            i++;
        all->list = all->list->next;
    }
    all->list = tmp;
    if (i == 3) {
        anim->spon = 0;
        anim->nb_pigeon = 0;
        anim->wave += 1;
        anim->shot = 0;
        while (all->list != NULL){
            all->list->pigeon->pos3d.z = 0;
            all->list = all->list->next;
        }
    }
    all->list = tmp;
}

void my_piaf_anim_dead(all_t *all)
{
    all->list->pigeon->t = 0 + rand() % 4;
    dead_pos(all);
    all->list->pigeon->pos3d.z = 2;
    sfSprite_setTextureRect(all->list->pigeon->sprite, all->list->pigeon->rect);
    sfSprite_setPosition(all->list->pigeon->sprite, all->list->pigeon->pos2d);
}
