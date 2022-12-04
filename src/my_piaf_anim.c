/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_piaf_anim
*/

#include "my.h"

void my_piaf_is_dead(anime_t *anim, all_t *all)
{
    dead_fall(all, anim);
    sfSprite_setTextureRect(all->list->pigeon->sprite,
    all->list->pigeon->rect);
    sfSprite_setPosition(all->list->pigeon->sprite,
    all->list->pigeon->pos2d);
}

void my_piaf_moov(anime_t *anim, all_t *all)
{
    list_t *tmp = all->list;
    for (int i = 0; all->list != NULL && i < anim->nb_pigeon; i++){
        if (all->list->pigeon->pos2d.y > 780 &&
        all->list->pigeon->pos3d.z == 2){
            all->list->pigeon->pos3d.z = 3;
            all->list->pigeon->pos2d.x = 10000;
            sfSprite_setPosition(all->list->pigeon->sprite,
            all->list->pigeon->pos2d);
        }
        if (all->list->pigeon->pos3d.z == 0)
            my_piaf_moov_alive(anim, all);
        if (all->list->pigeon->pos3d.z == 1){
            my_piaf_anim_dead(all);
        }
        if (all->list->pigeon->pos3d.z == 2){
            my_piaf_is_dead(anim, all);
        }
        all->list = all->list->next;
    }
    all->list = tmp;
}

void my_swap_pos(all_t *all, int old)
{
    if (all->list->pigeon->pos3d.z == 0){
        old = all->list->pigeon->t;
        while (old == all->list->pigeon->t)
            all->list->pigeon->t = 0 + rand() % 4;
        my_swap_orient(all);
    }
    all->list = all->list->next;
}

void my_swap_pos_piaf(anime_t *anim, all_t *all)
{
    int old = 0;
    list_t *tmp = all->list;
    if (anim->genseconds > (1 - (0.04 * anim->wave))){
        for (int i = 0; all->list != NULL && i < anim->nb_pigeon; i++){
            my_swap_pos(all, old);
        }
        sfClock_restart(anim->genclock);
    }
    all->list = tmp;
}

void my_piaf_moov_alive(anime_t *anim, all_t *all)
{
    if (all->list->pigeon->pos2d.y == 10000)
        all->list->pigeon->pos2d.y = 750;
    my_mouv_left(all, anim);
    my_mouv_right(all, anim);
    my_mouv_upleft(all, anim);
    my_mouv_upright(all, anim);
    sfSprite_setTextureRect(all->list->pigeon->sprite,
    all->list->pigeon->rect);
    sfSprite_setPosition(all->list->pigeon->sprite, all->list->pigeon->pos2d);
}
