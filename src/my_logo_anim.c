/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_logo_anim
*/

#include "my.h"

void my_logo_anim(anime_t *anim, all_t *all)
{
    anim->logotime = sfClock_getElapsedTime(anim->logoclock);
    anim->logosecond = anim->logotime.microseconds / 1000000.0;

    if (anim->logosecond > 0.1){
        switch (all->logo->rect.left){
        case 8: all->logo->rect.left = 304; break;
        case 304: all->logo->rect.left = 604; break;
        case 604: all->logo->rect.left = 906; break;
        case 906: all->logo->rect.left = 1250; break;
        case 1250: all->logo->rect.left = 1562; break;
        case 1562: all->logo->rect.left = 1880; break;
        case 1880: all->logo->rect.left = 8; break;
        default: all->logo->rect.left = 8; break;
        }
        sfClock_restart(anim->logoclock);
    }
    sfSprite_setTextureRect(all->logo->sprite, all->logo->rect);
}
