/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 13:50:40 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/22 13:50:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void    memory_del(t_memory *mem)
{
    if (mem)
    {
        if (CHAINE)
            ft_strdel(&(CHAINE));
        if (TYPE)
            ft_strdel(&(TYPE));
        ft_stackdel(STACK_A);
        ft_stackdel(STACK_B);
        //ft_memdel((void**)&mem);
        free(mem);
    }
}

t_brute     *brute_create(void)
{
    t_brute     *brute;

    if (!(brute = malloc(sizeof(t_brute))))
        return (NULL);
    brute->code = NULL;
    brute->commande = NULL;
    brute->origine = NULL;
    brute->pre_code = 0;
    brute->debug = 0;
    brute->print = 0;
    brute->find = 1;
    brute->min = 0;
    brute->all = 0;
    brute->step = 0;
    brute->color = 0;
    brute->help = 0;
    brute->stack = 0;
    brute->sort = 1;
    brute->nothing = 0;
    brute->brute = 0;
    return (brute);
}

t_memory    *memory_create(void)
{
    t_memory    *mem;

    if (!(mem = ft_memalloc(sizeof(t_memory))))
        return (NULL);
    STACK_A = ft_stackcreate();
    STACK_B = ft_stackcreate();
    FUNC = NULL;
    ITER = 0;
    CHAINE = ft_strnew(0);
    TYPE = NULL;
	ORIGINE = stack_copy(STACK_A);
    mem->brute = brute_create();
    return (mem);
}

