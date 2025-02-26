#include "../include/pipex.h"

void ft_putstr(const char *str)
{
    while (*str) {
        write(2, str, 1); 
        str++;             
    }
}
