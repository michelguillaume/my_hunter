/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** main
*/

#include "my.h"

    // if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace){
    //     printf("space\n");
    // }
    // if (sfJoystick_isConnected(event.joystickConnect.joystickId) == sfTrue)
    //     if (sfJoystick_isButtonPressed
//    (event.joystickConnect.joystickId, sfJoystickX) == sfTrue)
    //         printf("X")
    // if (sfJoystick_isConnected(event.joystickConnect.joystickId) == sfTrue){
    // manette.x = sfJoystick_getAxisPosition
//    (event.joystickConnect.joystickId, sfJoystickU);
    // manette.y = sfJoystick_getAxisPosition
//    (event.joystickConnect.joystickId, sfJoystickV);
    // printf("%f | %f\n", manette.x, manette.y);
    // if (manette.x == 100){
    //     all->lunette->pos2d.x = 10 - 31.25;
    //     printf("bouge connard");
    //     sfSprite_setPosition(all->lunette->sprite, all->lunette->pos2d);
    // }

int main(int ac, char **av)
{
    for (int i = 0; av[i]; i++){
        if (my_strcmp(av[i], "-h") == 0){
            write(1, "Duck Hunt:\n", 11);
            write(1, "Jeu de tir en vue subjective dans lequel", 10);
            write(1, " l'objectif est de toucher des cibles mouvantes.\n", 50);
            write(1, "Chaque vague consiste en un total de trois cibles ", 51);
            write(1, "à toucher.\nLe joueur dispose de trois ", 40);
            write(1,"essais pour les toucher avant qu'elles ne ", 43);
            write(1, "disparaissent.\nLe joueur a pour but ", 37);
            write(1, "de réussir à tirer sur le plus de cibles ", 44);
            write(1, "possible.\nAinsi, l'échec se soldera par ", 41);
            write(1, "un game over mettant fin à la partie.\n", 39);
            write(1, "La difficulté augmente au fur et à mesure ", 45);
            write(1, "que le joueur avance dans les waves.\n", 38);
            return (0);
        }
    }
    loop();
    return (0);
}
