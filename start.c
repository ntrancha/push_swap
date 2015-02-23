/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:50:14 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 14:50:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

t_memory	*error(void)
{
    ft_putendl_fd("Error", 2);
    return (NULL);
}

int     verif(int size, char **tab, t_brute *brute)
{
    char    *num;
	int		ret;

    num = tab[size--];
	ret = option(num, brute);
    if (!ft_strisnum(num) && !ret && tab[size])
		if (option(tab[size],brute) != -1)
	        return (0);
	if (ret == -1)
		brute->commande = ft_strdup(tab[size + 2]);
    if (size == 0)
        return (1);
    return (verif(size, tab, brute));
}

int     start(int size, char **tab, t_stack *stack)
{
    int     *num;
    int     nbr;
    int     index;
	int		count;

    num = ft_memalloc(sizeof(int) * size);
    index = 0;
	while (!(ft_strisnum(tab[(index)])))
		index++;
	count = 0;
    while (index <= size)
        num[count++] = ft_atoi(tab[(index++)]);
	index = 0;
    while (index < count)
        ft_stackaddfirst(stack, num[index++]);
    ft_memdel((void**)&num);
    return (1);
}

t_memory		*help(void)
{
	ft_putendl("NAME\n\tpush_swap - Sort a stack of token\n");
	ft_putendl("SYNOPSIS\n\t./push_swap [OPTION]... [STACK]...\n");
	ft_putendl("DESCRIPTION\n\tSort stack");
	ft_putendl("\nOPTIONS\n\t-h, --help\tHelp\n");
	ft_putendl("\t-c, --color\tColor mode\n");
	ft_putendl("\t-p, --print\tPrint stacks\n");
	ft_putendl("\t-d, --debug\tPrint infos\n");
	ft_putendl("\t-v, --stack\tPrint stacks for every step\n");
	ft_putendl("\t-s, --sort\tType of sort\n");
	ft_putendl("\t-b, --brute\tBrute force\n");
	ft_putendl("\t-a, --all\tAll solutions (require --brute)\n");
	ft_putendl("\t-P, --put\tPut instructions\n");
	ft_putendl("\t-n, --nothing\tDon't sort stacks (require --put)");
	ft_putendl("\nACTIONS\n\t\033[33mra\t\tRotate stack A\n");
	ft_putendl("\trb\t\tRotate stack B\n\n\trr\t\tRotate stack A & B\n");
	ft_putendl("\t\033[36mrra\t\tReverse rotate stack A\n");
	ft_putendl("\trrb\t\tReverse rotate stack B\n");
	ft_putendl("\trrr\t\tReverse rotate stack A & B\n");
	ft_putendl("\033[32m\tsa\t\tSwicth the two first elements of stack A\n");
	ft_putendl("\tsb\t\tSwicth the two first elements of stack B\n");
	ft_putendl("\tss\t\tSwicth the two first elements of stack A & B\n");
	ft_putendl("\t\033[31mpa\t\tPush on stack A\n");
	ft_putendl("\tpb\t\tPush on stack B\033[37m\n");
	return (NULL);
}

t_memory	*get_arg(int size, char **tab)
{
	t_brute     *brute;
    t_memory    *mem;

    mem = memory_create();
    brute = mem->brute;
    if (verif(size, tab, brute) == 0 || test_double(1, size, tab) == 0)
        return (error());
	if (HELP)
		return (help());
	if (PRINT && DEBUG)
		PRINT = 0;
	if (ALL)
		FORCE = 1;
	if (NOTHING)
		SORT = 0;
    if (start(size, tab, STACK_A) == 0)
        return (NULL);
    mem->size = SIZE_A;
    MIN = mem->size + (mem->size - (mem->size / 3));
	return (mem);
}
