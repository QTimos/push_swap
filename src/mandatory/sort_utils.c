/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:44:43 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/05 18:32:47 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sync_rotate(t_stack **a, t_stack **b, int reverse, t_oper **ops)
{
	if (reverse)
	{
		ft_rrotate(a, NULL, 'a');
		ft_rrotate(b, NULL, 'b');
		record_op("rrr", ops);
	}
	else
	{
		ft_rotate(a, NULL, 'a');
		ft_rotate(b, NULL, 'b');
		record_op("rr", ops);
	}
}

int	get_combined_cost(int cost_a, int cost_b, int rotate_a, int rotate_b)
{
	if (rotate_a == rotate_b)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

void	finish_stack(t_stack **s, t_stack *target, int rotate, t_oper **ops)
{
	char	stack_name;

	if (*s == target)
		return ;
	stack_name = (*s)->stack_name;
	while (*s != target)
	{
		if (rotate)
			ft_rotate(s, ops, stack_name);
		else
			ft_rrotate(s, ops, stack_name);
	}
}

t_stack	*find_min_or_max_of_stack(t_stack *s, const char *flag)
{
	t_stack	*ret;
	int		is_min;

	if (!s)
		return (NULL);
	ret = s;
	is_min = (ft_strcmp(flag, "min") == 0);
	while (s)
	{
		if (is_min)
		{
			if (s->value < ret->value)
				ret = s;
		}
		else if (s->value > ret->value)
			ret = s;
		s = s->next;
	}
	return (ret);
}
