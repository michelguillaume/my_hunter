/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_dog_anim
*/

#include "my.h"

void my_dog_snif(all_t *all, anime_t *anim)
{
    if ((all->dog->pos3d.z >= 12 && all->dog->pos3d.z <= 18
    && anim->dogseconds > 0.15) || (all->dog->pos3d.z >= 31 &&
    all->dog->pos3d.z <= 39 && anim->dogseconds > 0.15)){
        switch (all->dog->rect.left) {
        case 0: all->dog->rect.left = 226; break;
        case 226: all->dog->rect.left = 284; break;
        case 284: all->dog->rect.left = 226; break;
        }
        all->dog->pos3d.z += 1;
        sfClock_restart(anim->dogclock);
    }
    if (all->dog->pos3d.z == 39 && anim->dogseconds > 0.1){
        all->dog->rect.left = 342;
        all->dog->pos3d.z += 1;
        sfClock_restart(anim->dogclock);
    }
}

void my_dog_walk(all_t *all, anime_t *anim)
{
    anim->dogtime = sfClock_getElapsedTime(anim->dogclock);
    anim->dogseconds = anim->dogtime.microseconds / 1000000.0;

    if ((all->dog->pos3d.z < 12 && anim->dogseconds > 0.15) ||
    (all->dog->pos3d.z >= 19 && all->dog->pos3d.z < 31
    && anim->dogseconds > 0.15)){
        switch (all->dog->rect.left) {
        case 226: all->dog->rect.left = 56; break;
        case 0: all->dog->rect.left = 56; break;
        case 56: all->dog->rect.left = 112; break;
        case 112: all->dog->rect.left = 168; break;
        case 168: all->dog->rect.left = 0; break;
        }
        all->dog->pos2d.x += 12;
        all->dog->pos3d.z += 1;
        sfClock_restart(anim->dogclock);
    }
}

void my_dog_jump(all_t *all, anime_t *anim)
{
    my_dog_fly(all, anim);
    my_dog_fall(all, anim);
}

void my_dog_anim(anime_t *anim, all_t *all)
{
    if (all->dog->pos3d.z == 96){
        anim->scenes = 3;
        sfClock_restart(anim->spawnclock);
        return;
    }
    my_dog_walk(all, anim);
    my_dog_snif(all, anim);
    my_dog_jump(all, anim);
    sfSprite_setTextureRect(all->dog->sprite, all->dog->rect);
    sfSprite_setPosition(all->dog->sprite, all->dog->pos2d);
}

void my_dog_page(all_t *all, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, all->back_ground->sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->cloud->sprite, NULL);
    if (all->dog->pos3d.z >= 58){
        sfRenderWindow_drawSprite(window, all->dog->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->grass->sprite, NULL);
    } else {
        sfRenderWindow_drawSprite(window, all->grass->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->dog->sprite, NULL);
    }
    sfRenderWindow_drawSprite(window, all->border->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->lunette->sprite, NULL);
}
