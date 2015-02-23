/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:35:38 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/23 23:35:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

int			stack_cmp(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*plate_a;
	t_plate	*plate_b;

	plate_a = stack_a->end;
	plate_b = stack_b->end;
	while (plate_a || plate_b)
	{
		if (!plate_a || !plate_a->content)
			return (0);
		if (!plate_b || !plate_b->content)
			return (0);
		if (plate_a->content != plate_b->content)
			return (0);
		if (plate_a->previous)
			plate_a = plate_a->previous;
		if (plate_b->previous)
			plate_b = plate_b->previous;
	}
	return (1);
}
