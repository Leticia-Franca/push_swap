/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_swap_act.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:11:27 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/12 15:15:12 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rotate_a(t_stacka *stack_a)
{
	stack_a->head = stack_a->head->next;
	ft_putendl_fd("ra", 1);
}

void	switch_a(t_stacka *stack_a)
{
	int	aux_value;

	if (stack_a->head->next != stack_a->head)
	{
		aux_value = stack_a->head->data;
		stack_a->head->data = stack_a->head->next->data;
		stack_a->head->next->data = aux_value;
	}
	ft_putendl_fd("sa", 1);
}

void	rotate_reverse_a(t_stacka *stack_a)
{
	stack_a->head = stack_a->head->prev;
	ft_putendl_fd("rra", 1);
}
