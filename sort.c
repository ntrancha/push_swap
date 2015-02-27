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

int			sort_0(t_memory *mem)
{
	if (SIZE_B == 0)
	{
		if (SORT_ASTE == 4321)
			SWAP_RRA;
		else if (SORT_ASTE == 4213)
			SWAP_RA;
		else if (SORT_ASTE == 4132)
			SWAP_SA;
		else if (SORT_ASTE == 4312 && SORT_ASTF == 4312)
			SWAP_RA;
		else if (SORT_FSE_A == 123 || SORT_FSE_A == 132)
			SWAP_PB; 
		else if (SIZE_A > 3 && SORT_ASTF == 2143)
		{
			SWAP_PB;
			SWAP_PB;
			SWAP_SS;
		}
		else if (SIZE_A > 3 && SORT_ASTF == 4321)
			SWAP_RA;
		else	
			SWAP_PB;
		return (1);
	}
	if (SIZE_A == 3 && SORT_FSE_A == 231)
	{
		SWAP_RRA;
		return (1);
	}
	return (0);
}

int			sort_1(t_memory *mem)
{
	if (SIZE_B == 1)
	{
		if (SORT_FSE_A == 321)
			SWAP_SA;
		else if (SORT_ASTE == 4132)
			SWAP_RA;
		else if (SORT_FSE_A == 231)
			SWAP_RRA;
		else if (SORT_FSE_A == 312)
			SWAP_RRA;
		else
			SWAP_PB;
		return (1);
	}
	return (0);
}

int			sort_2(t_memory *mem)
{
	if (SIZE_B == 2)
	{
		if (TOKEN_A > TOKEN_NA && TOKEN_B < TOKEN_NB)
			SWAP_SS;
		if (SORT_ASBS == 1324)
		{
			SWAP_PB;
			SWAP_SB;
			SWAP_PB;
			SWAP_RRB;
		}
		else if (TOKEN_B < TOKEN_NB)
			SWAP_SB;
		else if (TOKEN_A > TOKEN_NA)
			SWAP_SA;
		else
			SWAP_PB;
		return (1);
	}
	return (0);
}

int			sort_3(t_memory *mem)
{
	if (SIZE_B == 3)
	{
		if (SORT_FST_B == 132)
			SWAP_RB;
		else if (TOKEN_A > TOKEN_NA && TOKEN_B < TOKEN_NB)
			SWAP_SS;
		else if (SIZE_A > 2 && SORT_FST_A == 312)
			SWAP_RA;
		else if (TOKEN_B < TOKEN_NB)
			SWAP_SB;
		else if (TOKEN_A > TOKEN_NA)
			SWAP_SA;
		else
			SWAP_PB;
		return (1);
	}
	return (0);
}

void		sort_4(t_memory *mem)
{
	if (SORT_BSTE == 1432)
		SWAP_RB;
	else if (SIZE_A > 2 &&SORT_FST_A == 312)
		SWAP_RA;
	else if (TOKEN_A > TOKEN_NA && TOKEN_B < TOKEN_NB)
		SWAP_SS;
	else if (TOKEN_B < TOKEN_NB)
		SWAP_SB;
	else if (TOKEN_A > TOKEN_NA)
		SWAP_SA;
	else if (SORT_BSA == 321)
		SWAP_PA;
	else if (SORT_FSE_A == 231)
		SWAP_RRA;
	else if (SIZE_A > 2)
		SWAP_PB;
}

void    		sort(t_memory *mem)
{
	int			test;

	test = 0;
	if (SIZE_B > 1)
		if (SIZE_A == 4 && SORT_ASTF == 1234 && TOKEN_B > TOKEN_NB)
			test = 1;
		else if (SIZE_A == 3 && SORT_FSE_A == 123 && SORT_ASBS == 3421)
			test = 1;
		else if (SIZE_A == 2 && (SORT_ASBS == 3421 || SORT_ASBS == 2431))
			test = 1;
	if (test == 0)
	{
		if (!sort_0(mem) && !sort_1(mem) && !sort_2(mem) && !sort_3(mem))
			sort_4(mem);
		sort(mem);
	}
	else
	{
		ft_putendl("OK");
		while (SIZE_B > 0 || TOKEN_A > TOKEN_NA)
			if (TOKEN_A > TOKEN_NA)
				SWAP_SA;
			else
				SWAP_PA;
	}
}
