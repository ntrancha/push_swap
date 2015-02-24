/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 07:31:18 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/17 07:31:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void	display(char const *str)
{
	int	index;

	index = (str[0] == ';') ? 1 : 0;
	while (str[index])
	{
		if (str[index] == ';')
			ft_putchar(' ');
		else
			ft_putchar(str[index]);
		index++;
	}
}

void	display_endl(char const *str)
{
	int	index;

	index = (str[0] == ';') ? 1 : 0;
	while (str[index])
	{
		if (str[index] == ';')
			ft_putchar(' ');
		else
			ft_putchar(str[index]);
		index++;
	}
	ft_putchar('\n');
}
