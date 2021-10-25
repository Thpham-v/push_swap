#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int        random_nb(int nb)
{
    return (rand() % nb);
}

int        is_int_tab(int *tab, int size, int val)
{
    int i = 0;
    while (i < size)
    {
        if (tab[i] == val)
            return (1);
        i++;
    }
    return (0);
}

int        main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    srand(time(NULL));
    int i = 0;
    int max = atoi(av[1]);
    int val;
    int *tab;

    tab = malloc(sizeof(int) * max);
    while (i < max)
    {
        val = random_nb(max * 3);
        if (!is_int_tab(tab, i, val))
        {
            tab[i] = val;
            i++;
        }
    }
    i = 0;
    while (i < max)
    {
        printf("%d", tab[i]);
        if (i != max - 1)
            printf(" ");
        i++;
    }
    free(tab);
    return (0);
}
