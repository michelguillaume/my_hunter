/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_call_scenes
*/

#include "my.h"

void my_call_scenes(all_t *all, anime_t *anim, sfRenderWindow *window)
{
    my_lunette(all, window);
    my_start_page(all, anim, window);
    my_wait_page(all, anim, window);
    if (anim->scenes == 2)
        my_dog_page(all, window);
    if (anim->life < 10 && anim->scenes == 3){
        my_start_game(all, window);
    }
    my_end(all, anim, window);
    sfRenderWindow_drawText(window, all->hight_score_ph->text, NULL);
    sfRenderWindow_drawText(window, all->hight_score_nbr->text, NULL);
}
