/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:04:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 15:04:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void        swap_sa(t_memory *mem)
{
    if (STACK_A->size > 1)
        ft_stackswap(STACK_A, PLATE_A, PLATE_A->previous);
}

void        swap_sb(t_memory *mem)
{
    if (STACK_B->size > 1)
        ft_stackswap(STACK_B, PLATE_B, PLATE_B->previous);
}

void        swap_ss(t_memory *mem)
{
    swap_sa(mem);
    swap_sb(mem);
}
