/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:46:38 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/22 16:46:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h> 
#include <stdlib.h>
#include "stack.h"

void	color(t_memory *mem)
{
	if (ft_strcmp(TYPE, "pa") == 0)
		RED;
	if (ft_strcmp(TYPE, "pb") == 0)
		RED;
	if (ft_strcmp(TYPE, "sa") == 0 || ft_strcmp(TYPE, "sb") == 0)
		GREEN;
	if (ft_strcmp(TYPE, "ss") == 0)
		GREEN;
	if (ft_strcmp(TYPE, "ra") == 0 || ft_strcmp(TYPE, "rb") == 0)
		YELLOW;
	if (ft_strcmp(TYPE, "rr") == 0)
		YELLOW;
	if (ft_strcmp(TYPE, "rra") == 0 || ft_strcmp(TYPE, "rrb") == 0)
		BLUE;
	if (ft_strcmp(TYPE, "rrr") == 0)
		BLUE;
}

void	print_color(int color)
{
	if (color == 0)
		ft_putstr("\033[0;37m");
	if (color == 1)
		ft_putstr("\033[0;31m");
	if (color == 2)
		ft_putstr("\033[0;32m");
	if (color == 3)
		ft_putstr("\033[0;33m");
	if (color == 4)
		ft_putstr("\033[0;36m");
	if (color == 5)
		ft_putstr("\033[1;91m");
	if (color == 6)
		ft_putstr("\033[1;92m");
	if (color == 7)
		ft_putstr("\033[1;93m");
	if (color == 8)
		ft_putstr("\033[1;96m");
	if (color == 9)
		ft_putstr("\033[1;37m");
}
