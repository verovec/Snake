/*
** rand.c for SNAKE in /home/robinet/snake/snake-game/source
** 
** Made by ARNAUD Hugo
** Login   <arnaud_h@etna-alternance.net>
** 
** Started on  Thu Apr  5 16:21:35 2018 ARNAUD Hugo
** Last update Thu Apr  5 16:21:37 2018 ARNAUD Hugo
*/
#include "../include/snake.h"

void    put_rand_bonus(int col, int row, char arr[][col])
{
    int bx;
    int by;

    bx = 0;
    by = 0;

    while (arr[bx][by] == '1' || arr[bx][by] == 's' || arr[bx][by] == 'm')
    {
        srandom(time(NULL));
        bx = MY_RAND(1, row - 2);
        by = MY_RAND(1, col - 2);
    }
    arr[bx][by] = 'b';
}

void    put_rand_malus(int col, int row, char arr[][col])
{
    int bx;
    int by;

    bx = 0;
    by = 0;

    while (arr[bx][by] == '1' || arr[bx][by] == 's' || arr[bx][by] == 'b')
    {
        srandom(time(NULL));
        bx = MY_RAND(1, row - 2);
        by = MY_RAND(1, col - 2);
    }
    arr[bx][by] = 'm';
}
