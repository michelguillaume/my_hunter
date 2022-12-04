/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** my_sprites
*/

#include "my.h"

text_t *create_text(char *str, unsigned int size,
sfVector2f pos, const char* font)
{
    text_t *text = malloc(sizeof(text_t));
    text->str = malloc(sizeof(char) * 7);
    text->str[6] = '\0';
    text->str = str;
    text->text = sfText_create();
    text->font = sfFont_createFromFile(font);
    text->pos = pos;
    text->size = size;
    sfText_setCharacterSize(text->text, size);
    sfText_setFont(text->text, text->font);
    sfText_setOrigin(text->text, (sfVector2f){200, 2});
    sfText_setPosition(text->text, pos);
    sfText_setString(text->text, text->str);

    return (text);
}

hunter_t *create_sprite(char *path, sfVector2f scale, sfVector3f pos,
sfIntRect rect)
{
    hunter_t *test = malloc(sizeof(hunter_t));

    test->texture = sfTexture_createFromFile(path, NULL);
    test->sprite = sfSprite_create();
    test ->scale = scale;
    test->pos3d = pos;
    test->rect = rect;
    test->pos2d.x = pos.x;
    test->pos2d.y = pos.y;
    sfSprite_setScale(test->sprite, test->scale);
    sfSprite_setPosition(test->sprite, test->pos2d);
    sfSprite_setTextureRect(test->sprite, rect);
    sfSprite_setTexture(test->sprite, test->texture, sfFalse);

    return (test);
}

all_t *a_lot_of_sprite(all_t *all)
{
    all->lunette = create_sprite("asset/lunette_white.png",
    (sfVector2f){2.5, 2.5}, (sfVector3f){304, 680, 0},
    (sfIntRect){0, 0, 25, 25});
    all->border = create_sprite("asset/border.png",
    (sfVector2f){5.8, 4.5}, (sfVector3f){-190, 0, 0},(sfIntRect){0,0,0,0});
    all->game_over = create_sprite("asset/game_over.png",
    (sfVector2f){1, 1}, (sfVector3f){720, 200, 0},(sfIntRect){0,0,0,0});
    all->life = create_sprite("asset/life.png",
    (sfVector2f){2.5, 2.5}, (sfVector3f){630, 1000, 0},
    (sfIntRect){2408,0,239,46});
    all->logo = create_sprite("asset/logo.png",
    (sfVector2f){2, 2}, (sfVector3f){640, 50, 0},(sfIntRect){8,1,289,172});
    all->start = create_sprite("asset/start.png",
    (sfVector2f){0.5, 0.5}, (sfVector3f){760, 550, 0},
    (sfIntRect){271,39,738,322});
    all->shot = create_sprite("asset/shot.png",
    (sfVector2f){2.5, 2.5}, (sfVector3f){430, 1003, 0},
    (sfIntRect){0, 0, 61, 43});
    return (all);
}

all_t *a_lot_of_txt(all_t *all)
{
    char *buf = malloc(sizeof(char) * 7);
    buf[6] = '\0';
    int fd = open("score.txt",O_RDONLY);
    read(fd, buf, 6);
    all->text = create_text("000000", 72,
    (sfVector2f){1489, 990}, "asset/arcade.ttf");
    all->hight_score_ph = create_text("High Score ", 38,
    (sfVector2f){400, 0}, "asset/arcade.ttf");
    all->hight_score_nbr = create_text(buf, 42,
    (sfVector2f){400, 40}, "asset/arcade.ttf");
    all = a_lot_of_sound(all);
    all->archi = create_sprite("asset/archi.png",
    (sfVector2f){0.6, 0.6}, (sfVector3f){0, 0, 0},
    (sfIntRect){119, 13, 563, 295});
    return (all);
}

all_t *my_def_sprites(all_t *all)
{
    all->back_ground = create_sprite("asset/back_ground.png",
    (sfVector2f){5.8, 4.5}, (sfVector3f){-190, 0, 0},(sfIntRect){0,0,0,0});
    all->marron = create_sprite("asset/marron.png",
    (sfVector2f){5.8, 4.5}, (sfVector3f){181, 905, 0},(sfIntRect){0,0,0,0});
    all->grass = create_sprite("asset/grass.png", (sfVector2f){5.8, 4.5},
    (sfVector3f){181, 750, 0}, (sfIntRect){1, 4, 256, 41});
    all->dog = create_sprite("asset/dog.png", (sfVector2f){4.75, 4.5},
    (sfVector3f){304, 720, 0}, (sfIntRect){0, 9, 56, 51});
    all->score = create_sprite("asset/score.png", (sfVector2f){2.5, 2.5},
    (sfVector3f){1270, 1003, 0}, (sfIntRect){0, 1, 109, 43});
    all->cloud = create_sprite("asset/cloud.png",
    (sfVector2f){2, 2}, (sfVector3f){0, 0, 0},(sfIntRect){0, 0, 67, 53});
    all->cloud->pos3d.x = 1;
    all->laugh = create_sprite("asset/laugh.png",
    (sfVector2f){4.75, 4.5}, (sfVector3f){860, 750, 0},
    (sfIntRect){0, 0, 39, 54});
    all = a_lot_of_sprite(all);
    all = a_lot_of_txt(all);
    return (all);
}
