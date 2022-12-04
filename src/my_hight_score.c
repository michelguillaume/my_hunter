/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_hight_score
*/

#include "my.h"

void my_hight_score(all_t *all, anime_t *anim)
{
    if (anim->life >= 10 && anim->scenes == 3 && all->over_song->i == 0){
        char *buf = malloc(sizeof(char) * 7);
        buf[6] = '\0';
        int fd = open("score.txt", O_RDWR);
        read(fd, buf, 6);
        int oldscore = my_str_to_nbr(buf);
        fd = open("score.txt", O_RDWR | O_TRUNC);
        if (anim->score > oldscore){
            write(fd, my_itoa(anim->score),
            my_strlen((my_itoa(anim->score))));
        } else {
            write(fd, buf,
            my_strlen(buf));
        }
        close(fd);
        sfSound_play(all->over_song->sound);
        sfSound_setPlayingOffset(all->over_song->sound, (sfTime){1000000});
        all->over_song->i = 1;
    }
}

void my_hight_score_in_game(all_t *all, anime_t *anim)
{
    if (anim->score > anim->oldscore){
        all->hight_score_nbr->str = my_itoa(anim->score);
        sfText_setString(all->hight_score_nbr->text, all->hight_score_nbr->str);
    }
}
