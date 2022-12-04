/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_sprites_sound
*/

#include "my.h"

sound_t *create_sound(char *path, sfBool loop,
float volume, sfVector3f position)
{
    sound_t *sng = malloc(sizeof(sound_t));
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);

    sng->sound = sfSound_create();
    sng->i = 0;
    sfSound_setBuffer(sng->sound, buffer);
    sfSound_setLoop(sng->sound, loop);
    sfSound_setVolume(sng->sound, volume);
    sfSound_setPosition(sng->sound, position);

    return (sng);
}

all_t *a_lot_of_sound(all_t *all)
{
    all->over_song = create_sound("asset/over.wav", sfFalse,
    100.00, (sfVector3f){0, 0, 0});
    all->shot_song = create_sound("asset/shot.wav", sfFalse,
    100.00, (sfVector3f){0, 0, 0});
    all->quack_song = create_sound("asset/quack.wav", sfFalse,
    100.00, (sfVector3f){0, 0, 0});

    return (all);
}
