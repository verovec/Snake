/*
** my_putchar.c for SNAKE in /home/robinet/snake/snake-game/libmy
** 
** Made by ARNAUD Hugo
** Login   <arnaud_h@etna-alternance.net>
** 
** Started on  Thu Apr  5 16:19:44 2018 ARNAUD Hugo
** Last update Thu Apr  5 16:19:46 2018 ARNAUD Hugo
*/
#include "../include/snake.h"

void    my_putchar(char c)
{
    write(1, &c, 1);
}
