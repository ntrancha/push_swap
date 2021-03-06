/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:43:32 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/23 10:43:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_plate
{
	int				content;
	struct s_plate	*next;
	struct s_plate	*previous;
}					t_plate;

typedef struct		s_stack
{
	t_plate			*start;
	t_plate			*end;
	int				size;
}					t_stack;

typedef struct		s_brute
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
	int				sort;
	int				info;
	int				nothing;
	char			*commande;
	char			*code;
	t_list			*solution;
	t_stack			*origine;
}					t_brute;

typedef struct		s_memory
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

typedef struct		s_status
{
	int				mid;
	int				min;
	int				min_a;
	int				min_b;
	int				max;
	int				max_a;
	int				max_b;
	int				sort_a;
	int				sort_b;
	int				unsort_a;
	int				unsort_b;
	int				sort_fst_a;
	int				sort_fst_b;
	int				sort_fse_a;
	int				sort_fse_b;
	int				sort_asb;
}					t_status;

#endif
