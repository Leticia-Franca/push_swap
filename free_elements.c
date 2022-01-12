/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:03:03 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/10 15:58:36 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void	free_argvs(t_stacka *stack_a)
{
	int	counter_arg;

	counter_arg = 0;
	while (counter_arg < stack_a->len_inputs)
	{
		free(stack_a->inputs[counter_arg]);
		counter_arg++;
	}
	free(stack_a->inputs);
}

void	ft_free_list(t_stacka *stack_a)
{
	t_node	*temp;

	stack_a->head->prev->next = NULL;
	stack_a->head->prev = NULL;
	temp = stack_a->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		free(temp->prev);
		temp->prev = NULL;
	}
	free(temp);
	temp = NULL;
}

void	delete_node(t_node **node_a, t_stacka *stack_a)
{
	t_node	*tmp;

	(*node_a)->next->prev = (*node_a)->prev;
	(*node_a)->prev->next = (*node_a)->next;
	if ((*node_a) == stack_a->head)
	{
		tmp = stack_a->head;
		stack_a->head = stack_a->head->next;
		free(tmp);
	}
	else
	{
		printf("dessa vez a node_a nao era a head_a a ser excluida\n");
		free((*node_a)->prev);
		free((*node_a)->next);
		free((*node_a));
	}
}
