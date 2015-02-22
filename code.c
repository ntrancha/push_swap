/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 14:49:31 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/22 14:49:31 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h> 
#include <stdlib.h>
#include "stack.h"

int			is_code(char *code)
{
	if (ft_strcmp(code, "pa") == 0)
		return (1);
	if (ft_strcmp(code, "pb") == 0)
		return (1);
	if (ft_strcmp(code, "sa") == 0)
		return (1);
	if (ft_strcmp(code, "sb") == 0)
		return (1);
	if (ft_strcmp(code, "ss") == 0)
		return (1);
	if (ft_strcmp(code, "ra") == 0)
		return (1);
	if (ft_strcmp(code, "rb") == 0)
		return (1);
	if (ft_strcmp(code, "rr") == 0)
		return (1);
	if (ft_strcmp(code, "rra") == 0)
		return (1);
	if (ft_strcmp(code, "rrb") == 0)
		return (1);
	if (ft_strcmp(code, "rrr") == 0)
		return (1);
	return (0);
}

int			is_commande(char **tab)
{
	int		index;

	index = 0;
	while (tab[index])
		if (!is_code(tab[index++]))
			return (0);
	return (1);
}

void		exec_code(char **tab, t_memory *mem)
{
	int		index;

	index = 0;
	while (tab[index])
		swap_swap(mem, tab[index++]);
}

int			post_code(t_memory *mem)
{
	char	**tab;

	tab = ft_strsplit(COMMANDE, ';');
	if (COMMANDE == NULL || !is_commande(tab))
	{
		error();
		return (0);
	}
	exec_code(tab, mem);
	return (1);
}
