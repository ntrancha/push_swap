/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:50:14 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/19 14:50:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

int     error(void)
{
    ft_putendl_fd("Error", 2);
    return (0);
}

int     verif(int size, char **tab)
{
    char    *num;

    num = tab[size--];
    if (ft_strisnum(num) == 0)
        return (0);
    if (size == 0)
        return (1);
    return (verif(size, tab));
}

int     start(int size, char **tab, t_stack *stack)
{
    int     *num;
    int     nbr;
    int     index;

    num = ft_memalloc(sizeof(int) * size);
    index = 0;
    while (index < size)
        num[index] = ft_atoi(tab[(index++ + 1)]);
    while (size)
        stack = ft_stackadd(stack, num[--size]);
    ft_memdel((void**)&num);
    return (1);
}
