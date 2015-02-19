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
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_memory;

t_stack     *ft_stackcreate(void);
t_stack     *ft_stackadd(t_stack *stack, int content);
t_stack     *ft_stackaddfirst(t_stack *stack, int content);
void        ft_stackdelplate(t_stack *stack, t_plate *plate);
void        ft_stackdel(t_stack *stack);
int         ft_stackcontent(t_stack *stack, t_plate *plate);
void        ft_stackswap(t_stack *stack, t_plate *plate, t_plate *plate2);

#endif
