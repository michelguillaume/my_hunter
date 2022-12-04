/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my
*/

#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/JoystickIdentification.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Window/Export.h>
#include <unistd.h>

#include <string.h>
#include <fcntl.h>

typedef struct hunter_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfIntRect rect;
    sfVector2f pos2d;
    sfVector3f pos3d;
    int t;
    // tmp :
    // sfFloatRect hitbox;
}hunter_t;

typedef struct text_s{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *str;
    unsigned int size;
}text_t;

typedef struct sound_s{
    sfSound *sound;
    int i;
}sound_t;


typedef struct list_s {
    hunter_t *pigeon;
    hunter_t *archi;
    struct list_s *next;
}list_t;


typedef struct all_s{
    hunter_t *dog;
    hunter_t *back_ground;
    hunter_t *border;
    hunter_t *game_over;
    hunter_t *life;
    hunter_t *grass;
    hunter_t *lunette;
    hunter_t *logo;
    hunter_t *start;
    hunter_t *shot;
    hunter_t *score;
    hunter_t *cloud;
    hunter_t *laugh;
    hunter_t *marron;
    hunter_t *archi;
    text_t *text;
    text_t *hight_score_ph;
    text_t *hight_score_nbr;
    sound_t *over_song;
    sound_t *shot_song;
    sound_t *quack_song;
    list_t *list;
    sfRenderWindow *window;
}all_t;

typedef struct anim_s{
    sfClock *clock;
    sfClock *genclock;
    sfClock *sensclock;
    sfClock *mouvclock;
    sfClock *spawnclock;
    sfClock *fallclock_anim;
    sfClock *fallclock;
    sfClock *logoclock;
    sfClock *startclock;
    sfClock *dogclock;
    sfClock *cloudclock;
    sfClock *laughclock;
    sfClock *lauupclock;
    sfTime time;
    sfTime gentime;
    sfTime senstime;
    sfTime mouvtime;
    sfTime spawntime;
    sfTime falltime_anim;
    sfTime falltime;
    sfTime logotime;
    sfTime starttime;
    sfTime dogtime;
    sfTime cloudtime;
    sfTime laughtime;
    sfTime lauuptime;
    int nb_pigeon;
    float seconds;
    float genseconds;
    float senseconds;
    float mouseconds;
    float spawnseconds;
    float fallseconds_anim;
    float fallsecond;
    float logosecond;
    float startsecond;
    float dogseconds;
    float cloudseconds;
    float laughseconds;
    float lauupseconds;
    int shot;
    int score;
    float i;
    float t;
    int life;
    int nb;
    int test;
    int spon;
    float wave;
    int scenes;
    int oldscore;
}anime_t;

void my_start_game(all_t *all, sfRenderWindow *window);
void my_after_dog(all_t *all, sfRenderWindow *window, anime_t *anim);

void my_dog_walk(all_t *all, anime_t *anim);
void my_dog_jump(all_t *all, anime_t *anim);
void my_gras_anim(anime_t *anim, all_t *all);
void my_dog_fall(all_t *all, anime_t *anim);
void my_dog_fly(all_t *all, anime_t *anim);


sfIntRect update_grass(sfSprite *my_sprite_grass, sfIntRect rect_grass);

//hunter_t *wolk_dog(hunter_t *dog, int *nb);
void my_dog_snif(all_t *all, anime_t *anim);

all_t *my_def_sprites(all_t *all);
void my_first_part(hunter_t *dog);
void my_second_part(hunter_t *dog);
void my_piaf_anim(anime_t *anim, all_t *all);

list_t *add_node(list_t *L, int pos);

hunter_t *create_sprite(char *path, sfVector2f scale,
sfVector3f pos,sfIntRect rect);

list_t *empty_list(void);

void my_swap_orient(all_t *all);
list_t *my_piaf_spawn(all_t *all, anime_t *anim);

text_t *create_text(char *txt, unsigned int size,
sfVector2f pos, const char* font);



void my_mouv_upright(all_t *all, anime_t *anim);
void my_mouv_upleft(all_t *all, anime_t *anim);
void my_mouv_right(all_t *all, anime_t *anim);
void my_mouv_left(all_t *all, anime_t *anim);
void dead_pos(all_t *all);
void dead_fall(all_t *all, anime_t *anim);
void my_life_anim(anime_t *anim, all_t *all);
void my_logo_anim(anime_t *anim, all_t *all);

void my_start_page(all_t *all, anime_t *anim, sfRenderWindow *window);

void my_wait_page(all_t *all, anime_t *anim, sfRenderWindow *window);

void my_lunette(all_t *all, sfRenderWindow *window);
void my_end(all_t *all, anime_t *anim, sfRenderWindow *window);

void my_kill_piaf(sfRenderWindow *window, all_t *all, anime_t *anim);

void my_press_start(sfRenderWindow *window, all_t *all, anime_t *anim);
void check_gone(anime_t *anim, all_t *all);
void my_piaf_is_gone(anime_t *anim, all_t *all);
void my_piaf_anim_dead(all_t *all);
void my_piaf_moov_alive(anime_t *anim, all_t *all);
void my_swap_pos_piaf(anime_t *anim, all_t *all);
void my_swap_pos(all_t *all, int old);
void my_piaf_moov(anime_t *anim, all_t *all);
void my_check_wave_clear(anime_t *anim, all_t *all);
void my_piaf_is_dead(anime_t *anim, all_t *all);
void my_shot_anim(anime_t *anim, all_t *all);
char *my_itoa(int num);
void my_dog_anim(anime_t *anim, all_t *all);
void my_dog_page(all_t *all, sfRenderWindow *window);
void my_cloud_anim(anime_t *anim, all_t *all);
void my_call_scenes(all_t *all, anime_t *anim, sfRenderWindow *window);
void my_laugh_dog(anime_t *anim, all_t *all);
void my_setup_anim(anime_t *anim);
void my_setup_anim_clock(anime_t *anim);
all_t *a_lot_of_sound(all_t *all);
sound_t *create_sound(char *path, sfBool loop,
float pitch, sfVector3f position);
int my_strcmp (char const *str1, char const *str2);
void destroy(all_t *all);
void loop(void);
char * my_rev_str(char *str);
int my_strlen (char const *str);
int my_str_to_nbr(char *str);
void my_hight_score(all_t *all, anime_t *anim);
void my_shot_cloud(sfRenderWindow *window, all_t *all,
anime_t *anim, sfEvent event);
void next_in_list(all_t *all, sfRenderWindow *window);
void free_one(all_t *all);
void my_hight_score_in_game(all_t *all, anime_t *anim);
