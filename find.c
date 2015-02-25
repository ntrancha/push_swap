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
	if (CHAINE && ft_strlen(CHAINE) > 2)
	{
		size = ft_strlen(CHAINE);
		ret[0] = CHAINE[size - 3];
		ret[1] = CHAINE[size - 2];
		ret[2] = CHAINE[size - 1];
		ret[3] = CHAINE[size];
	}
	return (ret);
}

int     find_min(t_stack *stack, int max)
{
    t_plate *plate;

    plate = stack->end;
    while (plate)
    {
        if (TOKEN < max)
            max = TOKEN;
        plate = plate->previous;
    }
    return (max);
}

int     find_max(t_stack *stack)
{
    int     ret;
    t_plate *plate;

    ret = 0;
    plate = stack->end;
    while (plate)
    {
        if (TOKEN > ret)
            ret = TOKEN;
        plate = plate->previous;
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
        if (TOKEN == max)
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
        if (TOKEN == max)
            return (ret);
        plate = plate->previous;
        ret++;
    }
    return (ret);
}
