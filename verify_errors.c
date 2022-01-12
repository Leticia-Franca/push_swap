/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:32:20 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/09 18:47:48 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	ft_isnumber(char *c)
{
	int	j;
	int	is_number;

	j = 0;
	is_number = 1;
	while (c[j] != '\0')
	{
		if (c[j] == '-' || c[j] == '+')
			j++;
		else if (c[j] < 48 || c[j] > 57)
			is_number = 0;
		j++;
	}
	return (is_number);
}

void	check_isnumber(t_stacka *stack_a)
{
	int	counter;
	int	ret;

	ret = 1;
	counter = -1;
	while (++counter < stack_a->len_inputs)
	{
		ret = ft_isnumber(stack_a->inputs[counter]);
		if (ret == 0)
		{
			free_argvs(stack_a);
			ft_error();
		}
	}
}

static void	is_range(long long int value, t_stacka *stack_a)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		free_argvs(stack_a);
		ft_error();
	}
}

void	ft_no_duplicates(t_stacka *stack_a)
{
	long long int	value;
	long long int	next_value;
	int				i;
	int				j;

	i = 0;
	value = atoi_long(stack_a->inputs[i]);
	is_range(value, stack_a);
	while (i < (stack_a->len_inputs - 1))
	{
		j = i;
		while (++j < stack_a->len_inputs)
		{
			next_value = atoi_long(stack_a->inputs[j]);
			if (i == 0)
				is_range(next_value, stack_a);
			if (value == next_value)
			{
				free_argvs(stack_a);
				ft_error();
			}
		}
		i++;
		value = atoi_long(stack_a->inputs[i]);
	}
}
