/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:48:38 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/24 15:48:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

t_status		*status_create(t_memory *mem)
{
	t_status	*status;

	status = malloc(sizeof(t_status));
	MID = is_middle(mem);
	MAX_A = (SIZE_A > 0 && find_max(STACK_A)) ? 1 : 0;
	MAX_B = (SIZE_B > 0 && find_max(STACK_B)) ? 1 : 0;
	MIN_A = (SIZE_A > 0 && find_min(STACK_A, MAX_A)) ? 1 : 0;
	MIN_B = (SIZE_B > 0 && find_min(STACK_B, MAX_B)) ? 1 : 0;
	SORT_A = (SIZE_A > 1 && is_sort(STACK_A)) ? 1 : 0;
	SORT_B = (SIZE_B > 1 && is_sort(STACK_B)) ? 1 : 0;
	UNSORT_A = (SIZE_A > 1 && is_unsort(STACK_A)) ? 1 : 0;
	UNSORT_B = (SIZE_B > 1 && is_unsort(STACK_B)) ? 1 : 0;
	return (status);
}

void			algo_sort(t_memory *mem)
{
	t_status	*status;

	status = status_create(mem);
	if (SIZE_B > 1 && TOKEN_B < TOKEN_NB)
	{
		SWAP_SB;
		SWAP_PA;
	}
	else if (SIZE_B > 1 && TOKEN_B < TOKEN_EB)
		SWAP_RRB;
	else if (TOKEN_A == MIN_A && !SORT_A)
		SWAP_PB;
	else if (NEXT_A && TOKEN_A > TOKEN_NA)
		SWAP_SA;
	else if (TOKEN_A > TOKEN_EA)
		SWAP_RRA;
	else if (!SIZE_B || !SORT_A)
		SWAP_PB;
	else
		SWAP_PA;
	ft_memdel((void**)&status);
}

void    		sort(t_memory *mem)
{
	int     	count;

	count = 0;
	while (count++ < 200 && (SIZE_B || count < 5))
		algo_sort(mem);
}
