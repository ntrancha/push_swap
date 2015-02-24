/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
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

void		action_first_print(t_memory *mem)
{
	print_option(mem);
	print_stack(mem);
	ft_putchar('\n');
}

void		action_sort(t_memory *mem)
{
	trie(mem);
	if (DEBUG)
	{
		ft_putchar('\n');
		print_stack(mem);
	}
	display_endl(mem->chaine);
}

void		action_brute_end(t_memory *mem, t_memory *mem_cpy)
{
	t_brute     *brute;
	int         test;

	brute = mem->brute;
	test = 0;
	if (brute->debug)
		test = 1;
	mem_cpy->brute->brute = 0;
	mem_cpy->brute->print = 0;
	mem_cpy->brute->debug = 0;
	mem_cpy->brute->commande = brute->solution->end->content;
	post_code(mem_cpy);
	ft_strdel(&mem_cpy->type);
	if (test == 1)
		print_stack(mem_cpy);
	else
		print(mem_cpy);

}

void		action_brute_next(t_memory *mem, t_memory *mem_cpy)
{
	void (*put) (char const *);
	t_brute     *brute;

	brute = mem->brute;
	put = display_endl;
	if (brute->debug || brute->print)
	{
		ft_putnbr(brute->solution->size);
		ft_putstr(" solution(s) (size: ");
		ft_putnbr(brute->min);
		ft_putendl(")");
	}
	ft_listputstr(brute->solution, put);
	if (brute->debug || brute->print)
		action_brute_end(mem, mem_cpy);
}

void		action_brute(t_memory *mem)
{
	t_brute     *brute;
	t_memory    *mem_cpy;
	void (*del) (void **);

	brute = mem->brute;
	del = ft_memdel;
	if (mem->size > 6)
		ft_putendl_fd("This operation can be long", 2);
	mem_cpy = mem_copy(mem);
	brute_force(mem, brute);
	mem = mem_cpy;
	mem_cpy = mem_copy(mem);
	FIND = 0;
	brute_force(mem, brute);
	if (!brute->all)
		ft_putendl(brute->code);
	else
		action_brute_next(mem, mem_cpy);
	ft_listdel(brute->solution, del);
	ft_strdel(&(brute->code));
	ft_memdel((void**)&brute);
}
