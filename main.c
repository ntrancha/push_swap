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
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

int		main(int argc, char **argv)
{
	t_memory	*mem;

	if (argc == 1 && !error())
		return (-1);
	mem = get_arg((argc - 1), argv);
	if (!mem)
		return (0);
	ORIGINE = stack_copy(STACK_A);
	if (PRINT)
		print(mem);
	if (DEBUG)
		action_first_print(mem);
	if (POST_CODE)
		if (!post_code(mem))
			return (0);
	if (!FORCE && !NOTHING)
		action_sort(mem);
	else if (!NOTHING)
		action_brute(mem);
	return (1);
}
