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

void        print_swap(t_memory *mem)
{
    if (mem->debug == 1)
    {
        ft_putstr(mem->type);
        ft_putstr("\t");
        if (!ft_strcmp(mem->type, "pa") && STACK_B->size)
        {
            ft_putstr("[STACK B] ===> [STACK A]\t");
            ft_putnbr(STACK_B->end->content);
        }
        else if (!ft_strcmp(mem->type, "pb") && STACK_A->size)
        {
            ft_putstr("[STACK A] ===> [STACK B]\t");
            ft_putnbr(STACK_A->end->content);
        }
        else if (!ft_strcmp(mem->type, "ss") && STACK_B->size > 1 && STACK_A->size > 1)
        {
            ft_putstr("[STACK A] <--> [STACK B]\t");
            ft_putnbr(STACK_A->end->content);
            ft_putchar(' ');
            ft_putnbr(STACK_A->end->previous->content);
            ft_putchar('\t');
            ft_putnbr(STACK_B->end->content);
            ft_putchar(' ');
            ft_putnbr(STACK_B->end->previous->content);
        }
        else if (!ft_strcmp(mem->type, "sb") && STACK_B->size > 1)
        {
            ft_putstr("[STACK B] <-->\t\t");
            ft_putnbr(STACK_B->end->content);
            ft_putchar(' ');
            ft_putnbr(STACK_B->end->previous->content);
        }
        else if (!ft_strcmp(mem->type, "sa") && STACK_A->size > 1)
        {
            ft_putstr("[STACK A] <-->\t\t");
            ft_putnbr(STACK_A->end->content);
            ft_putchar(' ');
            ft_putnbr(STACK_A->end->previous->content);
        }
        else if (!ft_strcmp(mem->type, "rra") && STACK_A->size > 1)
        {
            ft_putstr("[STACK A] <<<<\t\t");
            ft_putnbr(STACK_A->end->content);
        }
        else if (!ft_strcmp(mem->type, "rrb") && STACK_B->size > 1)
        {
            ft_putstr("[STACK B] <<<<\t\t");
            ft_putnbr(STACK_B->end->content);
        }
        else if (!ft_strcmp(mem->type, "rrr") && STACK_A->size > 1 && STACK_B->size > 1)
        {
            ft_putstr("[STACK A] <<<< [STACK B]\t");
            ft_putnbr(STACK_B->end->content);
        }
        else if (!ft_strcmp(mem->type, "ra") && STACK_A->size > 1)
        {
            ft_putstr("[STACK A] >>>>\t\t");
            ft_putnbr(STACK_A->end->content);
        }
        else if (!ft_strcmp(mem->type, "rb") && STACK_B->size > 1)
        {
            ft_putstr("[STACK B] >>>>\t\t");
            ft_putnbr(STACK_B->end->content);
        }
        else if (!ft_strcmp(mem->type, "rr") && STACK_A->size > 1 && STACK_B->size > 1)
        {
            ft_putstr("[STACK A] >>>> [STACK B]\t");
            ft_putnbr(STACK_B->end->content);
        }
        else
            ft_putstr("OPERATION IMPOSSIBLE");
        ft_putchar('\n');
    }
    mem->func(mem);
}

void    print_stack(t_memory *mem)
{
    t_plate *plate_a;
    t_plate *plate_b;

    plate_a = STACK_A->start;
    plate_b = STACK_B->start;
    ft_putstr("--------------------------\nSTACK A\t\tSTACK B\n--------------------------");
    ft_putendl("\t<-- Bas de la pile");
    while (plate_a || plate_b)
    {
        if (plate_a)
        {
            ft_putnbr(plate_a->content);
            plate_a = plate_a->next;
        }
        ft_putstr("\t\t");
        if (plate_b)
        {
            ft_putnbr(plate_b->content);
            plate_b = plate_b->next;
        }
        ft_putchar('\n');
    }
    ft_putendl("-------------------------\t<-- Haut de la pile");
}

void    debug(t_stack *stack)
{
    t_plate *plate;
    int     nbr;

    plate = stack->start;
    while (plate)
    {
        nbr = plate->content;
        ft_putnbr(nbr);
        ft_putchar(' ');
        plate = plate->next;
    }
}

void    print(t_memory *mem)
{
    ft_putstr("stack A: ");
    debug(STACK_A);
    ft_putchar('\n');
    ft_putstr("stack B: ");
    debug(STACK_B);
    ft_putstr("\n--------------------------\n");
}
