/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:11:05 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/12 15:12:39 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node) * 1);
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	ft_create_list(t_stacka *stack_a)
{
	int		counter;
	t_node	*node;

	counter = -1;
	stack_a->head = NULL;
	while (++counter < stack_a->len_inputs)
	{
		if (stack_a->head == NULL)
		{
			node = new_node(ft_atoi(stack_a->inputs[counter]));
			node->next = node;
			node->prev = node;
			stack_a->head = node;
		}
		else
		{
			node->next = new_node(ft_atoi(stack_a->inputs[counter]));
			node->next->prev = node;
			node = node->next;
			node->next = stack_a->head;
			stack_a->head->prev = node;
		}
	}
}

static void	validate_and_createlist(t_stacka *stack_a)
{
	check_isnumber(stack_a);
	ft_no_duplicates(stack_a);
	simplify_numbers(stack_a);
	ft_create_list(stack_a);
}

static void	store_input(char *argv[], int count_args)
{
	t_stacka	stack_a;

	stack_a.len_inputs = 0;
	if (count_args == 1)
	{
		stack_a.inputs = ft_split(*argv, ' ');
		while (stack_a.inputs[stack_a.len_inputs])
			stack_a.len_inputs++;
		validate_and_createlist(&stack_a);
	}
	else
	{
		stack_a.inputs = malloc(sizeof(char *) * count_args);
		while (stack_a.len_inputs < count_args)
		{
			stack_a.inputs[stack_a.len_inputs]
				= ft_strdup(argv[stack_a.len_inputs]);
			stack_a.len_inputs++;
		}
		validate_and_createlist(&stack_a);
	}
	send_to_sort(&stack_a);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		exit(0);
	if (argc >= 2)
	{
		store_input(&argv[1], argc - 1);
	}
	return (0);
}
