/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:58:24 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/18 13:58:24 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack		*ft_stackcreate(void)
{
    t_stack	*stack;

    stack = ft_memalloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->size = 0;
    stack->start = NULL;
    stack->end = NULL;
    return (stack);
}

t_stack		*ft_stackadd(t_stack *stack, int content)
{
    t_plate	*plate;

    if (!stack)
        stack = ft_stackcreate();
    plate = ft_memalloc(sizeof(t_plate));
    if (!plate) 
        return (NULL);
    plate->content = content;
    plate->next = NULL;
    plate->previous = stack->end;
    if (!stack->end)
        stack->start = plate;
    else
        stack->end->next = plate;
    stack->end = plate;
    stack->size++;
    return (stack);
}

t_stack		*ft_stackaddfirst(t_stack *stack, int content)
{
    t_plate	*plate;

    if (!stack)
        stack = ft_stackcreate();
    plate = ft_memalloc(sizeof(t_plate));
    if (!plate) 
        return (NULL);
    plate->content = content;
    plate->next = stack->start;
    plate->previous = NULL;
    if (stack->start)
        stack->start->previous = plate;
    else
        stack->end = plate; 
    stack->start = plate;
    stack->size++;
    return (stack);
}

void        ft_stackdelplate(t_stack *stack, t_plate *plate)
{
    if (stack && plate && ft_stackcontent(stack, plate))
    {
        if (plate->previous)
            plate->previous->next = plate->next;
        if (plate->next)
            plate->next->previous = plate->previous;
        if (stack->end == plate)
            stack->end = plate->previous;
        if (stack->start == plate)
            stack->start = plate->next;
        stack->size--;
        ft_memdel((void**)&plate);
    }
}

void        ft_stackdel(t_stack *stack)
{
    t_plate  *plate;
    t_plate  *tmp;

    if (stack)
    {
        plate = stack->start;
        while (plate)
        {
            tmp = plate->next;
            ft_stackdelplate(stack, plate);
            plate = tmp;
        }
    }
    ft_memdel((void**)&stack);
}
