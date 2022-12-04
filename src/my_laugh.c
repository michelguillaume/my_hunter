/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_laugh
*/

#include "my.h"

void my_laugh_dog(anime_t *anim, all_t *all)
{
    anim->laughtime = sfClock_getElapsedTime(anim->laughclock);
    anim->laughseconds = anim->laughtime.microseconds / 1000000.0;

    anim->lauuptime = sfClock_getElapsedTime(anim->lauupclock);
    anim->lauupseconds = anim->lauuptime.microseconds / 1000000.0;

    if (anim->laughseconds > 0.2){
        switch (all->laugh->rect.left){
        case 0: all->laugh->rect.left = 43; break;
        case 43: all->laugh->rect.left = 0; break;
        }
        sfClock_restart(anim->laughclock);
    }
    if (all->laugh->pos3d.z < 62 && anim->lauupseconds > 0.01){
        all->laugh->pos2d.y -= 2;
        all->laugh->pos3d.z += 1;
        sfClock_restart(anim->lauupclock);
    }
    sfSprite_setTextureRect(all->laugh->sprite, all->laugh->rect);
    sfSprite_setPosition(all->laugh->sprite, all->laugh->pos2d);
}
