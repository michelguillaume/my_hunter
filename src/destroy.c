/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** destroy
*/

#include "my.h"

void free_one(all_t *all)
{
    free(all->archi);
    free(all->back_ground);
    free(all->border);
    free(all->cloud);
    free(all->dog);
    free(all->game_over);
    free(all->grass);
    free(all->hight_score_nbr);
    free(all->hight_score_ph);
    free(all->laugh);
    free(all->life);
    free(all->logo);
    free(all->lunette);
    free(all->marron);
    free(all->over_song);
    free(all->quack_song);
    free(all->score);
    free(all->shot);
    free(all->start);
    free(all->text);
}

void destroy_sprite(all_t *all)
{
    list_t *tmp = all->list;
    sfSprite_destroy(all->back_ground->sprite);
    sfSprite_destroy(all->border->sprite);
    sfSprite_destroy(all->cloud->sprite);
    sfSprite_destroy(all->dog->sprite);
    sfSprite_destroy(all->game_over->sprite);
    sfSprite_destroy(all->grass->sprite);
    sfSprite_destroy(all->laugh->sprite);
    sfSprite_destroy(all->life->sprite);
    sfSprite_destroy(all->logo->sprite);
    sfSprite_destroy(all->lunette->sprite);
    sfSprite_destroy(all->marron->sprite);
    sfSprite_destroy(all->start->sprite);
    sfSprite_destroy(all->shot->sprite);
    while (all->list != NULL){
        sfSprite_destroy(all->list->pigeon->sprite);
        sfSprite_destroy(all->list->archi->sprite);
        all->list = all->list->next;
    }
    all->list = tmp;
}

void destroy(all_t *all)
{
    destroy_sprite(all);
    sfText_destroy(all->text->text);
    sfSound_destroy(all->shot_song->sound);
    sfSound_destroy(all->over_song->sound);
    sfSound_destroy(all->quack_song->sound);
}
