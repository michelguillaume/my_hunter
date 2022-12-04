/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** scenes
*/

#include "my.h"

void my_start_game(all_t *all, sfRenderWindow *window)
{
    list_t *tmp = all->list;
    sfRenderWindow_drawSprite(window, all->back_ground->sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->cloud->sprite, NULL);
    next_in_list(all, window);
    sfRenderWindow_drawSprite(window, all->life->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->shot->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->score->sprite, NULL);
    sfRenderWindow_drawText(window, all->text->text, NULL);
    sfRenderWindow_drawSprite(window, all->grass->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->border->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->lunette->sprite, NULL);
    all->list = tmp;
}

void my_start_page(all_t *all, anime_t *anim, sfRenderWindow *window)
{
    if (anim->scenes == 0){
        sfRenderWindow_drawSprite(window, all->back_ground->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->grass->sprite, NULL);
        sfRenderWindow_drawSprite(all->window, all->cloud->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->logo->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->start->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->border->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->lunette->sprite, NULL);
    }
}

void my_wait_page(all_t *all, anime_t *anim, sfRenderWindow *window)
{
    anim->starttime = sfClock_getElapsedTime(anim->startclock);
    anim->startsecond = anim->starttime.microseconds / 1000000.0;

    if (anim->scenes == 1){
        sfRenderWindow_drawSprite(window, all->back_ground->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->grass->sprite, NULL);
        sfRenderWindow_drawSprite(all->window, all->cloud->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->logo->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->start->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->border->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->lunette->sprite, NULL);
        if (anim->startsecond > 0.8){
            anim->scenes = 2;
            sfClock_restart(anim->spawnclock);
        }
    }
}

void my_lunette(all_t *all, sfRenderWindow *window)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse2 = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    mouse.x = (int){mouse2.x};
    mouse.y = (int){mouse2.y};
    all->lunette->pos2d.x = mouse.x - 31.25;
    all->lunette->pos2d.y = mouse.y - 31.25;
    sfSprite_setPosition(all->lunette->sprite, all->lunette->pos2d);
}

void my_end(all_t *all, anime_t *anim, sfRenderWindow *window)
{
    my_hight_score(all, anim);
    if (anim->life >= 10 && anim->scenes == 3){
        sfRenderWindow_drawSprite(window, all->back_ground->sprite, NULL);
        sfRenderWindow_drawSprite(window,all->laugh->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->marron->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->grass->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->cloud->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->logo->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->border->sprite, NULL);
        sfRenderWindow_drawSprite(window, all->lunette->sprite, NULL);
    }
}
        //sfRenderWindow_drawSprite(window, all->game_over->sprite, NULL);
