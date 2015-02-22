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
# define LINE		ft_putstr("--------------------------")
# define BRUTE(X)	brute_force(swap_swap(mem_copy(mem), X), mem->brute)
# define LAST(X)	ft_strcmp(last, X)
# define CONTENTS	ft_stackcontent
# define WHITE		print_color(0)
# define RED		print_color(1)
# define GREEN		print_color(2)
# define YELLOW		print_color(3)
# define BLUE		print_color(4)
# define FIND		mem->brute->find
# define MIN		mem->brute->min
# define CODE		mem->brute->code
# define COMMANDE	mem->brute->commande
# define POST_CODE	mem->brute->pre_code
# define DEBUG		mem->brute->debug
# define PRINT		mem->brute->print
# define ALL		mem->brute->all
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
# define TOKEN		plate->content
# define TOKEN_A	PLATE_A->content
# define TOKEN_B	PLATE_B->content
# define NEXT		plate->next
# define PREVIOUS	plate->previous
# define START		stack->start
# define END		stack->end

typedef struct      s_plate
{
    int				content;
    struct s_plate   *next;
    struct s_plate   *previous;
}                   t_plate;

typedef struct      s_stack
{
    t_plate          *start;
    t_plate          *end;
    int             size;
}                   t_stack;

typedef struct      s_brute
{
	int				min;
	int				debug;
	int				print;
	int				brute;
	int				pre_code;
	int				all;
	int				find;
	int				step;
	int				help;
	int				color;
	int				stack;
	int				nothing;
	char			*commande;
	char			*code;	
	
}					t_brute;

typedef struct      s_memory
{
	char			*type;
	char			*chaine;
	void			(*func)(struct s_memory*);
	int				iter;
	int				size;
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_brute			*brute;
}					t_memory;

t_stack     *ft_stackcreate(void);
t_stack     *ft_stackadd(t_stack *stack, int content);
t_stack     *ft_stackaddfirst(t_stack *stack, int content);
t_stack         *stack_copy(t_stack *stack);
t_memory        *mem_copy(t_memory *mem);
void        ft_stackdelplate(t_stack *stack, t_plate *plate);
void        ft_stackdel(t_stack *stack);
int         ft_stackcontent(t_stack *stack, t_plate *plate);
void        ft_stackswap(t_stack *stack, t_plate *plate, t_plate *plate2);
int     is_middle(t_memory *mem);
int     is_unsort(t_stack *stack);
int     is_sort(t_stack *stack);
int         test_double_after(int point, int size, char **tab);
int     test_double(int point, int size, char **tab);
t_memory    *error(void);
int     verif(int size, char **tab, t_brute *brute);
int     start(int size, char **tab, t_stack *stack);
t_memory    *get_arg(int size, char **tab);
void    memory_del(t_memory *mem);
t_brute     *brute_create(void);
t_memory    *memory_create(void);
int         post_code(t_memory *mem);
int             brute_force(t_memory *mem, t_brute *brute);
void    print(t_memory *mem);
void    debug(t_stack *stack, t_memory *mem);
void    print_stack(t_memory *mem);
void        print_swap(t_memory *mem);
int     find_min(t_stack *stack, int max);
int     find_max(t_stack *stack);
int     find_jump_start(t_stack *stack, int max);
int     find_jump_end(t_stack *stack, int max);
char    *find_last_code(t_memory *mem);
void        swap_sa(t_memory *mem);
void        swap_sb(t_memory *mem);
void        swap_ss(t_memory *mem);
void        swap_pa(t_memory *mem);
void        swap_pb(t_memory *mem);
void        swap_ra(t_memory *mem);
void        swap_rb(t_memory *mem);
void        swap_rr(t_memory *mem);
void        swap_rra(t_memory *mem);
void        swap_rrb(t_memory *mem);
void        swap_rrr(t_memory *mem);
void        swap_action(t_memory *mem);
t_memory    *swap_swap(t_memory *mem, char *swap);
void    rotate(t_memory *mem, t_stack *stack, int max);
void    color(t_memory *mem);
void    print_color(int color);

#endif
