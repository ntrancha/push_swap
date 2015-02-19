/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:46:49 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 14:46:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

int         test_double_after(int point, int size, char **tab)
{
    char    *test;

    test = tab[point++];
    while (point <= size)
        if (ft_strcmp(test, tab[point++]) == 0)
            return (0);
    return (1);
}

int     test_double(int point, int size, char **tab)
{
    while (point < size)
        if (test_double_after(point++, size, tab) == 0)
            return (0);
    return (1);
}

int     is_middle(t_memory *mem)
{
    int size;

    size = (STACK_A->size + STACK_B->size) / 2;
    if (STACK_A->size - 1 <= size && STACK_B->size - 1 <= size)
        return 1;
    return (0);
}

int     is_unsort(t_stack *stack)
{
    int     min;
    t_plate *plate;

    plate = stack->start;
    min = plate->content;
    plate = plate->next;
    while (plate)
    {
        if (plate->content > min)
            min = plate->content;
        else
            return (0);
        plate = plate->next;
    }
    return (1);
}

int     is_sort(t_stack *stack)
{
    int     max;
    t_plate *plate;

    plate = stack->start;
    max = plate->content;
    plate = plate->next;
    while (plate)
    {
        if (plate->content < max)
            max = plate->content;
        else
            return (0);
        plate = plate->next;
    }
    return (1);
}
