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
		else if (MAX_A == TOKEN_A)
			SWAP_RA;
		else if (ITER == 0)
			SWAP_PB;
		else if (FST_A == 132 && TOKEN_A < TOKEN_B)
		{
			SWAP_PB;
			SWAP_SS;
		}
		else if (FST_A == 312 && FST_B == 312)
			SWAP_RR;
		else if (FST_A == 312 || TOKEN_A == MAX_A)
			SWAP_RA;
		else if (FST_B == 312)
			SWAP_RB;
		else if (FST_A == 213 && FST_B == 213)
			SWAP_SS;
		else if (FST_A == 213)
			SWAP_SA;
		else if (FST_A == 213)
			SWAP_SB;
		else
			SWAP_PB;
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
