/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:31:33 by lfranca-          #+#    #+#             */
/*   Updated: 2022/01/09 18:44:35 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	change_minindex(t_simplify *st, int i)
{
	if (i == -1)
		st->minindex++;
	else
		st->minindex = st->i;
	st->is_minindex_changed = 1;
}

static void	find_minindex(t_simplify *st, t_stacka *stack_a)
{
	if (st->j == 0)
	{
		if (ft_atoi(stack_a->inputs[st->minindex])
			> ft_atoi(stack_a->inputs[st->i]))
			change_minindex(st, st->i);
	}
	else if (st->j > 0)
	{
		if ((ft_atoi(stack_a->inputs[st->i]) > st->prev_value)
			&& (ft_atoi(stack_a->inputs[st->minindex])
				> ft_atoi(stack_a->inputs[st->i])))
			change_minindex(st, st->i);
		else if (ft_atoi(stack_a->inputs[st->minindex]) < st->prev_value
			|| (st->j > 0
				&& ft_atoi(stack_a->inputs[st->minindex]) == st->prev_value))
		{
			change_minindex(st, -1);
			st->initial_loop_position++;
		}
	}
}

static void	init_simplify_struct(t_simplify *st, t_stacka *stack_a)
{
	st->prev_value = 0;
	st->minindex = 0;
	st->j = 0;
	st->initial_loop_position = st->minindex;
	st->is_minindex_changed = 0;
	st->arr_simplify = malloc(sizeof(char *) * stack_a->len_inputs);
}

static void	passing_into_input(t_stacka *stack_a, t_simplify *st)
{
	free_argvs(stack_a);
	stack_a->inputs = malloc(sizeof(char *) * stack_a->len_inputs);
	st->j = 0;
	while (st->j < stack_a->len_inputs)
	{
		stack_a->inputs[st->j] = ft_strdup(st->arr_simplify[st->j]);
		free(st->arr_simplify[st->j]);
		st->j++;
	}
	free(st->arr_simplify);
}

void	simplify_numbers(t_stacka *stack_a)
{
	t_simplify	st;

	init_simplify_struct(&st, stack_a);
	while (st.j < stack_a->len_inputs)
	{
		st.i = st.minindex + 1;
		while (st.i < stack_a->len_inputs)
		{
			find_minindex(&st, stack_a);
			st.i++;
		}
		st.prev_value = ft_atoi(stack_a->inputs[st.minindex]);
		if (st.is_minindex_changed == 0)
			st.initial_loop_position++;
		st.arr_simplify[st.minindex] = ft_itoa(st.j);
		st.minindex = st.initial_loop_position;
		st.is_minindex_changed = 0;
		st.j++;
	}
	passing_into_input(stack_a, &st);
}

 /* GERAR INPUT DENTRO DE UM RANGE ALEATORIO NO TERMINAL:::::::::::::::::: 
 
 MYVAR=$(seq 500 | shuf) // esse 500 é o 'n' e pode ser substituido pelo total de elementos do range, de 1 até n, basicamente
 ./push_swop2 $MYVAR
 */