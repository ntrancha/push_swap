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

	if (STACK && INFO)
	{
		status = status_create(mem);
		print_status(status, mem);
	}
	if (SORT_A)
	{
		if (SIZE_B > 0)
			SWAP_PA;
	}
	else
	{
		if (!SIZE_B)
		{
			if (have_nbr(2431, 3241, 3231, SORT_ASTE) > 0)
				SWAP_RRR;
			else if (have_nbr(3421, 4231, 4321, SORT_ASTE) > 0)
				SWAP_RRR;
			else if (SORT_ASTE > 1000 && SORT_ASTE < 2000)
				SWAP_PB;
			else if (TOKEN_A > TOKEN_NA)
				SWAP_SA;
			else
				SWAP_PB;
		}
		else if (MIN_A == TOKEN_EA)
			SWAP_RRA;
		else if (MAX_A == TOKEN_A && MAX_B == TOKEN_EB)
			SWAP_RR;
		else if (SIZE_B > 1 && TOKEN_A > TOKEN_NA && TOKEN_B < TOKEN_NB)
			SWAP_SS;
		else if (MAX_A == TOKEN_A)
			SWAP_RA;
		else if (TOKEN_EA == MAX_A && SORT_FST_A == 312)
			SWAP_SA;
		else if (SORT_FSE_A == 231)
			SWAP_RRA;
		else if (FST_A == 132 && TOKEN_A < TOKEN_B && TOKEN_NA != MAX_A)
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
	if (STACK && INFO)
		ft_memdel((void**)&status);
}

void			depile(t_memory *mem)
{
	while (SIZE_B > 0)
		SWAP_PA;
}

void			empile(t_memory *mem)
{
	if (SIZE_A == 3 && TOKEN_B > TOKEN_NB && SORT_FSE_A == 231)
		SWAP_RRA;
	if (SIZE_B > 1 && TOKEN_B < TOKEN_NB && SORT_FSE_A == 132)
		SWAP_RRA;
	else if (SIZE_B > 1 && TOKEN_B < TOKEN_NB && TOKEN_A > TOKEN_NA)
		SWAP_SS;
	else if (SIZE_B > 1 && TOKEN_B < TOKEN_NB)
		SWAP_SB;
	else if (SIZE_A > 1 && SIZE_B > 1 && SORT_ASBS == 4312)
		SWAP_RR;
	else if (SIZE_A > 1 && SIZE_B > 1 && SORT_ASBS == 4321)
		SWAP_SA;
	else if (SIZE_A > 2 && SORT_FST_A == 231)
		SWAP_PB;
	else if (SIZE_A > 2 && SORT_FST_A == 312)
		SWAP_RA;
	else if (SIZE_A > 2 && SORT_FST_A == 132)
		SWAP_PB;
	else if (SIZE_A > 2 && SORT_FST_A == 123)
		SWAP_PB;
	else if (SIZE_A > 2 && SORT_FST_A == 213)
		SWAP_SA;
	else if (SIZE_A > 2 && SORT_FST_A == 321)
		SWAP_RA;
	if (SIZE_A == 4 && SORT_ASTE == 1234 && TOKEN_B > TOKEN_NB)
		depile(mem);
	if (SIZE_A == 3 && SORT_FSE_A == 123 && TOKEN_B > TOKEN_NB)
		depile(mem);
	else if (SIZE_A == 2 && SORT_ASBS == 3421)
		depile(mem);
	else
		empile(mem);
}

void    		sort(t_memory *mem)
{
	/*
	while (SIZE_B != 0 || IS_SORT_A != 1)
		algo_sort(mem);
*/	
	empile(mem);
}
