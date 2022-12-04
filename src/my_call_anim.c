/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_call_anim_dog
*/

#include "my.h"

sfIntRect update_grass(sfSprite *my_sprite_grass, sfIntRect rect_grass)
{
    if (rect_grass.top == 4) {
        rect_grass.top = 50;
    } else if (rect_grass.top == 50){
        rect_grass.top = 99;
    } else {
        rect_grass.top = 4;
    }

    sfSprite_setTextureRect(my_sprite_grass, rect_grass);
    return (rect_grass);
}

void my_gras_anim(anime_t *anim, all_t *all)
{
    anim->time = sfClock_getElapsedTime(anim->clock);
    anim->seconds = anim->time.microseconds / 1000000.0;
    if (anim->seconds > 0.7) {
        all->grass->rect = update_grass(all->grass->sprite, all->grass->rect);
        sfClock_restart(anim->clock);
        anim->i = 0.1;
        anim->t = 0.001;
    }
}

void set_clock_piaf(anime_t *anim)
{
    anim->gentime = sfClock_getElapsedTime(anim->genclock);
    anim->genseconds = anim->gentime.microseconds / 1000000.0;

    anim->senstime = sfClock_getElapsedTime(anim->sensclock);
    anim->senseconds = anim->senstime.microseconds / 1000000.0;

    anim->mouvtime = sfClock_getElapsedTime(anim->mouvclock);
    anim->mouseconds = anim->mouvtime.microseconds / 1000000.0;

    anim->spawntime = sfClock_getElapsedTime(anim->spawnclock);
    anim->spawnseconds = anim->spawntime.microseconds / 1000000.0;

    anim->falltime_anim = sfClock_getElapsedTime(anim->fallclock_anim);
    anim->fallseconds_anim = anim->falltime_anim.microseconds / 1000000.0;

    anim->falltime = sfClock_getElapsedTime(anim->fallclock);
    anim->fallsecond = anim->falltime.microseconds / 1000000.0;
}

void my_piaf_anim(anime_t *anim, all_t *all)
{
    list_t *tmp = all->list;
    set_clock_piaf(anim);
    if (anim->spon == 0) {
        all->list = my_piaf_spawn(all, anim);
    }
    my_check_wave_clear(anim, all);
    my_piaf_moov(anim, all);
    my_swap_pos_piaf(anim, all);
    if (all->list != NULL && anim->spawnseconds > 1.5){
        anim->nb_pigeon += 1;
        sfClock_restart(anim->spawnclock);
    }
    all->list = tmp;
    my_piaf_is_gone(anim, all);
}
