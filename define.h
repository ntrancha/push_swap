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
# define IS_SORT_A	is_sort(STACK_A)
# define IS_SORT_B	is_sort(STACK_B)
# define IS_NSORT_A	is_unsort(STACK_A)
# define IS_NSORT_B	is_unsort(STACK_B)
# define SORT_FST_A	is_sort_token(TOKEN_A, TOKEN_NA, TOKEN_TA)
# define SORT_FST_B	is_sort_token(TOKEN_B, TOKEN_NB, TOKEN_TB)
# define SORT_FSE_A	is_sort_token(TOKEN_A, TOKEN_NA, TOKEN_EA)
# define SORT_FSE_B	is_sort_token(TOKEN_B, TOKEN_NB, TOKEN_EB)
# define SORT_ASB	is_sort_token(TOKEN_A, TOKEN_NA, TOKEN_B)
# define SORT_ASBS	is_sort_token_four(TOKEN_A, TOKEN_NA, TOKEN_B, TOKEN_NB)
# define SORT_ASTE	is_sort_token_four(TOKEN_A, TOKEN_NA, TOKEN_TA, TOKEN_EA)
# define SORT_BSTE	is_sort_token_four(TOKEN_B, TOKEN_NB, TOKEN_TB, TOKEN_EB)
# define HAVE_MAX	have_nbr(TOKEN_A, TOKEN_NA, TOKEN_TA, TOKEN_EA, MAX_A)

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
# define INFO		mem->brute->info
# define FORCE		mem->brute->brute
# define COLOR		mem->brute->color
# define STACK		mem->brute->stack
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
# define TOKEN_NA	NEXT_A->content
# define TOKEN_TA	NEXT_A->previous->content
# define TOKEN_EA	END_A->content
# define TOKEN_B	PLATE_B->content
# define TOKEN_NB	NEXT_B->content
# define TOKEN_TB	NEXT_B->previous->content
# define TOKEN_EB	END_B->content

# define TOKEN		plate->content
# define NEXT		plate->next
# define PREVIOUS	plate->previous

# define START		stack->start
# define END		stack->end

# define MID		status->mid
# define MIN_O		status->min
# define MIN_A		status->min_a
# define MIN_B		status->min_b
# define MAX_O		status->max
# define MAX_A		status->max_a
# define MAX_B		status->max_b
# define SORT_A		status->sort_a
# define SORT_B		status->sort_b
# define UNSORT_A	status->unsort_a
# define UNSORT_B	status->unsort_b
# define FST_A		status->sort_fst_a
# define FST_B		status->sort_fst_b
# define FSE_A		status->sort_fse_a
# define FSE_B		status->sort_fse_b
# define ASB		status->sort_asb

# define SWAP_PA	swap_swap(mem, "pa")
# define SWAP_PB	swap_swap(mem, "pb")
# define SWAP_SA	swap_swap(mem, "sa")
# define SWAP_SB	swap_swap(mem, "sb")
# define SWAP_SS	swap_swap(mem, "ss")
# define SWAP_RA	swap_swap(mem, "ra")
# define SWAP_RB	swap_swap(mem, "rb")
# define SWAP_RR	swap_swap(mem, "rr")
# define SWAP_RRA	swap_swap(mem, "rra")
# define SWAP_RRB	swap_swap(mem, "rrb")
# define SWAP_RRR	swap_swap(mem, "rrr")

#endif
