/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:05:46 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 15:05:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void        swap_pb(t_memory *mem)
{
    if (STACK_A->size > 0)
    {
        ft_stackadd(STACK_B, PLATE_A->content);
        ft_stackdelplate(STACK_A, PLATE_A);
    }
}

void        swap_pa(t_memory *mem)
{
    if (STACK_B->size > 0)
    {
        ft_stackadd(STACK_A, PLATE_B->content);
        ft_stackdelplate(STACK_B, PLATE_B);
    }
}
