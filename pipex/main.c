#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
int main (int ac, char **av, char **envp)
{
    int i = 0;
    while (envp[i])
    {
        printf ("%s\n", envp[i]);
        i++;
    }
    
}