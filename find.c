/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:02:50 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 15:02:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

int     find_min(t_stack *stack, int max)
{
    t_plate *plate;

    plate = stack->start;
    while (plate)
    {
        if (plate->content < max)
            max = plate->content;
        plate = plate->next;
    }
    return (max);
}

int     find_max(t_stack *stack)
{
    int     ret;
    t_plate *plate;

    ret = 0;
    plate = stack->start;
    while (plate)
    {
        if (plate->content > ret)
            ret = plate->content;
        plate = plate->next;
    }
    return (ret);
}

int     find_jump_start(t_stack *stack, int max)
{
    t_plate *plate;
    int     ret;

    plate = stack->start;
    ret = 0;
    while (plate)
    {
        if (plate->content == max)
            return (ret);
        plate = plate->next;
        ret++;
    }
    return (ret);
}

int     find_jump_end(t_stack *stack, int max)
{
    t_plate *plate;
    int     ret;

    plate = stack->end;
    ret = 0;
    while (plate)
    {
        if (plate->content == max)
            return (ret);
        plate = plate->previous;
        ret++;
    }
    return (ret);
}
