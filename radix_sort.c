/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:04:13 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/11 23:27:07 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	radix_moves(t_stacka *stack_a, int i, t_node **head_b)
{
	int	num_top_a;

	num_top_a = stack_a->head->data;
	if (((num_top_a >> i) & 1) == 1)
		rotate_a(stack_a);
	else
		push_tob(&(stack_a->head), head_b, stack_a);
}

void	radix_sort(t_stacka *stack_a)
{
	int		max_bits;
	int		i;
	int		j;
	t_node	*head_b;

	max_bits = 0;
	head_b = NULL;
	while ((stack_a->len_inputs >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_a->len_inputs)
		{
			radix_moves(stack_a, i, &head_b);
			j++;
		}
		while (head_b != NULL)
			push_toa(stack_a, &head_b);
		i++;
	}
}
