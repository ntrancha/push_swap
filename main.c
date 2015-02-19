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
	int		max;
	int		min;
	int		sort_a;
	int		sort_b;
	int		count;
	int		mid;

	count = 0;
	while (count++ < 100 && (STACK_B->size || count < 5))
	{
		max = find_max(STACK_A);
		min = find_min(STACK_A, max);
		sort_a = 0;
		sort_b = 0;
		mid = 0;
		if (is_sort(STACK_A))
			sort_a = 1;
		if (STACK_B->size && is_unsort(STACK_B))
			sort_b = 1;
		if (is_middle(mem))
			mid = 1;
		if (STACK_B->size > 1 && PLATE_B->content < PLATE_B->previous->content)
		{
			swap_swap(mem, "sb");
			swap_swap(mem, "pa");
		}
		else if (STACK_B->size > 1 && PLATE_B->content < STACK_B->start->content)
			swap_swap(mem, "rrb");
		else if (PLATE_A->content == min && !sort_a)
			swap_swap(mem, "pb");
		else if (PLATE_A->previous && PLATE_A->content > PLATE_A->previous->content)
			swap_swap(mem, "sa");
		else if (PLATE_A->content > STACK_A->start->content)
			swap_swap(mem, "rra");
		else if (!STACK_B->size || !sort_a)
			swap_swap(mem, "pb");
		else
			swap_swap(mem, "pa");
		print(mem);
	}
}

int				brute_force(t_memory *mem, t_brute *brute)
{
	t_memory	*sa;
	t_memory	*ra;
	int			ts;
	int			tr;

	if (mem->iter < brute->min && !is_sort(STACK_A))
	{
		sa = mem_copy(mem);
		ra = mem_copy(mem);
		swap_swap(sa, "sa");
		swap_swap(ra, "ra");
		tr = brute_force(ra, brute);
		ts = brute_force(sa, brute);
	}
	if (is_sort(STACK_A))
	{
		if (mem->iter < brute->min)
		{
			if (brute->code)
				ft_strdel(&(brute->code));
			brute->code = ft_strdup(mem->chaine);
			brute->min = mem->iter;
		}
		ft_putnbr(mem->iter);
		ft_putstr("\t");
		ft_putendl(mem->chaine);
		return (mem->iter);
	}
	return (mem->size * 3);
}

int		push_swap(int size, char **tab)
{
	t_stack		*stack;
	t_stack		*stack_b;
	t_brute		*brute;
	t_memory	*mem;
	void	(*func)(t_memory*);

	stack = ft_stackcreate();
	func = swap_pb;
	stack_b = ft_stackcreate();
	mem = ft_memalloc(sizeof(t_memory));
	mem->stack_a = stack;
	mem->stack_b = stack_b;
	mem->debug = 0;
	mem->iter = 0;
	mem->chaine = ft_strnew(0);
	mem->type = NULL;
	if (verif(size, tab) == 0 || test_double(1, size, tab) == 0)
		return (error());
	if (start(size, tab, stack) == 0)
		return (0);
	mem->size = STACK_A->size;
	//print_stack(mem);
	//print(mem);
	//swap_swap(mem, "sa");
	//trie(mem);
	brute = malloc(sizeof(t_brute));
	brute->min = mem->size * 3;
	brute->code = NULL;
	brute_force(mem, brute);
	ft_putendl(brute->code);
	//print_stack(mem);
	//ft_putendl(mem->chaine);
	//ft_putstr("Nombre d'operation: ");
	//ft_putnbr_endl(mem->iter);
	ft_stackdel(STACK_A);
	ft_stackdel(STACK_B);
	ft_strdel(&(mem->type));
	ft_strdel(&(mem->chaine));
	ft_memdel((void**)&mem);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (error());
	else
		if (push_swap((argc - 1),argv) == 0)
			return (0);
	return (1);
}
