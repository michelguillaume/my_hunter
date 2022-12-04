/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_cloud_anim
*/

#include "my.h"

void my_cloud_anim(anime_t *anim, all_t *all)
{
    anim->cloudtime = sfClock_getElapsedTime(anim->cloudclock);
    anim->cloudseconds = anim->cloudtime.microseconds / 1000000.0;

    if (all->cloud->pos3d.z == 0){
        all->cloud->pos2d.y = 0 + rand() % 300;
        all->cloud->pos2d.x = 0;
        all->cloud->pos3d.z += 1;
    }
    if (anim->cloudseconds > 0.01){
        all->cloud->pos2d.x += 1;
        sfClock_restart(anim->cloudclock);
    }
    if (all->cloud->pos2d.x > 1800){
        all->cloud->pos3d.z = 0;
    }
    sfSprite_setPosition(all->cloud->sprite, all->cloud->pos2d);
}
