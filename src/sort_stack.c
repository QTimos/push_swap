/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:05:46 by hdyani            #+#    #+#             */
/*   Updated: 2025/12/31 19:32:10 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **s, t_oper **ops)
{
	int	first;
	int	second;
	int	third;

	if (!s || !(*s) || !(*s)->next || !(*s)->next->next)
		return ;
	first = (*s)->value;
	second = (*s)->next->value;
	third = (*s)->next->next->value;
	if (first > second && second < third && first < third)
		ft_swap(s, ops, 'a');
	else if (first < second && second > third && first > third)
		ft_rrotate(s, ops, 'a');
	else if (first > second && second > third)
	{
		ft_swap(s, ops, 'a');
		ft_rrotate(s, ops, 'a');
	}
	else if (first > second && second < third && first > third)
		ft_rotate(s, ops, 'a');
	else if (first < second && second > third && first < third)
	{
		ft_swap(s, ops, 'a');
		ft_rotate(s, ops, 'a');
	}
}

void	bring_min_to_top(t_stack **s, t_oper **ops)
{
	t_stack	*min;
	t_stack	*current;
	int		pos;
	int		size;

	size = stack_size(*s);
	min = find_min_or_max_of_stack(*s, "min");
	current = *s;
	pos = 0;
	while (current && current != min)
	{
		current = current->next;
		pos++;
	}
	if (pos < size / 2)
		while (*s != min)
			ft_rotate(s, ops, 'a');
	else
		while (*s != min)
			ft_rrotate(s, ops, 'a');
}

static void	sort_five(t_stack **s1, t_stack **s2, t_oper **ops)
{
	if (stack_size(*s1) <= 3)
	{
		sort_three(s1, ops);
		return ;
	}
	bring_min_to_top(s1, ops);
	ft_push(s1, s2, ops, 'b');
	sort_five(s1, s2, ops);
	ft_push(s2, s1, ops, 'a');
}

void	sort_stack(t_stack **s1, t_stack **s2, t_oper **ops)
{
	int	size;

	if (!s1)
		return ;
	size = stack_size(*s1);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*s1)->value > ((*s1)->next)->value)
			ft_swap(s1, ops, 'a');
	}
	else if (size == 3)
		sort_three(s1, ops);
	else if (size <= 5)
		sort_five(s1, s2, ops);
	else
	{
		push_to_b(s1, s2, size, ops);
		sort_three(s1, ops);
		push_back(s1, s2, ops);
	}
}
