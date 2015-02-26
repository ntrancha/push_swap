/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
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

static void		print_status_a(t_status *status, t_memory *mem)
{
	if (COLOR)
		L_BLUE;
	ft_putendl("    [STACK A]");
	if (COLOR)
		WHITE;
	ft_putstr("SIZE\t\t: ");
	ft_putnbr_endl(SIZE_A);
	ft_putstr("MAX\t\t: ");
	ft_putnbr_endl(MAX_A);
	ft_putstr("MIN\t\t: ");
	ft_putnbr_endl(MIN_A);
	if (COLOR)
		L_GREEN;
	if (SORT_A)
		ft_putendl("IS SORT");
	else if (UNSORT_A)
		ft_putendl("IS UNSORT");
}

static void		print_status_b(t_status *status, t_memory *mem)
{
	if (COLOR)
		L_BLUE;
	ft_putendl("    [STACK B]");
	if (COLOR)
		WHITE;
	ft_putstr("SIZE\t\t: ");
	ft_putnbr_endl(SIZE_B);
	ft_putstr("MAX\t\t: ");
	ft_putnbr_endl(MAX_B);
	ft_putstr("MIN\t\t: ");
	ft_putnbr_endl(MIN_B);
	if (COLOR)
		L_GREEN;
	if (SORT_B)
		ft_putendl("IS SORT");
	else if (UNSORT_B)
		ft_putendl("IS UNSORT");
}

void			print_status(t_status *status, t_memory *mem)
{
	ft_putstr("SIZE\t\t: ");
	ft_putnbr_endl(ORIGINE->size);
	ft_putstr("MAX\t\t: ");
	ft_putnbr_endl(MAX_O);
	ft_putstr("MIN\t\t: ");
	ft_putnbr_endl(MIN_O);
	if (COLOR)
		L_GREEN;
	if (MID)
		ft_putendl("IS MIDDLE");
	print_status_a(status, mem);
	print_status_b(status, mem);
	if (COLOR)
		L_BLUE;
	ft_putendl("==========================");
	if (COLOR)
		WHITE;
}

t_status		*status_create(t_memory *mem)
{
	t_status	*status;

	status = malloc(sizeof(t_status));
	MID = is_middle(mem);
	MAX_O = (SIZE_A > 0 && find_max(ORIGINE)) ? find_max(ORIGINE) : 0;
	MAX_A = (SIZE_A > 0 && find_max(STACK_A)) ? find_max(STACK_A) : 0;
	MAX_B = (SIZE_B > 0 && find_max(STACK_B)) ? find_max(STACK_B) : 0;
	MIN_O = (SIZE_A > 0 && find_min(ORIGINE, MAX_O)) ? find_min(ORIGINE, MAX_O) : 0;
	MIN_A = (SIZE_A > 0 && find_min(STACK_A, MAX_A)) ? find_min(STACK_A, MAX_A) : 0;
	MIN_B = (SIZE_B > 0 && find_min(STACK_B, MAX_B)) ? find_min(STACK_B, MAX_B) : 0;
	SORT_A = (SIZE_A > 1 && IS_SORT_A) ? 1 : 0;
	SORT_B = (SIZE_B > 1 && IS_SORT_B) ? 1 : 0;
	UNSORT_A = (SIZE_A > 1 && IS_NSORT_A) ? 1 : 0;
	UNSORT_B = (SIZE_B > 1 && IS_NSORT_B) ? 1 : 0;
	FST_A = (SIZE_A > 2) ? SORT_FST_A : -1;
	FST_B = (SIZE_B > 2) ? SORT_FST_B : -1;
	FSE_A = (SIZE_A > 2) ? SORT_FSE_A : -1;
	FSE_B = (SIZE_B > 2) ? SORT_FSE_B : -1;
	ASB = (SIZE_B > 1 && SIZE_A > 1) ? SORT_ASB : -1;
	return (status);
}
