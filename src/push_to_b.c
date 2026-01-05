/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:32:10 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/01 17:35:56 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_position(t_stack *stack, t_stack *node)
{
	int	pos;

	pos = 0;
	while (stack && stack != node)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	get_push_condition(t_stack **a, t_push_params par, int rotations)
{
	int	size;
	int	diff;
	int	value;
	int	median;

	value = (*a)->value;
	median = par.median;
	size = stack_size(*a);
	if (value > median)
		diff = value - median;
	else
		diff = median - value;
	if (par.size <= 100)
		return (diff < par.range || par.pushed > 40 || size <= 15
			|| rotations >= 50);
	return (diff < par.range || par.pushed > par.target - 15 || size <= 10
		|| rotations >= par.size);
}

void	push_first_two(t_stack **a, t_stack **b, int *pushed, t_oper **ops)
{
	if (*pushed < 1 && *a)
	{
		ft_push(a, b, ops, 'b');
		(*pushed)++;
	}
	if (*pushed < 2 && *a)
	{
		ft_push(a, b, ops, 'b');
		(*pushed)++;
		if (*b && (*b)->next && (*b)->value < (*b)->next->value)
			ft_swap(b, ops, 'b');
	}
}

void	push_remaining_elements(t_stack **a, t_stack **b, t_oper **ops,
		t_push_params *par)
{
	int	rotations;

	rotations = 0;
	while (par->pushed < par->target && *a)
	{
		if (get_push_condition(a, *par, rotations))
		{
			ft_push(a, b, ops, 'b');
			if (*b && (*b)->next && stack_size(*b) > 2)
			{
				if ((*b)->value > par->median
					&& (*b)->next->value < par->median)
					ft_rotate(b, ops, 'b');
			}
			par->pushed++;
			rotations = 0;
		}
		else
		{
			ft_rotate(a, ops, 'a');
			rotations++;
			if (rotations % 25 == 0)
				par->range += (par->max_val - par->min_val) / 8;
		}
	}
}

void	push_to_b(t_stack **a, t_stack **b, int size, t_oper **ops)
{
	t_push_params	par;
	int				pushed;

	pushed = 0;
	par.target = size - 3;
	par.size = size;
	par.max_val = (find_min_or_max_of_stack(*a, "max"))->value;
	par.min_val = (find_min_or_max_of_stack(*a, "min"))->value;
	par.median = par.min_val / 2 + par.max_val / 2 + (par.max_val % 2
			+ par.min_val % 2) / 2;
	par.range = (par.max_val - par.min_val) / 3;
	push_first_two(a, b, &pushed, ops);
	par.pushed = pushed;
	push_remaining_elements(a, b, ops, &par);
	while (stack_size(*a) > 3 && *a)
		ft_push(a, b, ops, 'b');
}
