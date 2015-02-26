/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
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

int     	is_sort_token(int a, int sa, int ta)
{
    if (a < sa && sa < ta)
        return (123);
    if (ta < sa && ta > a)
        return (132);
    if (a > sa && a < ta)
        return (213);
    if (a < sa && ta < a)
        return (231);
    if (a > ta && ta > sa)
        return (312);
    if (a > sa && sa > ta)
        return (321);
    return (-1);
}

static int	is_sort_token_four_next(int a, int b, int c, int d)
{
	if (c > b && b > a && a > d)
        return (2341);
	if (d > b && b > a && a > c)
        return (2314);
	if (b > c && c > a && a > d)
        return (2431);
	if (b > d && d > a && a > c)
        return (2413);
	if (c > d && d > a && a > b)
        return (2143);
	if (d > c && c > a && a > b)
        return (2134);
	if (d > c && c > b && b > a)
        return (1234);
	if (c > d && d > b && b > a)
        return (1243);
	if (c > b && b > d && d > a)
        return (1342);
	if (d > b && b > c && c > a)
        return (1324);
	if (b > c && c > d && d > a)
        return (1432);
	if (b > d && d > c && c > a)
        return (1423);
	return (-1);
}

int			is_sort_token_four(int a, int b, int c, int d)
{
	if (a > b && b > c && c > d)
		return (4321);
	if (a > b && b > d && d > c)
		return (4312);
	if (a > c && c > b && b > d)
		return (4231);
	if (a > d && d > b && b > c)
        return (4213);
	if (a > c && c > d && d > b)
        return (4132);
	if (a > d && d > c && c > a)
        return (4123);
	if (b > a && a > c && c > d)
        return (3421);
	if (b > a && a > d && d > c)
        return (3412);
	if (c > a && a > b && b > d)
        return (3241);
	if (d > a && a > b && b > c)
        return (3214);
	if (c > a && a > d && d > b)
        return (3142);
	if (d > a && a > c && c > b)
        return (3124);
	return (is_sort_token_four_next(a, b, c, d));
}
