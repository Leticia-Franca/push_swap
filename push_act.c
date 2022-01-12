/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:08:55 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/12 15:10:56 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push_tob(t_node **node_a, t_node **head_b, t_stacka *stack_a)
{
	t_node	*node;
	t_node	*tmp;

	if (*head_b == NULL)
	{
		node = new_node((*node_a)->data);
		node->next = node;
		node->prev = node;
		*head_b = node;
	}
	else
	{
		node = new_node((*node_a)->data);
		node->next = *head_b;
		tmp = (*head_b)->prev;
		node->prev = tmp;
		tmp->next = node;
		(*head_b)->prev = node;
		*head_b = node;
	}
	delete_node(node_a, stack_a);
	ft_putendl_fd("pb", 1);
}

static void	pass_to_stacka(t_stacka *stack_a, t_node *tmp)
{
	if (stack_a->head != NULL)
	{
		stack_a->head->prev->next = tmp;
		tmp->prev = stack_a->head->prev;
		tmp->next = stack_a->head;
		stack_a->head->prev = tmp;
		stack_a->head = tmp;
	}
	else
	{
		stack_a->head = tmp;
		stack_a->head->next = stack_a->head;
		stack_a->head->prev = stack_a->head;
	}
}

void	push_toa(t_stacka *stack_a, t_node **head_b)
{
	t_node	*tmp;

	if ((*head_b)->next != (*head_b))
	{
		(*head_b)->next->prev = (*head_b)->prev;
		(*head_b)->prev->next = (*head_b)->next;
		tmp = (*head_b);
		(*head_b) = (*head_b)->next;
	}
	else
	{
		tmp = (*head_b);
		(*head_b) = NULL;
	}
	pass_to_stacka(stack_a, tmp);
	ft_putendl_fd("pa", 1);
}
