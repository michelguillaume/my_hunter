/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** continue_in_list
*/

#include "my.h"

void next_in_list(all_t *all, sfRenderWindow *window)
{
    while (all->list != NULL){
        if (all->cloud->pos3d.x != 0){
            sfRenderWindow_drawSprite(window, all->list->pigeon->sprite, NULL);
        } else {
            all->list->archi->pos2d.x = all->list->pigeon->pos2d.x - 100;
            all->list->archi->pos2d.y = all->list->pigeon->pos2d.y - 30;
            sfSprite_setPosition(all->list->archi->sprite,
            all->list->archi->pos2d);
            sfRenderWindow_drawSprite(all->window,
            all->list->archi->sprite, NULL);
        }
        all->list = all->list->next;
    }
}
