/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:19:42 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/01 19:48:27 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_target_in_a(t_stack *a, int value)
{
	t_stack	*target;
	t_stack	*current;

	target = NULL;
	current = a;
	while (current)
	{
		if (current->value > value && (!target
				|| current->value < target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		return (find_min_or_max_of_stack(a, "min"));
	return (target);
}

int	get_move_cost(t_stack *a, t_stack *b, t_stack *node_b)
{
	t_stack	*target;
	int		cost_a;
	int		cost_b;
	int		rotate_a;
	int		rotate_b;

	target = find_target_in_a(a, node_b->value);
	cost_a = stack_size(a) - get_position(a, target);
	cost_b = stack_size(b) - get_position(b, node_b);
	rotate_b = 0;
	rotate_a = 0;
	if (get_position(a, target) <= stack_size(a) / 2)
	{
		rotate_a = 1;
		cost_a = get_position(a, target);
	}
	if (get_position(b, node_b) <= stack_size(b) / 2)
	{
		rotate_b = 1;
		cost_b = get_position(b, node_b);
	}
	return (get_combined_cost(cost_a, cost_b, rotate_a, rotate_b));
}

t_stack	*find_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*current;
	int		min_cost;
	int		cost;

	cheapest = b;
	min_cost = get_move_cost(a, b, b);
	current = b->next;
	while (current)
	{
		cost = get_move_cost(a, b, current);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

void	do_cheapest_move(t_stack **a, t_stack **b, t_stack *node, t_oper **ops)
{
	t_stack	*target;
	int		rotate_a;
	int		rotate_b;

	target = find_target_in_a(*a, node->value);
	rotate_a = (get_position(*a, target) <= stack_size(*a) / 2);
	rotate_b = (get_position(*b, node) <= stack_size(*b) / 2);
	if (rotate_a && rotate_b)
		while (*a != target && *b != node)
			sync_rotate(a, b, 0, ops);
	else if (!rotate_a && !rotate_b)
		while (*a != target && *b != node)
			sync_rotate(a, b, 1, ops);
	finish_stack(a, target, rotate_a, ops);
	finish_stack(b, node, rotate_b, ops);
	ft_push(b, a, ops, 'a');
}

void	push_back(t_stack **a, t_stack **b, t_oper **ops)
{
	t_stack	*cheapest;

	while (*b)
	{
		cheapest = find_cheapest(*a, *b);
		do_cheapest_move(a, b, cheapest, ops);
	}
	bring_min_to_top(a, ops);
}
