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
	int 	put;
    int     index;
    char    c;

    ret = 1;
    index = 1;
	put = 1;
    if (argv[0] != '-')
        return (0);
    ret = 0;
    while (argv[index])
    {
        c = argv[index];
        if (c == 'd' || c == 'p' || c == 'b' || c == 's' || c == 'n')
            ret = option_end(c, brute);
        else if (c == 'c' || c == 'h' || c == 'v' || c == 'a')
            ret = option_end(c, brute);
        else if (c == 'P')
			put = option_end(c, brute);
        else
            return (0);
        index++;
    }
    return (ret * put);
}

int     option(char *argv, t_brute *brute)
{
    if (ft_strcmp(argv, "-d") == 0 || ft_strcmp(argv, "--debug") == 0)
        brute->debug = 1;
    else if (ft_strcmp(argv, "-p") == 0 || ft_strcmp(argv, "--print") == 0)
		return (option_end('p', brute));
    else if (ft_strcmp(argv, "-b") == 0 || ft_strcmp(argv, "--brute") == 0)
		return (option_end('b', brute));
    else if (ft_strcmp(argv, "-s") == 0 || ft_strcmp(argv, "--step") == 0)
		return (option_end('s', brute));
    else if (ft_strcmp(argv, "-a") == 0 || ft_strcmp(argv, "--all") == 0)
		return (option_end('a', brute));
    else if (ft_strcmp(argv, "-n") == 0 || ft_strcmp(argv, "--nothing") == 0)
		return (option_end('n', brute));
    else if (ft_strcmp(argv, "-c") == 0 || ft_strcmp(argv, "--color") == 0)
		return (option_end('c', brute));
    else if (ft_strcmp(argv, "-h") == 0 || ft_strcmp(argv, "--help") == 0)
		return (option_end('h', brute));
    else if (ft_strcmp(argv, "-v") == 0 || ft_strcmp(argv, "--stack") == 0)
		return (option_end('n', brute));
    else if (ft_strcmp(argv, "-P") == 0 || ft_strcmp(argv, "--put") == 0)
		return (option_end('P', brute));
    else
        return (option_next(argv, brute));
    return (1);
}

t_memory        *help(void)
{
    ft_putendl("NAME\n\tpush_swap - Sort a stack of token\n");
    ft_putendl("SYNOPSIS\n\t./push_swap [OPTION]... [STACK]...\n");
    ft_putendl("DESCRIPTION\n\tSort stack");
    ft_putendl("\nOPTIONS\n\t-h, --help\tHelp\n");
    ft_putendl("\t-c, --color\tColor mode\n");
    ft_putendl("\t-p, --print\tDisplay stacks when is sort\n");
    ft_putendl("\t-d, --debug\tDisplay infos\n");
    ft_putendl("\t-v, --stack\tDisplay stacks for every step\n");
    ft_putendl("\t-s, --sort\tType of sort\n");
    ft_putendl("\t-b, --brute\tBrute force\n");
    ft_putendl("\t-a, --all\tDisplay all solutions (require --brute)\n");
    ft_putendl("\t-P, --put\tPut instructions separate with ;\n");
    ft_putendl("\t-n, --nothing\tDon't sort stacks (require --put)");
    ft_putendl("\nINSTRUCTIONS\n\t\033[33mra\t\tRotate stack A\n");
    ft_putendl("\trb\t\tRotate stack B\n\n\trr\t\tRotate stack A & B\n");
    ft_putendl("\t\033[36mrra\t\tReverse rotate stack A\n");
    ft_putendl("\trrb\t\tReverse rotate stack B\n");
    ft_putendl("\trrr\t\tReverse rotate stack A & B\n");
    ft_putendl("\033[32m\tsa\t\tSwicth the two first elements of stack A\n");
    ft_putendl("\tsb\t\tSwicth the two first elements of stack B\n");
    ft_putendl("\tss\t\tSwicth the two first elements of stack A & B\n");
    ft_putendl("\t\033[31mpa\t\tPush on stack A\n");
    ft_putendl("\tpb\t\tPush on stack B\033[37m\n");
	ft_putstr("EXEMPLES\n\t./push_swap 5 2 3 1 4\n\n\t./push_swap --dvc 5");
    ft_putendl(" 1 3 4 2\n\n\t./push_swap -c -dvbP \"pb;pb;rr;ss\" 3 5 2 1 4");
    return (NULL);
}
