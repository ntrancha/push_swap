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
		if (mem->chaine)
			ft_strdel(&(mem->chaine));
		if (mem->type)
			ft_strdel(&(mem->type));
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
	char		*last;
	int			min;
	int			max;
	int			sort_a;
	int			sort_b;

	last = NULL;
	if (mem->iter < brute->min - 1 && !is_sort(STACK_A))
	{
		if (last)
			ft_strdel(&last);
		last = find_last_code(mem);
		max = find_max(STACK_A);
		min = find_min(STACK_A, max);
		sort_a = is_sort(STACK_A);
		sort_b = 0;
		if (STACK_B->size > 0 && is_unsort(STACK_B))
			sort_b = 1;
		if (ft_strcmp(last, ";pb") != 0 && SIZE_B > 0)
			brute_force(swap_swap(mem_copy(mem), "pa"), brute);
		if (!sort_a)
		{
			if (ft_strcmp(last, ",ra") != 0 && STACK_A->size > 2)	
				brute_force(swap_swap(mem_copy(mem), "rra"), brute);
			if (ft_strcmp(last, "rra") != 0 && STACK_A->size > 2)	
				brute_force(swap_swap(mem_copy(mem), "ra"), brute);
			if (ft_strcmp(last, ";sa") && ft_strcmp(last, ";sb") && SIZE_A > 1)
				brute_force(swap_swap(mem_copy(mem), "sa"), brute);
			if (ft_strcmp(last, ";pa") != 0 && STACK_A->size > 2)	
				brute_force(swap_swap(mem_copy(mem), "pb"), brute);
		}
		//if (!sort_b)
		//{
			if (ft_strcmp(last, "rrb") != 0 && STACK_B->size > 2)	
				brute_force(swap_swap(mem_copy(mem), "rb"), brute);
			if (ft_strcmp(last, ";rb") != 0 && STACK_B->size > 2)	
				brute_force(swap_swap(mem_copy(mem), "rrb"), brute);
			if (ft_strcmp(last, ";sb") && ft_strcmp(last, ";sa") && SIZE_B > 1)
				brute_force(swap_swap(mem_copy(mem), "sb"), brute);
		//}
		if (STACK_A->size > 1 && STACK_B->size > 1 && ft_strcmp(last, ";rr") != 0 )
			brute_force(swap_swap(mem_copy(mem), "rrr"), brute);
		if (STACK_A->size > 1 && STACK_B->size > 1 && ft_strcmp(last, "ss") != 0 )
			brute_force(swap_swap(mem_copy(mem), "ss"), brute);
		if (STACK_A->size > 1 && STACK_B->size > 1 && ft_strcmp(last, "rrr") != 0 )
			brute_force(swap_swap(mem_copy(mem), "rr"), brute);
	}
	if (is_sort(STACK_A) && !STACK_B->size)
	{
		ft_strdel(&last);
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
	mem->stack_a = ft_stackcreate();
	mem->stack_b = ft_stackcreate();
	mem->func = NULL;
	mem->debug = 0;
	mem->iter = 0;
	mem->chaine = ft_strnew(0);
	mem->type = NULL;
	if (verif(size, tab) == 0 || test_double(1, size, tab) == 0)
		return (error());
	if (start(size, tab, STACK_A) == 0)
		return (0);
	mem->size = STACK_A->size;
	//print_stack(mem);
	//print(mem);
	//swap_swap(mem, "sa");
	//trie(mem);
	brute = malloc(sizeof(t_brute));
	brute->min = mem->size +  (mem->size / 2);
	brute->code = NULL;
	brute_force(mem, brute);
	ft_putendl(brute->code);
	ft_strdel(&(brute->code));
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
