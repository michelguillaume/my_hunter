/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_mouv_piaf
*/

#include "my.h"

void my_mouv_left(all_t *all, anime_t *anim)
{
    if (all->list->pigeon->t == 0){
        if (anim->senseconds > 0.15){
            switch (all->list->pigeon->rect.left){
            case 114: all->list->pigeon->rect.left = 189; break;
            case 189: all->list->pigeon->rect.left = 153; break;
            case 153: all->list->pigeon->rect.left = 114; break;
            }
            sfClock_restart(anim->sensclock);
        }
        if (anim->mouseconds > (0.05 - (0.002 * anim->wave))) {
            all->list->pigeon->pos2d.x = all->list->pigeon->pos2d.x - 12;
            all->list->pigeon->pos2d.y = all->list->pigeon->pos2d.y - 12;
            sfClock_restart(anim->mouvclock);
        }
    }
}

void my_mouv_right(all_t *all, anime_t *anim)
{
    if (all->list->pigeon->t == 1){
        if (anim->senseconds > 0.15){
            switch (all->list->pigeon->rect.left) {
            case 69: all->list->pigeon->rect.left = -2; break;
            case -2: all->list->pigeon->rect.left = 35; break;
            case 35: all->list->pigeon->rect.left = 69; break;
            }
            sfClock_restart(anim->sensclock);
        }
        if (anim->mouseconds > (0.05 - (0.002 * anim->wave))) {
            all->list->pigeon->pos2d.x = all->list->pigeon->pos2d.x + 12;
            all->list->pigeon->pos2d.y = all->list->pigeon->pos2d.y - 12;
            sfClock_restart(anim->mouvclock);
        }
    }
}

void my_mouv_upleft(all_t *all, anime_t *anim)
{
    if (all->list->pigeon->t == 2){
        if (anim->senseconds > 0.15){
            switch (all->list->pigeon->rect.left) {
            case 1: all->list->pigeon->rect.left = 76; break;
            case 76: all->list->pigeon->rect.left = 38; break;
            case 38: all->list->pigeon->rect.left = 1; break;
            }
            sfClock_restart(anim->sensclock);
        }
        if (anim->mouseconds > (0.05 - (0.002 * anim->wave))) {
            all->list->pigeon->pos2d.x = all->list->pigeon->pos2d.x - 12;
            sfClock_restart(anim->mouvclock);
        }
    }
}

void my_mouv_upright(all_t *all, anime_t *anim)
{
    if (all->list->pigeon->t == 3){
        if (anim->senseconds > 0.15){
            switch (all->list->pigeon->rect.left) {
            case 179: all->list->pigeon->rect.left = 104; break;
            case 104: all->list->pigeon->rect.left = 142; break;
            case 142: all->list->pigeon->rect.left = 179; break;
            }
            sfClock_restart(anim->sensclock);
        }
        if (anim->mouseconds > (0.05 - (0.002 * anim->wave))) {
            all->list->pigeon->pos2d.x = all->list->pigeon->pos2d.x + 12;
            sfClock_restart(anim->mouvclock);
        }
    }
}
