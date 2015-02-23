/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:41:05 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/23 20:41:05 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

static int	option_end(char c, t_brute *brute)
{
    if (c == 'd')
        brute->debug = 1;
    if (c == 'p')
        brute->print = 1;
    if (c == 'b')
        brute->brute = 1;
    if (c == 's')
        brute->step = 1;
    if (c == 'a')
        brute->all = 1;
    if (c == 'n')
        brute->nothing = 1;
    if (c == 'c')
        brute->color = 1;
    if (c == 'h')
        brute->help = 1;
    if (c == 'v')
        brute->stack = 1;
    if (c == 'p')
        brute->print = 1;
    if (c == 'P')
    {
        brute->pre_code = 1;
        return (-1);
    }
    return (1);
}

static int	option_next(char *argv, t_brute *brute)
{
    int     ret;
    int     index;
    char    c;

    ret = 1;
    index = 1;
    if (argv[0] != '-')
        return (0);
    while (argv[index])
    {
        c = argv[index];
        ret = 0;
        if (c == 'd' || c == 'p' || c == 'b' || c == 's' || c == 'a' || c == 'n')
            ret = option_end(c, brute);
        else if (c == 'c' || c == 'h' || c == 'v' || c == 'P')
            ret = option_end(c, brute);
        else
            return (0);
        index++;
    }
    return (ret);
}

int     option(char *argv, t_brute *brute)
{
    if (ft_strcmp(argv, "-d") == 0 || ft_strcmp(argv, "--debug") == 0)
        brute->debug = 1;
    else if (ft_strcmp(argv, "-p") == 0 || ft_strcmp(argv, "--print") == 0)
        brute->print = 1;
    else if (ft_strcmp(argv, "-b") == 0 || ft_strcmp(argv, "--brute") == 0)
        brute->brute = 1;
    else if (ft_strcmp(argv, "-s") == 0 || ft_strcmp(argv, "--step") == 0)
        brute->step = 1;
    else if (ft_strcmp(argv, "-a") == 0 || ft_strcmp(argv, "--all") == 0)
        brute->all = 1;
    else if (ft_strcmp(argv, "-n") == 0 || ft_strcmp(argv, "--nothing") == 0)
        brute->nothing = 1;
    else if (ft_strcmp(argv, "-c") == 0 || ft_strcmp(argv, "--color") == 0)
        brute->color = 1;
    else if (ft_strcmp(argv, "-h") == 0 || ft_strcmp(argv, "--help") == 0)
        brute->help = 1;
    else if (ft_strcmp(argv, "-v") == 0 || ft_strcmp(argv, "--stack") == 0)
        brute->stack = 1;
    else if (ft_strcmp(argv, "-s1") == 0 || ft_strcmp(argv, "--sort") == 0)
        brute->sort = 1;
    else if (ft_strcmp(argv, "-s2") == 0 || ft_strcmp(argv, "--sort2") == 0)
        brute->sort = 2;
    else if (ft_strcmp(argv, "-P") == 0 || ft_strcmp(argv, "--put") == 0)
    {
        brute->pre_code = 1;
        return (-1);
    }
    else
        return (option_next(argv, brute));
    return (1);
}
