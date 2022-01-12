/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:11:48 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/12 19:14:21 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	smaller_sort_three(t_stacka *stack_a, t_node **head_b)
{
	int		head_greater_next;
	int		head_greater_prev;
	int		prev_greater_next;

	prev_greater_next = stack_a->head->prev->data > stack_a->head->next->data;
	head_greater_prev = stack_a->head->data > stack_a->head->prev->data;
	head_greater_next = stack_a->head->data > stack_a->head->next->data;
	if (!head_greater_next && head_greater_prev)
		rotate_reverse_a(stack_a);
	else if (!prev_greater_next && !head_greater_prev)
	{
		push_tob(&(stack_a->head), head_b, stack_a);
		switch_a (stack_a);
		push_toa(stack_a, head_b);
	}
	else if (!prev_greater_next && head_greater_next)
	{
		switch_a(stack_a);
		rotate_reverse_a(stack_a);
	}
	else if (prev_greater_next && head_greater_prev)
		rotate_a(stack_a);
	else if (head_greater_next && !head_greater_prev)
		switch_a(stack_a);
}

static void	dif_fndless(t_stacka *stack_a, t_node **tmp, int j)
{
	int	counter_traverse_input;

	counter_traverse_input = 1;
	while ((counter_traverse_input <= stack_a->len_inputs - j))
	{
		if ((*tmp)->data != j && (*tmp)->prev->data != j)
		{
			(*tmp) = (*tmp)->next;
			stack_a->head = (*tmp);
			ft_putendl_fd("ra", 1);
		}
		else if ((*tmp)->data != j && (*tmp)->prev->data == j)
		{
			(*tmp) = (*tmp)->prev;
			stack_a->head = (*tmp);
			ft_putendl_fd("rra", 1);
		}
		counter_traverse_input++;
	}
}

static void	putdif_stackb(t_stacka *stack_a, t_node **head_b)
{
	int		j;
	t_node	*tmp;

	j = 0;
	while (j < stack_a->len_inputs - 3)
	{
		tmp = stack_a->head;
		dif_fndless(stack_a, &tmp, j);
		push_tob(&tmp, head_b, stack_a);
		j++;
	}
}

void	small_sorts(t_stacka *stack_a)
{
	int		j;
	t_node	*head_b;

	head_b = NULL;
	if (stack_a->len_inputs == 2)
		rotate_a(stack_a);
	else if (stack_a->len_inputs == 3)
		smaller_sort_three(stack_a, &head_b);
	else if (stack_a->len_inputs > 3)
	{
		j = 0;
		putdif_stackb(stack_a, &head_b);
		smaller_sort_three(stack_a, &head_b);
		while (j < stack_a->len_inputs - 3)
		{
			push_toa(stack_a, &head_b);
			j++;
		}
	}
}
