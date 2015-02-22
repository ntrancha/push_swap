/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:52:12 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 14:52:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void	print_option(t_memory *mem)
{
	LINE;
	ft_putstr("\nDebug\t\t: \033[32mOn\033[37m\nPrint\t\t: ");
	if (PRINT)
		ft_putstr("\033[32mOn\033[37m");
	else
		ft_putstr("\033[31mOff\033[37m");
	ft_putstr("\nBrute force\t: ");
	if (mem->brute->brute)
		ft_putstr("\033[32mOn\033[37m");
	else
		ft_putstr("\033[31mOff\033[37m");
	ft_putstr("\nPost code\t: ");
	if (mem->brute->pre_code)
		ft_putstr(mem->brute->commande);
	else
		ft_putstr("\033[31mOff\033[37m");
	ft_putstr("\nAll\t\t: ");
	if (mem->brute->all)
		ft_putstr("\033[32mOn\033[37m");
	else
		ft_putstr("\033[31mOff\033[37m");
	ft_putstr("\nColor\t\t: ");
	if (mem->brute->color)
		ft_putstr("\033[32mOn\033[37m");
	else
		ft_putstr("\033[31mOff\033[37m");
	ft_putstr("\nStack\t\t: ");
	if (mem->brute->stack)
		ft_putstr("\033[32mOn\033[37m");
	else
		ft_putstr("\033[31mOff\033[37m");
	ft_putstr("\nNothing\t\t: ");
	if (mem->brute->nothing)
		ft_putstr("\033[32mOn\033[37m");
	else
		ft_putstr("\033[31mOff\033[37m");
	ft_putchar('\n');
	LINE;
	ft_putstr("\n\n");
}

void    print_stack_next(t_memory *mem)
{
    t_plate *plate_a;
    t_plate *plate_b;

    plate_a = STACK_A->end;
    plate_b = STACK_B->end;
    while (plate_a || plate_b)
    {
        if (plate_a)
        {
            ft_putnbr(plate_a->content);
            plate_a = plate_a->previous;
        }
        ft_putstr("\t\t");
        if (plate_b)
        {
            ft_putnbr(plate_b->content);
            plate_b = plate_b->previous;
        }
        ft_putchar('\n');
    }
}
void    print_stack(t_memory *mem)
{
	if (mem->brute->color)
		BLUE;
    ft_putstr("--------------------------\nSTACK A\t\tSTACK B\n");
    ft_putstr("--------------------------");
	if (mem->brute->color)
		WHITE;
	ft_putendl("\t<-- Haut de la pile");
	print_stack_next(mem);
	if (mem->brute->color)
		BLUE;
    ft_putstr("--------------------------");
	if (mem->brute->color)
		WHITE;
	ft_putendl("\t<-- Bas de la pile");
}

void    debug(t_stack *stack, t_memory *mem)
{
    t_plate *plate;
    int     nbr;
	int		count;

    plate = END;
    while (plate)
    {
        nbr = TOKEN;
		if (mem->brute->color)
		{
			if (ft_strcmp(TYPE, "pa") == 0)
				if (nbr == STACK_A->end->content)
					RED;
			if (ft_strcmp(TYPE, "sa") == 0 || ft_strcmp(TYPE, "ss") == 0)
				if (nbr == TOKEN_A || nbr == NEXT_A->content)
					GREEN;
			if (ft_strcmp(TYPE, "pb") == 0)
				if (nbr == STACK_B->end->content)
					RED;
			if (ft_strcmp(TYPE, "sb") == 0 || ft_strcmp(TYPE, "ss") == 0)
				if (nbr == TOKEN_B || nbr == NEXT_B->content)
					GREEN;
			if (ft_strcmp(TYPE, "ra") == 0 || ft_strcmp(TYPE, "rr") == 0)
				YELLOW;
			if (ft_strcmp(TYPE, "rra") == 0 || ft_strcmp(TYPE, "rrr") == 0)
				BLUE;
			if (ft_strcmp(TYPE, "rb") == 0 || ft_strcmp(TYPE, "rr") == 0)
				YELLOW;
			if (ft_strcmp(TYPE, "rrb") == 0 || ft_strcmp(TYPE, "rrr") == 0)
				BLUE;
		}
        ft_putnbr(nbr);
		if (mem->brute->color)
			WHITE;
        ft_putchar(' ');
        plate = PREVIOUS;
    }
}

void    print(t_memory *mem)
{
    ft_putstr("stack A: ");
	if (mem->brute->color)
    debug(STACK_A, mem);
	if (mem->brute->color)
		WHITE;
    ft_putchar('\n');
    ft_putstr("stack B: ");
    debug(STACK_B, mem);
	if (mem->brute->color)
		WHITE;
    ft_putstr("\n");
	LINE;
    ft_putstr("\n");
}
