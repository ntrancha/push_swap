/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:06:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/18 14:06:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <libft.h>
# include "define.h"
# include "struct.h"

t_stack		*ft_stackcreate(void);
t_stack		*ft_stackadd(t_stack *stack, int content);
t_stack		*ft_stackaddfirst(t_stack *stack, int content);
t_stack		*stack_copy(t_stack *stack);
void		ft_stackdelplate(t_stack *stack, t_plate *plate);
void		ft_stackdel(t_stack *stack);
void		ft_stackswap(t_stack *stack, t_plate *plate, t_plate *plate2);
int			ft_stackcontent(t_stack *stack, t_plate *plate);

int			is_middle(t_memory *mem);
int			is_unsort(t_stack *stack);
int			is_sort(t_stack *stack);
int			test_double_after(int point, int size, char **tab);
int			test_double(int point, int size, char **tab);

t_memory	*error(void);
t_memory	*get_arg(int size, char **tab);
int			verif(int size, char **tab, t_brute *brute);
int			start(int size, char **tab, t_stack *stack);

int			option(char *argv, t_brute *brute);
t_memory	*help(void);

void		memory_del(t_memory *mem);
t_memory	*mem_copy(t_memory *mem);
t_memory	*memory_create(void);

void		algo_sort(t_memory *mem);
void		sort(t_memory *mem);

int			is_sort_token(int a, int sa, int ta);
int			is_sort_token_four(int a, int b, int c, int d);
int			have_nbr(int a, int b, int c, int nbr);
int			is_equ(int a, int b, int c);

t_status	*status_create(t_memory *mem);
void		print_status(t_status *status, t_memory *mem);

t_brute		*brute_create(void);
int			post_code(t_memory *mem);
int			brute_force(t_memory *mem, t_brute *brute);

void		print(t_memory *mem);
void		debug(t_stack *stack, t_memory *mem);
void		print_stack(t_memory *mem);
void		print_swap(t_memory *mem);
void		print_color(int color);
void		color(t_memory *mem);

void		display(char const *str);
void		display_endl(char const *str);

void		action_first_print(t_memory *mem);
void		action_sort(t_memory *mem);
void		action_brute(t_memory *mem);

int			find_min(t_stack *stack, int max);
int			find_max(t_stack *stack);
int			find_jump_start(t_stack *stack, int max);
int			find_jump_end(t_stack *stack, int max);
char		*find_last_code(t_memory *mem);

void		swap_sa(t_memory *mem);
void		swap_sb(t_memory *mem);
void		swap_ss(t_memory *mem);
void		swap_pa(t_memory *mem);
void		swap_pb(t_memory *mem);
void		swap_ra(t_memory *mem);
void		swap_rb(t_memory *mem);
void		swap_rr(t_memory *mem);
void		swap_rra(t_memory *mem);
void		swap_rrb(t_memory *mem);
void		swap_rrr(t_memory *mem);
void		swap_action(t_memory *mem);
t_memory	*swap_swap(t_memory *mem, char *swap);
void		rotate(t_memory *mem, t_stack *stack, int max);

int			stack_cmp(t_stack *stack_a, t_stack *stack_b);

#endif
