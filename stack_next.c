/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:16:13 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/18 14:16:13 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int         ft_stackcontent(t_stack *stack, t_plate *plate)
{
    t_plate  *tmp;

    tmp = stack->start;
    while (tmp)
    {
        if (tmp == plate)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

static void stack_swap(t_stack *stack, t_plate *plate, t_plate *plate2)
{
    if (stack->start == plate)
        stack->start = plate2;
    else if (stack->start == plate2)
        stack->start = plate;
    if (stack->end == plate)
        stack->end = plate2;
    else if (stack->end == plate2)
        stack->end = plate;
}

static void stackswapplate2(t_stack *stack, t_plate *plate)
{
    t_plate  *prev2;
    t_plate  *next3;
    t_plate  *tmp3;

    if (stack && plate && plate->next)
    {
        tmp3 = plate->next;
        prev2 = plate->previous;
        next3 = tmp3->next;
        if (plate->previous)
            plate->previous->next = tmp3;
        else
            stack->start = tmp3;
        if (tmp3->next)
            tmp3->next->previous = plate;
        else
            stack->end = plate;
        plate->previous = tmp3;
        tmp3->next = plate;
        tmp3->previous = prev2;
        plate->next = next3;
    }
}

static void stackswapplate(t_stack *stack, t_plate *plate, t_plate *plate2)
{
    t_plate  *plate1prev;
    t_plate  *plate1next;
    t_plate  *plate2prev;
    t_plate  *plate2next;

    plate1prev = plate->previous;
    plate1next = plate->next;
    plate2prev = plate2->previous;
    plate2next = plate2->next;
    plate->next = plate2next;
    plate->previous = plate2prev;
    plate2->next = plate1next;
    plate2->previous = plate1prev;
    if (plate1prev)
        plate1prev->next = plate2;
    if (plate1next)
        plate1next->previous = plate2;
    if (plate2prev)
        plate2prev->next = plate;
    if (plate2next)
        plate2next->previous = plate;
    stack_swap(stack, plate, plate2);
}

void        ft_stackswap(t_stack *stack, t_plate *plate, t_plate *plate2)
{
    if (stack && plate && plate2 && CONTENTS(stack, plate) && CONTENTS(stack, plate2))
    {
        if (plate->next == plate2)
            stackswapplate2(stack, plate);
        else if (plate->previous == plate2)
            stackswapplate2(stack, plate2);
        else
            stackswapplate(stack, plate, plate2);
    }
}
