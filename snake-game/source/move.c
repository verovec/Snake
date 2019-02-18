/*
** move.c for SNAKE in /home/robinet/snake/snake-game/source
** 
** Made by ARNAUD Hugo
** Login   <arnaud_h@etna-alternance.net>
** 
** Started on  Thu Apr  5 16:21:25 2018 ARNAUD Hugo
** Last update Thu Apr  5 16:21:26 2018 ARNAUD Hugo
*/

#include "../include/snake.h"

int            direction(t_list *list, char t, int location_x, int location_y, int col, int row, char arr[][col])
{
    int         bx;
    int         by;
    t_snake     *e;

    bx = 0;
    by = 0;
    
    if (arr[location_x][location_y] == '1' || arr[location_x][location_y] == 's')
    {
        my_putstr("Vous êtes mort.\n");
        return (1);
    }
    if (location_x > (row - 1) || location_x < 0 || location_y > (col - 1) || location_y < 0)
    {
        my_putstr("Vous êtes mort.\n");
        return (1);
    }
    if (arr[location_x][location_y] == 'b')
    {
        put_rand_bonus(col, row, arr);
        snake_add(list, t);
    }
    if (arr[location_x][location_y] == 'm')
    {
        put_rand_malus(col, row, arr);
        if(!snake_rm_last(list))
            return (0);
    }
    e = list->last;
    while (e && list->first != e)
    {
        e->location_x = e->prev->location_x;
        e->location_y = e->prev->location_y;
        e->next_x = e->prev->next_x;
        e->next_y = e->prev->next_y;
        e = e->prev;
    }
    e = list->first;

    e->next_x = e->location_x;
    e->next_y = e->location_y;
    e->location_x = location_x;
    e->location_y = location_y;
    snake_in_map(list, col, arr);
    return (0);
}

void            move(t_list *list, int col, int row, char arr[][col])
{
    char        t;
    int         v;
    t_snake     *e;

    t = '\0';

    while (t != 'q')
    {
        e = list->first;

        my_putstr("\033c\n");
        if (t == 'd')
            if (direction(list, t, e->location_x, e->location_y + 1, col, row, arr))
                return;
        if (t == 'a')
            if (direction(list, t, e->location_x, e->location_y - 1, col, row, arr))
                return;
        if (t == 'w')
            if (direction(list, t, e->location_x - 1, e->location_y, col, row, arr))
                return;
        if (t == 's')
            if (direction(list, t, e->location_x + 1, e->location_y, col, row, arr))
                return;
        aff_map(col, row, arr);
        v = list->size;
        my_putstr("Votre score : ");
        my_put_nbr(v);
        my_putstr("\n");
        t = readline();
    }
}
