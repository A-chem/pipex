#include "../include/pipex.h"
void    handle_error(char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}