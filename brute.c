/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 14:02:59 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/22 14:02:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void			brute_a(t_memory *mem, int sort_a, char *last)
{
	//if (LAST(";pb") != 0 && SIZE_B > 0)
		BRUTE("pa");
	//if (!sort_a)
	//{
	//	if (LAST(",ra") != 0 && SIZE_A > 2)
		 	BRUTE("rra");
	//	if (LAST("rra") != 0 && SIZE_A > 2)
			BRUTE("ra");
	//	if (LAST(";sa") && LAST(";sb") && SIZE_A > 1)
			BRUTE("sa");
	//	if (LAST(";pa") != 0 && SIZE_A > 2)
			BRUTE("pb");
	//}
}

void			brute_b(t_memory *mem, int sort_b, char *last)
{
	if (mem && STACK_B)
	{
	//	if (LAST("rrb") != 0 && SIZE_B > 2)
			BRUTE("rb");
	//	if (LAST(";rb") != 0 && SIZE_B > 2)
			BRUTE("rrb");
	//	if (LAST(";sb") && LAST(";sa") && SIZE_B > 1)
			BRUTE("sb");
	}
}

void			brute_d(t_memory *mem, char *last)
{
	//if (SIZE_A > 1 && SIZE_B > 1 && LAST(";rr") != 0 )
		BRUTE("rrr");
	//if (SIZE_A > 1 && SIZE_B > 1 && LAST("ss") != 0 )
		BRUTE("ss");
	//if (SIZE_A > 1 && SIZE_B > 1 && LAST("rrr") != 0 )
		BRUTE("rr");
}

int				brute_end(t_memory *mem, char *last)
{
	if (ITER != 0 && stack_cmp(ORIGINE, STACK_A))
		return (0);
	if (mem && is_sort(STACK_A) && SIZE_B == 0)
	{
        ft_strdel(&last);
        if (FIND && (ITER < MIN || !CODE))
        {
            if (CODE)
                ft_strdel(&(CODE));
            CODE = ft_strdup(CHAINE);
            MIN = ITER;
        }
        if (!FIND && (ITER <= MIN || !CODE))
        {
            if (CODE)
                ft_strdel(&(CODE));
            CODE = ft_strdup(CHAINE);
            MIN = ITER;
        }
		if (DEBUG && !FIND)
		{
			if (COLOR)
				L_GREEN;
	        ft_putnbr(ITER);
	        ft_putstr("\t");
	        ft_putendl(CHAINE);
			if (COLOR)
				WHITE;
	        print(mem);
		}
		if ((ALL && !FIND))
			SOLUTION = ft_listadd(SOLUTION, ft_strdup(CHAINE));
        memory_del(mem);
		mem = NULL;
        return (1);
	}
	return (0);
}

int             brute_force(t_memory *mem, t_brute *brute)
{
    char        *last;
    int         min;
    int         max;
    int         sort_a;
    int         sort_b;

    last = NULL;
    if (ITER < MIN && !is_sort(STACK_A))
    {
        if (last)
            ft_strdel(&last);
        last = find_last_code(mem);
        max = find_max(STACK_A);
        min = find_min(STACK_A, max);
        sort_a = is_sort(STACK_A);
        sort_b = 0;
        if (SIZE_B > 0 && is_unsort(STACK_B))
            sort_b = 1;
		brute_a(mem, sort_a, last);
		brute_b(mem, sort_b, last);
		brute_d(mem, last);
    }
	if (brute_end(mem, last))
		return (1);
    memory_del(mem);
    return (0);
}
