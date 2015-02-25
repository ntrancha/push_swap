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

void			algo_sort(t_memory *mem)
{
	t_status	*status;

	status = status_create(mem);
	if (STACK && INFO)
		print_status(status, mem);
	if (SORT_A)
	{
		if (SIZE_B > 0)
			SWAP_PA;
	}
	else
	{
		if (MIN_A == TOKEN_EA)
			SWAP_RRA;
		if (FST_A == 231 && FST_B == 231)
			SWAP_RRR;
		if (FST_A == 231)
			SWAP_RRA;
		if (FST_B == 231)
			SWAP_RRB;
		if (FST_A == 312 && FST_B == 312)
			SWAP_RR;
		if (FST_A == 312)
			SWAP_RA;
		if (FST_B == 312)
			SWAP_RB;
	}
	/*
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
	*/
	ft_memdel((void**)&status);
}

void    		sort(t_memory *mem)
{
	while (SIZE_B != 0 || IS_SORT_A != 1)
		algo_sort(mem);
}
