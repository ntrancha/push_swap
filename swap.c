/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:09:57 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 15:09:57 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void        swap_action(t_memory *mem)
{
    char    *tmp;
    char    *tmp2;

    if (!ft_strcmp(mem->type, "sa"))
        mem->func = swap_sa;
    if (!ft_strcmp(mem->type, "sb"))
        mem->func = swap_sb;
    if (!ft_strcmp(mem->type, "pa"))
        mem->func = swap_pa;
    if (!ft_strcmp(mem->type, "pb"))
        mem->func = swap_pb;
    if (!ft_strcmp(mem->type, "ra"))
        mem->func = swap_ra;
    if (!ft_strcmp(mem->type, "rb"))
        mem->func = swap_rb;
    if (!ft_strcmp(mem->type, "rra"))
        mem->func = swap_rra;
    if (!ft_strcmp(mem->type, "rrb"))
        mem->func = swap_rrb;
    if (!ft_strcmp(mem->type, "ss"))
        mem->func = swap_ss;
    if (!ft_strcmp(mem->type, "rr"))
        mem->func = swap_rr;
    if (!ft_strcmp(mem->type, "rrr"))
        mem->func = swap_rrr;
    mem->iter++;
    tmp = ft_strjoin(mem->chaine, ";");
    tmp2 = ft_strjoin(tmp, mem->type);
    ft_strdel(&(mem->chaine));
    ft_strdel(&(tmp));
    mem->chaine = tmp2;
    print_swap(mem);
}

t_memory    *swap_swap(t_memory *mem, char *swap)
{
    char    *type;

    type = mem->type;
    if (type != NULL)
        ft_memdel((void**)&type);
    if (!ft_strcmp(swap, "sa"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "sb"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "pa"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "pb"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "ra"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "rb"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "rra"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "rrb"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "ss"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "rr"))
        mem->type = ft_strdup(swap);
    if (!ft_strcmp(swap, "rrr"))
        mem->type = ft_strdup(swap);
    if (mem->type)
        swap_action(mem);
    else if (DEBUG)
        ft_putendl("ACTION INCONNU");
	return (mem);
}

void    rotate(t_memory *mem, t_stack *stack, int max)
{
    int start;
    int end;

    start = find_jump_start(stack, max);
    end = find_jump_end(stack, max);
    if (start > end)
        while (PLATE_A->content != max)
            swap_swap(mem, "ra");
    else
        while (PLATE_A->content != max)
            swap_swap(mem, "rra");
}
