/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** dead
*/

#include "my.h"

void dead_pos_0(all_t *all)
{
    all->list->pigeon->rect.height = 106 - 74;
    all->list->pigeon->rect.left = 0;
    all->list->pigeon->rect.top = 74;
    all->list->pigeon->rect.width = 36;
}

void dead_pos_1(all_t *all)
{
    all->list->pigeon->rect.height = 106 - 74;
    all->list->pigeon->rect.left = 38;
    all->list->pigeon->rect.top = 74;
    all->list->pigeon->rect.width = 36;
}

void dead_pos(all_t *all)
{
    if (all->list->pigeon->t == 0){
        dead_pos_0(all);
    }
    if (all->list->pigeon->t == 1){
        dead_pos_1(all);
    }
    if (all->list->pigeon->t == 2){
        all->list->pigeon->rect.height = 106 - 74;
        all->list->pigeon->rect.left = 78;
        all->list->pigeon->rect.top = 74;
        all->list->pigeon->rect.width = 36;
    }
    if (all->list->pigeon->t == 3){
        all->list->pigeon->rect.height = 106 - 74;
        all->list->pigeon->rect.left = 116;
        all->list->pigeon->rect.top = 74;
        all->list->pigeon->rect.width = 36;
    }
}

void dead_fall(all_t *all, anime_t *anim)
{
    if (all->list->pigeon->rect.top == 74){
        all->list->pigeon->rect.height = 142 - 111;
        all->list->pigeon->rect.left = 4;
        all->list->pigeon->rect.top = 111;
        all->list->pigeon->rect.width = 19;
    }
    if (anim->fallseconds_anim > 0.1){
        switch (all->list->pigeon->rect.left){
        case 4: all->list->pigeon->rect.left = 33; break;
        case 33: all->list->pigeon->rect.left = 84; break;
        case 84: all->list->pigeon->rect.left = 59; break;
        case 59: all->list->pigeon->rect.left = 4; break;
        default: break;
        }
        sfClock_restart(anim->fallclock_anim);
    }
    if (anim->fallsecond > 0.01){
        all->list->pigeon->pos2d.y = all->list->pigeon->pos2d.y + 9;
        sfClock_restart(anim->fallclock);
    }
}
