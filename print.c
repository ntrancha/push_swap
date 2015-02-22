/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:14:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/21 16:14:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void        print_one(char *msg, int num)
{
    ft_putstr(msg);
	WHITE;
    ft_putnbr(num);
}

void        print_two(char *msg, int num, int previous)
{
    ft_putstr(msg);
	WHITE;
    ft_putnbr(num);
    ft_putchar('\t');
    ft_putnbr(previous);
}

void        print_three(t_memory *mem)
{
    ft_putstr("[STACK A] <--> [STACK B]\t");
	WHITE;
    ft_putnbr(TOKEN_A);
    ft_putchar(' ');
    ft_putnbr(NEXT_A->content);
    ft_putstr("\t");
    ft_putnbr(TOKEN_B);
    ft_putchar(' ');
    ft_putnbr(NEXT_B->content);
}

void        print_next(t_memory *mem)
{
        if (!ft_strcmp(TYPE, "pa") && SIZE_B)
            print_one("[STACK B] ===> [STACK A]\t", TOKEN_B);
        else if (!ft_strcmp(TYPE, "pb") && SIZE_A)
            print_one("[STACK A] ===> [STACK B]\t", TOKEN_A);
        else if (!ft_strcmp(TYPE, "sb") && SIZE_B > 1)
            print_two("[STACK B] <-->\t\t\t", TOKEN_B, NEXT_B->content);
        else if (!ft_strcmp(TYPE, "sa") && SIZE_A > 1)
            print_two("[STACK A] <-->\t\t\t", TOKEN_A, NEXT_A->content);
        else if (!ft_strcmp(TYPE, "rra") && SIZE_A > 1)
            print_one("[STACK A] <<<<\t\t\t", TOKEN_A);
        else if (!ft_strcmp(TYPE, "rrb") && SIZE_B > 1)
            print_one("[STACK B] <<<<\t\t\t", TOKEN_B);
        else if (!ft_strcmp(TYPE, "rrr") && SIZE_A > 1 && SIZE_B > 1)
            print_one("[STACK A] <<<< [STACK B]\t", TOKEN_B);
        else if (!ft_strcmp(TYPE, "ra") && SIZE_A > 1)
            print_one("[STACK A] >>>>\t\t\t", TOKEN_A);
        else if (!ft_strcmp(TYPE, "rb") && SIZE_B > 1)
            print_one("[STACK B] >>>>\t\t\t", TOKEN_B);
        else if (!ft_strcmp(TYPE, "rr") && SIZE_A > 1 && SIZE_B > 1)
            print_one("[STACK A] >>>> [STACK B]\t", TOKEN_B);
        else if (!ft_strcmp(TYPE, "ss") && SIZE_B > 1 && SIZE_A > 1)
            print_three(mem);
        else
            ft_putstr("OPERATION IMPOSSIBLE");
        ft_putchar('\n');
}

void        print_swap(t_memory *mem)
{
    if (DEBUG || (PRINT && !mem->brute->brute))
    {
		if (mem->brute->color)
			color(mem);
        ft_putstr(TYPE);
        ft_putchar('\t');
		if (DEBUG)
	        print_next(mem);
		else
			ft_putchar('\n');
		WHITE;
    }
    mem->func(mem);
    if (mem->brute->stack)
		print(mem);
}
