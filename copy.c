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
    plate = START;
    while (plate)
    {
        ft_stackadd(new, TOKEN);
        plate = NEXT;
    }
    return (new);
}

t_memory        *mem_copy(t_memory *mem)
{
    t_memory    *new;

    new = malloc(sizeof(t_memory));
    if (!new)
        return (new);
    if (TYPE)
        new->type = ft_strdup(TYPE);
    else
        new->type = NULL;
    new->chaine = ft_strdup(CHAINE);
    new->iter = ITER;
    new->size = SIZE;
    new->func = NULL;
	new->brute = mem->brute;
    new->stack_a = stack_copy(STACK_A);
    new->stack_b = stack_copy(STACK_B);
    return (new);
}
