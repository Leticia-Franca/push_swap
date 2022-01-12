/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:31:23 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/12 15:11:37 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_sorted(t_stacka *stack_a)
{
	int		count;
	t_node	*tmp;

	count = 1;
	tmp = stack_a->head;
	while (count < stack_a->len_inputs)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
		count++;
	}
	return (1);
}

void	send_to_sort(t_stacka *stack_a)
{
	int	its_sorted;

	its_sorted = 0;
	its_sorted = is_sorted(stack_a);
	if (its_sorted == 0)
	{
		if (stack_a->len_inputs <= 5)
			small_sorts(stack_a);
		else
			radix_sort(stack_a);
	}
	free_argvs(stack_a);
	ft_free_list(stack_a);
}
