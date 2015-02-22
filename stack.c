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

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

t_stack		*ft_stackcreate(void)
{
    t_stack	*stack;

    stack = ft_memalloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->size = 0;
    START = NULL;
    END = NULL;
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
    TOKEN = content;
    NEXT = NULL;
    PREVIOUS = END;
    if (!END)
        START = plate;
    else
        END->next = plate;
    END = plate;
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
    TOKEN = content;
    NEXT = START;
    PREVIOUS = NULL;
    if (START)
        START->previous = plate;
    else
        END = plate;
    START = plate;
    stack->size++;
    return (stack);
}

void        ft_stackdelplate(t_stack *stack, t_plate *plate)
{
    if (stack && plate && ft_stackcontent(stack, plate))
    {
        if (PREVIOUS)
            PREVIOUS->next = NEXT;
        if (NEXT)
            NEXT->previous = PREVIOUS;
        if (END == plate)
            END = PREVIOUS;
        if (START == plate)
            START = NEXT;
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
        plate = START;
        while (plate)
        {
            tmp = NEXT;
            ft_stackdelplate(stack, plate);
            plate = tmp;
        }
    }
    free(stack);
}
