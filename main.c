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

void	memory_del(t_memory *mem)
{
	if (mem)
	{
		if (CHAINE)
			ft_strdel(&(CHAINE));
		if (TYPE)
			ft_strdel(&(TYPE));
		ft_stackdel(STACK_A);
		ft_stackdel(STACK_B);
		//ft_memdel((void**)&mem);
		free(mem);
	}
}

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

int				brute_force(t_memory *mem, t_brute *brute)
{
	char		*last;
	int			min;
	int			max;
	int			sort_a;
	int			sort_b;

	last = NULL;
	if (ITER < MIN && !is_sort(STACK_A))
	{
		if (last)
			ft_strdel(&last);
		last = find_last_code(mem);
		max = find_max(STACK_A);
		min = find_min(STACK_A, max);
		sort_a = is_sort(STACK_A);
		sort_b = 0;
		if (SIZE_B > 0 && is_unsort(STACK_B))
			sort_b = 1;
		if (LAST(";pb") != 0 && SIZE_B > 0)
			BRUTE("pa");
		if (!sort_a)
		{
			if (LAST(",ra") != 0 && SIZE_A > 2)	
				BRUTE("rra");
			if (LAST("rra") != 0 && SIZE_A > 2)	
				BRUTE("ra");
			if (LAST(";sa") && LAST(";sb") && SIZE_A > 1)
				BRUTE("sa");
			if (LAST(";pa") != 0 && SIZE_A > 2)	
				BRUTE("pb");
		}
		//if (!sort_b)
		//{
			if (LAST("rrb") != 0 && SIZE_B > 2)	
				BRUTE("rb");
			if (LAST(";rb") != 0 && SIZE_B > 2)	
				BRUTE("rrb");
			if (LAST(";sb") && LAST(";sa") && SIZE_B > 1)
				BRUTE("sb");
		//}
		if (SIZE_A > 1 && SIZE_B > 1 && LAST(";rr") != 0 )
			BRUTE("rrr");
		if (SIZE_A > 1 && SIZE_B > 1 && LAST("ss") != 0 )
			BRUTE("ss");
		if (SIZE_A > 1 && SIZE_B > 1 && LAST("rrr") != 0 )
			BRUTE("rr");
	}
	if (is_sort(STACK_A) && !SIZE_B)
	{
		ft_strdel(&last);
		if (ITER < MIN)
		{
			if (CODE)
				ft_strdel(&(CODE));
			CODE = ft_strdup(CHAINE);
			MIN = ITER;
		}
		ft_putnbr(ITER);
		ft_putstr("\t");
		ft_putendl(CHAINE);
		print(mem);
		memory_del(mem);
		return (1);
	}
	memory_del(mem);
	return (0);
}

int		push_swap(int size, char **tab)
{
	t_brute		*brute;
	t_memory	*mem;

	mem = ft_memalloc(sizeof(t_memory));
	STACK_A = ft_stackcreate();
	STACK_B = ft_stackcreate();
	FUNC = NULL;
	DEBUG = 1;
	ITER = 0;
	CHAINE = ft_strnew(0);
	TYPE = NULL;
	if (verif(size, tab) == 0 || test_double(1, size, tab) == 0)
		return (error());
	if (start(size, tab, STACK_A) == 0)
		return (0);
	mem->size = SIZE_A;
	//print_stack(mem);
	//print(mem);
	//swap_swap(mem, "sa");
	//trie(mem);
	brute = malloc(sizeof(t_brute));
	MIN = mem->size +  (mem->size / 2);
	CODE = NULL;
	brute_force(mem, brute);
	ft_putendl(CODE);
	ft_strdel(&(CODE));
	ft_memdel((void**)&brute);
	//memory_del(mem);
	//print_stack(mem);
	//ft_putendl(mem->chaine);
	//ft_putstr("Nombre d'operation: ");
	//ft_putnbr_endl(mem->iter);
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
