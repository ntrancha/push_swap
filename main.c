/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 07:31:18 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/17 07:31:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			test_double_after(int point, int size, char **tab)
{
	char	*test;

	test = tab[point++];
	while (point <= size)
		if (ft_strcmp(test, tab[point++]) == 0)
			return (0);
	return (1);
}

int		test_double(int point, int size, char **tab)
{
	while (point < size)
		if (test_double_after(point++, size, tab) == 0)
			return (0);
	return (1);
}

void	error()
{
		ft_putendl_fd("Error", 2);
}

int		verif(int size, char **tab)
{
	char	*num;

	num = tab[size--];
	if (ft_strisnum(num) == 0)
		return (0);
	if (size == 0)
		return (1);
	return (verif(size, tab));
}

int		push_swap(int size, char **tab)
{
	if (verif(size, tab) == 0 || test_double(1, size, tab) == 0)
		error();
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		error();
	else
		push_swap((argc - 1),argv);
	return (0);
}
