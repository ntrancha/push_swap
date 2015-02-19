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
# define CONTENTS	ft_stackcontent
# define STACK_A	mem->stack_a
# define STACK_B	mem->stack_b
# define PLATE_A	mem->stack_a->end
# define PLATE_B	mem->stack_b->end

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

typedef struct      s_memory
{
	char			*type;
	char			*chaine;
	void			(*func)(struct s_memory*);
	int				debug;
	int				iter;
	int				size;
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_memory;

typedef struct      s_brute
{
	int				min;
	char			*code;	
}					t_brute;

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
int     error(void);
int     verif(int size, char **tab);
int     start(int size, char **tab, t_stack *stack);
void    print(t_memory *mem);
void    debug(t_stack *stack);
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

#endif
