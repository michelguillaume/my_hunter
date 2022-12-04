/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_setup_anim
*/

#include "my.h"

void my_setup_anim_clock(anime_t *anim)
{
    anim->clock = sfClock_create();
    anim->genclock = sfClock_create();
    anim->sensclock = sfClock_create();
    anim->mouvclock = sfClock_create();
    anim->spawnclock = sfClock_create();
    anim->fallclock_anim = sfClock_create();
    anim->fallclock = sfClock_create();
    anim->logoclock = sfClock_create();
    anim->startclock = sfClock_create();
    anim->dogclock = sfClock_create();
    anim->cloudclock = sfClock_create();
    anim->laughclock = sfClock_create();
    anim->lauupclock = sfClock_create();
}

void my_setup_anim(anime_t *anim)
{
    char *buf = malloc(sizeof(char) * 7);
    buf[6] = '\0';
    int fd = open("score.txt", O_RDWR);
    read(fd, buf, 6);
    anim->oldscore = my_str_to_nbr(buf);
    anim->spon = 0;
    anim->nb_pigeon = 1;
    anim->wave = 1;
    anim->life = 0;
    anim->scenes = 0;
    anim->shot = 0;
    anim->score = 0;
}
