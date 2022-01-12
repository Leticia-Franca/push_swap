/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:53:01 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/11 23:25:52 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

typedef struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stacka {
	int		len_inputs;
	char	**inputs;
	t_node	*head;
}				t_stacka;

typedef struct s_simplify {
	int		minindex;
	int		initial_loop_position;
	int		is_minindex_changed;
	int		prev_value;
	int		i;
	int		j;
	char	**arr_simplify;
}				t_simplify;

void			print_list(t_stacka *stack_a);
t_node			*new_node(int value);
void			ft_error(void);
long long int	atoi_long(const char *nptr);
void			ft_no_duplicates(t_stacka *stack_a);
int				ft_isnumber(char *c);
void			ft_free_list(t_stacka *stack_a);
void			free_argvs(t_stacka *stack_a);
void			check_isnumber(t_stacka *stack_a);
void			simplify_numbers(t_stacka *stack_a);
void			rotate_a(t_stacka *stack_a);
void			push_tob(t_node **node_a, t_node **head_b, t_stacka *stack_a);
void			push_toa(t_stacka *stack_a, t_node **head_b);
void			switch_a(t_stacka *stack_a);
void			rotate_reverse_a(t_stacka *stack_a);
int				is_sorted(t_stacka *stack_a);
void			small_sorts(t_stacka *stack_a);
void			radix_sort(t_stacka *stack_a);
void			send_to_sort(t_stacka *stack_a);
void			delete_node(t_node **node_a, t_stacka *stack_a);

#endif