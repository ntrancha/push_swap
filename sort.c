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
		if (!ITER && TOKEN_A != MAX_O)
			SWAP_PB;
		else if (TOKEN_A == MIN_O || TOKEN_A < TOKEN_NA && TOKEN_A < TOKEN_EA)
			SWAP_PB;
		else if (SIZE_B > 1 && TOKEN_B > TOKEN_A && TOKEN_B > TOKEN_NA)
		{
			SWAP_PA;
			SWAP_RR;
		}
		else if (TOKEN_A > TOKEN_NA)
		{
			if (SIZE_B == 3 && TOKEN_B < TOKEN_EB && TOKEN_EB < TOKEN_NB)
				SWAP_RR;
		}
		else if (SIZE_B == 3 && TOKEN_B < TOKEN_EB && TOKEN_EB < TOKEN_NB)
			SWAP_RB;
		else if (TOKEN_A > TOKEN_NA && TOKEN_A < TOKEN_EA)
		{
			if (SIZE_B > 1 && TOKEN_B < TOKEN_NB)
				SWAP_SS;
		}
		else if (TOKEN_A > TOKEN_NA && TOKEN_A < TOKEN_EA)
			SWAP_SA;
		else if (SIZE_B > 1 && TOKEN_B < TOKEN_NB)
			SWAP_SB;
		else if (TOKEN_A > TOKEN_NA && TOKEN_A > TOKEN_EA && TOKEN_NA < TOKEN_EA)
			SWAP_RA;
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
