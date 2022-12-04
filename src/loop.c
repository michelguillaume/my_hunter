/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** loop
*/

#include "my.h"

// delta time

static sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title,
    sfClose | sfResize, NULL));
}

void my_game_event(sfEvent event, sfRenderWindow *window,
all_t *all, anime_t *anim)
{
    while (sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (anim->scenes == 3 && anim->shot < 3 &&
        anim->life < 10 &&
        event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft){
            anim->shot += 1;
            my_kill_piaf(window, all, anim);
            sfSound_play(all->shot_song->sound);
            sfSound_setPlayingOffset(all->shot_song->sound, (sfTime){800000});
        }
        my_shot_cloud(window, all, anim, event);
        if (anim->scenes == 0 && event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft)
            my_press_start(window, all, anim);
    }
}

void my_game_loop(all_t *all, anime_t *anim, sfRenderWindow *window)
{
    my_hight_score_in_game(all, anim);
    my_call_scenes(all, anim, window);
    if (anim->scenes == 0 || (anim->life >= 10 && anim->scenes == 3))
        my_logo_anim(anim, all);
    if (anim->scenes == 2)
        my_dog_anim(anim, all);
    if (anim->scenes == 3){
        my_piaf_anim(anim, all);
        my_life_anim(anim, all);
        my_shot_anim(anim, all);
    }
    my_cloud_anim(anim, all);
    my_gras_anim(anim, all);
    if (anim->life >= 10 && anim->scenes == 3)
        my_laugh_dog(anim, all);
}

void is_open_yes(all_t *all, anime_t *anim)
{
    sfEvent event;
    my_setup_anim_clock(anim);
    my_setup_anim(anim);
    all = my_def_sprites(all);
    while (sfRenderWindow_isOpen(all->window)) {
        sfRenderWindow_setFramerateLimit(all->window, 100);
        sfRenderWindow_display(all->window);
        my_game_event(event, all->window, all, anim);
        my_game_loop(all, anim, all->window);
    }
    sfRenderWindow_destroy(all->window);
    destroy(all);
}

void loop(void)
{
    srand(time(NULL));
    anime_t *anim = malloc(sizeof(anime_t));
    all_t *all = malloc(sizeof(all_t));
    all->window = create_window(1920, 1080, 32, "my_hunter");
    all->list = empty_list();
    for (int n = 0; n < 3; n++)
        all->list = add_node(all->list, 0);
    is_open_yes(all, anim);
    free_one(all);
    list_t *tmp = all->list->next;
    while (all->list != NULL) {
        tmp = all->list->next;
        free(all->list->pigeon);
        free(all->list->archi);
        free(all->list);
        all->list = tmp;
    }
    free (anim);
    free (all);
}
