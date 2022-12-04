/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_game_event_fonctions
*/

#include "my.h"

void my_kill_piaf(sfRenderWindow *window, all_t *all, anime_t *anim)
{
    list_t *tmp = all->list;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse2 = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    mouse.x = (int){mouse2.x};
    mouse.y = (int){mouse2.y};
    while (all->list != NULL){
        if (((mouse.x > all->list->pigeon->pos2d.x) &&
        (mouse.x < all->list->pigeon->pos2d.x + 110)) &&
        ((mouse.y > all->list->pigeon->pos2d.y) &&
        (mouse.y < all->list->pigeon->pos2d.y + 120) &&
        all->list->pigeon->pos3d.z == 0)) {
            all->list->pigeon->pos3d.z = 1;
            anim->score += 500;
            sfText_setString(all->text->text, my_itoa(anim->score));
            sfSound_play(all->quack_song->sound);
            sfSound_setPlayingOffset(all->quack_song->sound, (sfTime){100000});
        }
        all->list = all->list->next;
    }
    all->list = tmp;
}

void my_press_start(sfRenderWindow *window, all_t *all, anime_t *anim)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse2 = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    mouse.x = (int){mouse2.x};
    mouse.y = (int){mouse2.y};
    if (((mouse.x > all->start->pos2d.x) &&
    (mouse.x < all->start->pos2d.x + 370)) &&
    ((mouse.y > all->start->pos2d.y) &&
    (mouse.y < all->start->pos2d.y + 150))){
        anim->scenes = 1;
        anim->life = 0;
        all->start->rect.top = 351;
        sfClock_restart(anim->startclock);
        sfSprite_setTextureRect(all->start->sprite, all->start->rect);
    }
}

void my_setup_anim_clock_restart(anime_t *anim)
{
    sfClock_restart(anim->clock);
    sfClock_restart(anim->genclock);
    sfClock_restart(anim->sensclock);
    sfClock_restart(anim->mouvclock);
    sfClock_restart(anim->spawnclock);
    sfClock_restart(anim->fallclock_anim);
    sfClock_restart(anim->fallclock);
    sfClock_restart(anim->logoclock);
    sfClock_restart(anim->startclock);
    sfClock_restart(anim->dogclock);
    sfClock_restart(anim->cloudclock);
    sfClock_restart(anim->laughclock);
    sfClock_restart(anim->lauupclock);
}

void press_archi(sfEvent event, all_t *all, anime_t *anim, sfVector2i mouse)
{
    if (anim->life < 10 &&
        anim->scenes == 3 &&
        event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft){
            if (all->cloud->pos3d.x == 0 && ((mouse.x > all->cloud->pos2d.x) &&
            (mouse.x < all->cloud->pos2d.x + 160)) &&
            ((mouse.y > all->cloud->pos2d.y) &&
            (mouse.y < all->cloud->pos2d.y + 100))) {
                all->cloud->pos3d.x = 1;
                anim->shot -= 1;
                return;
            }
            if (all->cloud->pos3d.x != 0 && ((mouse.x > all->cloud->pos2d.x) &&
            (mouse.x < all->cloud->pos2d.x + 160)) &&
            ((mouse.y > all->cloud->pos2d.y) &&
            (mouse.y < all->cloud->pos2d.y + 100))) {
                all->cloud->pos3d.x = 0;
                anim->shot -= 1;
        }
    }
}

void my_shot_cloud(sfRenderWindow *window, all_t *all,
anime_t *anim, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse2 = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    mouse.x = (int){mouse2.x};
    mouse.y = (int){mouse2.y};
    if (anim->life >= 10 && anim->scenes == 3 && event.type ==
    sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft){
            if (((mouse.x > all->cloud->pos2d.x) &&
            (mouse.x < all->cloud->pos2d.x + 160)) &&
            ((mouse.y > all->cloud->pos2d.y) &&
            (mouse.y < all->cloud->pos2d.y + 100))) {
                my_setup_anim_clock_restart(anim);
                my_setup_anim(anim);
                all->start->rect = (sfIntRect){271,39,738,322};
                sfSprite_setTextureRect(all->start->sprite, all->start->rect);
                all->cloud->pos3d.x = 1;
                all->text->str = "000000";
                sfText_setString(all->text->text, all->text->str);
        }
    }
    press_archi(event, all, anim, mouse);
}
