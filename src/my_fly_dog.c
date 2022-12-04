/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_fly_dog
*/

#include "my.h"

void my_dog_fly(all_t *all, anime_t *anim)
{
    if (all->dog->pos3d.z == 40 && all->dog->rect.left == 342
    && anim->dogseconds > 0.45){
        all->dog->pos3d.z += 1;
        all->dog->rect.left = 400;
        all->dog->pos2d.y -= 100;
        all->dog->pos2d.x += 30;
        sfClock_restart(anim->dogclock);
    }
    if (all->dog->pos3d.z < 58 && all->dog->rect.left == 400
    && anim->dogseconds > 0.01){
        all->dog->pos2d.y -= 8;
        all->dog->pos2d.x += 4;
        all->dog->pos3d.z += 1;
        sfClock_restart(anim->dogclock);
    }
}

void my_dog_fall(all_t *all, anime_t *anim)
{
    if (all->dog->pos3d.z >= 58 && all->dog->rect.left == 400
    && anim->dogseconds > 0.01){
        all->dog->rect.left = 465;
        sfClock_restart(anim->dogclock);
    }
    if (all->dog->pos3d.z < 70 && all->dog->rect.left == 465
    && anim->dogseconds > 0.01){
        all->dog->pos2d.x += 2;
        all->dog->pos3d.z += 1;
        sfClock_restart(anim->dogclock);
    }
    if (all->dog->pos3d.z >= 70 && all->dog->pos3d.z < 96
    && anim->dogseconds > 0.01){
        all->dog->pos2d.y += 8;
        all->dog->pos2d.x += 4;
        all->dog->pos3d.z += 1;
        sfClock_restart(anim->dogclock);
    }
}
