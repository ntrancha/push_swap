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

char	*find_last_code(t_memory *mem)
{
	char	*ret;
	int		size;

	ret = ft_strnew(4);
	if (mem->chaine && ft_strlen(mem->chaine) > 2)
	{
		size = ft_strlen(mem->chaine);
		ret[0] = mem->chaine[size - 3];
		ret[1] = mem->chaine[size - 2];
		ret[2] = mem->chaine[size - 1];
		ret[3] = mem->chaine[size];
	}
	return (ret);
}

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
