/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:44:23 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 14:44:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

t_stack         *stack_copy(t_stack *stack)
{
    t_stack     *new;
    t_plate     *plate;

    new = ft_stackcreate();
    if (!new)
        return (new);
    plate = stack->start;
    while (plate)
    {
        ft_stackadd(new, plate->content);
        plate = plate->next;
    }
    return (new);
}

t_memory        *mem_copy(t_memory *mem)
{
    t_memory    *new;

    new = malloc(sizeof(t_memory));
    if (!new)
        return (new);
    if (mem->type)
        new->type = ft_strdup(mem->type);
    else
        new->type = NULL;
    new->chaine = ft_strdup(mem->chaine);
    new->debug = mem->debug;
    new->iter = mem->iter;
    new->size = mem->size;
    new->func = NULL;
    new->stack_a = stack_copy(STACK_A);
    new->stack_b = stack_copy(STACK_B);
    return (new);
}
