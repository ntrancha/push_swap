/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:07:39 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 15:07:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void        swap_rra(t_memory *mem)
{
    if (STACK_A->size > 1)
    {
        ft_stackadd(STACK_A, STACK_A->start->content);
        ft_stackdelplate(STACK_A, STACK_A->start);
    }
}

void        swap_rrb(t_memory *mem)
{
    if (STACK_B->size > 1)
    {
        ft_stackadd(STACK_B, STACK_B->start->content);
        ft_stackdelplate(STACK_B, STACK_B->start);
    }
}

void        swap_rrr(t_memory *mem)
{
    swap_rra(mem);
    swap_rra(mem);
}
