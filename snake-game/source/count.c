/*
** count.c for SNAKE in /home/robinet/snake/snake-game/source
** 
** Made by ARNAUD Hugo
** Login   <arnaud_h@etna-alternance.net>
** 
** Started on  Thu Apr  5 16:20:31 2018 ARNAUD Hugo
** Last update Thu Apr  5 16:20:33 2018 ARNAUD Hugo
*/
#include "../include/snake.h"

int     count_x(char *c)
{
    int i;
    
    i = 0;
    while (c[i] != '\n')
        i++;
    return i;
}

int     count_y(char *c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (c[i] != '\0')
    {
        if (c[i] == '\n')
            count++;
        i++;
    }
    return count;
}
