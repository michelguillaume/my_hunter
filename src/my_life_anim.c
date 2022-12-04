/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_life_anim
*/

#include "my.h"

void my_life_anim(anime_t *anim, all_t *all)
{
    all->life->rect.left = 2408 - (238 * anim->life);
    sfSprite_setTextureRect(all->life->sprite, all->life->rect);
}

void my_shot_anim(anime_t *anim, all_t *all)
{
    if (anim->shot <= 3)
        all->shot->rect.left = 0 + (62 * anim->shot);
    sfSprite_setTextureRect(all->shot->sprite, all->shot->rect);
}
