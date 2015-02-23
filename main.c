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

void	trie(t_memory *mem)
{
	int		min;
	int		max;
	int		sort_a;
	int		sort_b;
	int		count;
	int		mid;

	count = 0;
	while (count++ < 100 && (SIZE_B || count < 5))
	{
		max = find_max(STACK_A);
		min = find_min(STACK_A, max);
		sort_a = 0;
		sort_b = 0;
		mid = 0;
		if (is_sort(STACK_A))
			sort_a = 1;
		if (SIZE_B && is_unsort(STACK_B))
			sort_b = 1;
		if (is_middle(mem))
			mid = 1;
		if (SIZE_B > 1 && TOKEN_B < NEXT_B->content)
		{
			swap_swap(mem, "sb");
			swap_swap(mem, "pa");
		}
		else if (SIZE_B > 1 && TOKEN_B < END_B->content)
			swap_swap(mem, "rrb");
		else if (TOKEN_A == min && !sort_a)
			swap_swap(mem, "pb");
		else if (NEXT_A && TOKEN_A > NEXT_A->content)
			swap_swap(mem, "sa");
		else if (TOKEN_A > END_A->content)
			swap_swap(mem, "rra");
		else if (!SIZE_B || !sort_a)
			swap_swap(mem, "pb");
		else
			swap_swap(mem, "pa");
		print(mem);
	}
}

int		push_swap(int size, char **tab)
{
	t_brute		*brute;
	t_memory	*mem;
	t_memory	*mem_cpy;

	mem = get_arg(size, tab);
	if (!mem)
		return (0);
	if (PRINT)
		print(mem);
	if (DEBUG)
	{
		print_option(mem);
		print_stack(mem);
		ft_putchar('\n');
	}
	if (POST_CODE)
		if (!post_code(mem))
			return (0);
	brute = mem->brute;
	if (mem->brute->brute)
	{
		if (mem->size > 6)
			ft_putendl_fd("This operation can be long", 2);
		mem_cpy = mem_copy(mem);
		brute_force(mem, brute);
		mem = mem_cpy;
		FIND = 0;
		brute_force(mem, brute);
		ft_putendl(brute->code);
		ft_strdel(&(brute->code));
		ft_memdel((void**)&brute);
	}
	if (PRINT)
		print(mem);
	if (DEBUG)
	{
		ft_putchar('\n');
		print_stack(mem);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (!error())
			return (-1);
	}
	else
		if (push_swap((argc - 1),argv) == 0)
			return (0);
	return (1);
}
