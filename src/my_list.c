/*
** EPITECH PROJECT, 2022
** MY_LS
** File description:
** my_list.c
*/

#include "my.h"

list_t *empty_list(void)
{
    return NULL;
}

list_t *create_node(void)
{
    list_t *node = malloc(sizeof(list_t));

    if (!node)
        return NULL;
    node->archi = create_sprite("asset/archi.png",
    (sfVector2f){0.6, 0.6}, (sfVector3f){1, 0, 0},
    (sfIntRect){119, 13, 563, 295});
    node->pigeon = create_sprite("asset/pigeon_fligh.png", (sfVector2f){4, 4},
    (sfVector3f){750, 750, 0}, (sfIntRect){0, 1, 35, 34});
    node->next = NULL;

    return (node);
}

list_t *add_node(list_t *L, int pos)
{
    list_t *node = create_node();
    if (L == NULL)
        return (node);
    if (pos == 0) {
        node->next = L;
        return (node);
    }
    return (node);
}

void free_list(list_t *L)
{
    list_t *tmp = NULL;
    while (L){
        tmp = L->next;
        free(L);
        L = tmp;
    }
}
