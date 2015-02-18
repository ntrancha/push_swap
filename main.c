/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 07:31:18 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/17 07:31:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack.h"

void		print_swap(t_memory *mem)
{
	if (mem->debug == 1)
	{
		ft_putstr(mem->type);
		ft_putstr("\t");
		if (!ft_strcmp(mem->type, "pa") && STACK_B->size)
		{
			ft_putstr("[STACK B] ===> [STACK A]\t");
			ft_putnbr(STACK_B->end->content);
		}
		else if (!ft_strcmp(mem->type, "pb") && STACK_A->size)
		{
			ft_putstr("[STACK A] ===> [STACK B]\t");
			ft_putnbr(STACK_A->end->content);
		}
		else if (!ft_strcmp(mem->type, "ss") && STACK_B->size > 1 && STACK_A->size > 1)
		{
			ft_putstr("[STACK A] <--> [STACK B]\t");
			ft_putnbr(STACK_A->end->content);
			ft_putchar(' ');
			ft_putnbr(STACK_A->end->previous->content);
			ft_putchar('\t');
			ft_putnbr(STACK_B->end->content);
			ft_putchar(' ');
			ft_putnbr(STACK_B->end->previous->content);
		} 
		else if (!ft_strcmp(mem->type, "sb") && STACK_B->size > 1)
		{
			ft_putstr("[STACK B] <-->\t\t");
			ft_putnbr(STACK_B->end->content);
			ft_putchar(' ');
			ft_putnbr(STACK_B->end->previous->content);
		} 
		else if (!ft_strcmp(mem->type, "sa") && STACK_A->size > 1)
		{
			ft_putstr("[STACK A] <-->\t\t");
			ft_putnbr(STACK_A->end->content);
			ft_putchar(' ');
			ft_putnbr(STACK_A->end->previous->content);
		} 
		else if (!ft_strcmp(mem->type, "rra") && STACK_A->size > 1)
		{
			ft_putstr("[STACK A] <<<<\t\t");
			ft_putnbr(STACK_A->end->content);
		}
		else if (!ft_strcmp(mem->type, "rrb") && STACK_B->size > 1)
		{
			ft_putstr("[STACK B] <<<<\t\t");
			ft_putnbr(STACK_B->end->content);
		}
		else if (!ft_strcmp(mem->type, "rrr") && STACK_A->size > 1 && STACK_B->size > 1)
		{
			ft_putstr("[STACK A] <<<< [STACK B]\t");
			ft_putnbr(STACK_B->end->content);
		}
		else if (!ft_strcmp(mem->type, "ra") && STACK_A->size > 1)
		{
			ft_putstr("[STACK A] >>>>\t\t");
			ft_putnbr(STACK_A->end->content);
		}
		else if (!ft_strcmp(mem->type, "rb") && STACK_B->size > 1)
		{
			ft_putstr("[STACK B] >>>>\t\t");
			ft_putnbr(STACK_B->end->content);
		}
		else if (!ft_strcmp(mem->type, "rr") && STACK_A->size > 1 && STACK_B->size > 1)
		{
			ft_putstr("[STACK A] >>>> [STACK B]\t");
			ft_putnbr(STACK_B->end->content);
		}
		else
			ft_putstr("OPERATION IMPOSSIBLE");
		ft_putchar('\n');
	}
	else
	{
		ft_putstr(mem->type);
	}
	mem->func(mem);
}

void		swap_sa(t_memory *mem)
{
	if (STACK_A->size > 1)
		ft_stackswap(STACK_A, PLATE_A, PLATE_A->previous);
}

void		swap_sb(t_memory *mem)
{
	if (STACK_B->size > 1)
		ft_stackswap(STACK_B, PLATE_B, PLATE_B->previous);
}

void		swap_ss(t_memory *mem)
{
	swap_sa(mem);
	swap_sb(mem);
}

void		swap_pb(t_memory *mem)
{
	if (STACK_A->size > 0)
	{
		ft_stackadd(STACK_B, PLATE_A->content);
		ft_stackdelplate(STACK_A, PLATE_A);
	}
}

void		swap_pa(t_memory *mem)
{
	if (STACK_B->size > 0)
	{
		ft_stackadd(STACK_A, PLATE_B->content);
		ft_stackdelplate(STACK_B, PLATE_B);
	}
}

void		swap_ra(t_memory *mem)
{
	if (STACK_A->size > 1)
	{
		ft_stackaddfirst(STACK_A, PLATE_A->content);
		ft_stackdelplate(STACK_A, PLATE_A);
	}
}

void		swap_rb(t_memory *mem)
{
	if (STACK_B->size > 1)
	{
		ft_stackaddfirst(STACK_B, PLATE_B->content);
		ft_stackdelplate(STACK_B, PLATE_B);
	}
}

void		swap_rra(t_memory *mem)
{
	if (STACK_A->size > 1)
	{
		ft_stackadd(STACK_A, STACK_A->start->content);
		ft_stackdelplate(STACK_A, STACK_A->start);
	}
}

void		swap_rrb(t_memory *mem)
{
	if (STACK_B->size > 1)
	{
		ft_stackadd(STACK_B, STACK_B->start->content);
		ft_stackdelplate(STACK_B, STACK_B->start);
	}
}

void		swap_rr(t_memory *mem)
{
	swap_ra(mem);
	swap_ra(mem);
}

void		swap_rrr(t_memory *mem)
{
	swap_rra(mem);
	swap_rra(mem);
}

void		swap_action(t_memory *mem)
{
	if (!ft_strcmp(mem->type, "sa"))
		mem->func = swap_sa;
	if (!ft_strcmp(mem->type, "sb"))
		mem->func = swap_sb;
	if (!ft_strcmp(mem->type, "pa"))
		mem->func = swap_pa;
	if (!ft_strcmp(mem->type, "pb"))
		mem->func = swap_pb;
	if (!ft_strcmp(mem->type, "ra"))
		mem->func = swap_ra;
	if (!ft_strcmp(mem->type, "rb"))
		mem->func = swap_rb;
	if (!ft_strcmp(mem->type, "rra"))
		mem->func = swap_rra;
	if (!ft_strcmp(mem->type, "rrb"))
		mem->func = swap_rrb;
	if (!ft_strcmp(mem->type, "ss"))
		mem->func = swap_ss;
	if (!ft_strcmp(mem->type, "rr"))
		mem->func = swap_rr;
	if (!ft_strcmp(mem->type, "rrr"))
		mem->func = swap_rrr;
	print_swap(mem);
}

void		swap_swap(t_memory *mem, char *swap)
{
	mem->type = NULL;
	if (!ft_strcmp(swap, "sa"))
		mem->type = swap;
	if (!ft_strcmp(swap, "sb"))
		mem->type = swap;
	if (!ft_strcmp(swap, "pa"))
		mem->type = swap;
	if (!ft_strcmp(swap, "pb"))
		mem->type = swap;
	if (!ft_strcmp(swap, "ra"))
		mem->type = swap;
	if (!ft_strcmp(swap, "rb"))
		mem->type = swap;
	if (!ft_strcmp(swap, "rra"))
		mem->type = swap;
	if (!ft_strcmp(swap, "rrb"))
		mem->type = swap;
	if (!ft_strcmp(swap, "ss"))
		mem->type = swap;
	if (!ft_strcmp(swap, "rr"))
		mem->type = swap;
	if (!ft_strcmp(swap, "rrr"))
		mem->type = swap;
	if (mem->type)
		swap_action(mem);
}

int			test_double_after(int point, int size, char **tab)
{
	char	*test;

	test = tab[point++];
	while (point <= size)
		if (ft_strcmp(test, tab[point++]) == 0)
			return (0);
	return (1);
}

int		test_double(int point, int size, char **tab)
{
	while (point < size)
		if (test_double_after(point++, size, tab) == 0)
			return (0);
	return (1);
}

int		error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

int		verif(int size, char **tab)
{
	char	*num;

	num = tab[size--];
	if (ft_strisnum(num) == 0)
		return (0);
	if (size == 0)
		return (1);
	return (verif(size, tab));
}

int		start(int size, char **tab, t_stack *stack)
{
	t_plate	*plate;
	int		*num;
	int		*ptr;
	int		nbr;
	int		index;

	num = ft_memalloc(sizeof(int) * size);
	index = 0;
	while (index < size)
		num[index] = ft_atoi(tab[(index++ + 1)]);
	while (size)
		stack = ft_stackadd(stack, num[--size]);
	plate = stack->start;
	return (1);
}

void	print_stack(t_memory *mem)
{
	t_plate	*plate_a;
	t_plate	*plate_b;

	plate_a = STACK_A->start;
	plate_b = STACK_B->start;
	ft_putstr("--------------------------\nSTACK A\t\tSTACK B\n--------------------------");
	ft_putendl("\t<-- Bas de la pile");
	while (plate_a || plate_b)
	{
		if (plate_a)
		{
			ft_putnbr(plate_a->content);
			plate_a = plate_a->next;
		}
		//else
			//ft_putchar('\t');
		ft_putstr("\t\t");
		if (plate_b)
		{
			ft_putnbr(plate_b->content);
			plate_b = plate_b->next;
		}
		ft_putchar('\n');
	}
	ft_putendl("-------------------------\t<-- Haut de la pile");
}

void	debug(t_stack *stack)
{
	t_plate	*plate;
	int		nbr;

	plate = stack->start;
	while (plate)
	{
		nbr = plate->content;
		ft_putnbr(nbr);
		ft_putchar(' ');
		plate = plate->next;
	}
}

void	print(t_memory *mem)
{
	ft_putstr("--------------------------\nstack A: ");
	debug(STACK_A);
	ft_putchar('\n');
	ft_putstr("stack B: ");
	debug(STACK_B);
	ft_putstr("\n--------------------------\n");
}

int		push_swap(int size, char **tab)
{
	t_stack	*stack;
	t_stack	*stack_b;
	t_memory	*mem;
	void	(*func)(t_memory*);

	stack = ft_stackcreate();
	func = swap_pb;
	stack_b = ft_stackcreate();
	mem = ft_memalloc(sizeof(t_memory));
	mem->stack_a = stack;
	mem->stack_b = stack_b;
	mem->debug = 1;
	if (verif(size, tab) == 0 || test_double(1, size, tab) == 0)
		return (error());
	if (start(size, tab, stack) == 0)
		return (0);
	print(mem);
	swap_swap(mem, "pa");
	swap_swap(mem, "pb");
	swap_swap(mem, "pb");
	swap_swap(mem, "pb");
	swap_swap(mem, "pa");
	swap_swap(mem, "ss");
	swap_swap(mem, "rr");
	swap_swap(mem, "rrr");
	swap_swap(mem, "ss");
	swap_swap(mem, "pa");
	swap_swap(mem, "pa");
	print_stack(mem);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (error());
	else
		if (push_swap((argc - 1),argv) == 0)
			return (0);
	return (1);
}
