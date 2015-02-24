/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:39:14 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/23 10:39:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define LINE		ft_putstr("--------------------------")
# define BRUTE(X)	brute_force(swap_swap(mem_copy(mem), X), mem->brute)
# define LAST(X)	ft_strcmp(last, X)
# define CONTENTS	ft_stackcontent

# define WHITE		print_color(0)
# define RED		print_color(1)
# define GREEN		print_color(2)
# define YELLOW		print_color(3)
# define BLUE		print_color(4)
# define L_RED		print_color(5)
# define L_GREEN	print_color(6)
# define L_YELLOW	print_color(7)
# define L_BLUE		print_color(8)
# define L_WHITE	print_color(9)

# define FIND		mem->brute->find
# define MIN		mem->brute->min
# define CODE		mem->brute->code
# define COMMANDE	mem->brute->commande
# define POST_CODE	mem->brute->pre_code
# define DEBUG		mem->brute->debug
# define PRINT		mem->brute->print
# define FORCE		mem->brute->brute
# define COLOR		mem->brute->color
# define STACK		mem->brute->stack;
# define NOTHING	mem->brute->nothing
# define HELP		mem->brute->help
# define ALL		mem->brute->all
# define SORT		mem->brute->sort
# define ORIGINE	mem->brute->origine
# define SOLUTION	mem->brute->solution

# define STACK_A	mem->stack_a
# define STACK_B	mem->stack_b
# define TYPE		mem->type
# define CHAINE		mem->chaine
# define ITER		mem->iter
# define SIZE		mem->size
# define FUNC		mem->func

# define SIZE_A		STACK_A->size
# define SIZE_B		STACK_B->size
# define END_A		STACK_A->start
# define END_B		STACK_B->start
# define PLATE_A	STACK_A->end
# define PLATE_B	STACK_B->end

# define NEXT_A		PLATE_A->previous
# define NEXT_B		PLATE_B->previous
# define TOKEN_A	PLATE_A->content
# define TOKEN_B	PLATE_B->content

# define TOKEN		plate->content
# define NEXT		plate->next
# define PREVIOUS	plate->previous

# define START		stack->start
# define END		stack->end

#endif
