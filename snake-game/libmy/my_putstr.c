/*
** my_putstr.c for SNAKE in /home/robinet/snake/snake-game/libmy
** 
** Made by ARNAUD Hugo
** Login   <arnaud_h@etna-alternance.net>
** 
** Started on  Thu Apr  5 16:20:09 2018 ARNAUD Hugo
** Last update Thu Apr  5 16:20:11 2018 ARNAUD Hugo
*/
#include "../include/snake.h"

void    my_putstr(char * str) 
{
    int end;

    end = 0;
    while (*(str + end) != '\0') {
        char str_end;

        str_end = *(str + end);
        write(1, &str_end, 1);
        end = end + 1;
    }
}
