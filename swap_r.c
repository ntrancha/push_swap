/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:06:32 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 15:06:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void        swap_ra(t_memory *mem)
{
    if (STACK_A->size > 1)
    {
        ft_stackaddfirst(STACK_A, PLATE_A->content);
        ft_stackdelplate(STACK_A, PLATE_A);
    }
}

void        swap_rb(t_memory *mem)
{
    if (STACK_B->size > 1)
    {
        ft_stackaddfirst(STACK_B, PLATE_B->content);
        ft_stackdelplate(STACK_B, PLATE_B);
    }
}

void        swap_rr(t_memory *mem)
{
    swap_ra(mem);
    swap_rb(mem);
}
