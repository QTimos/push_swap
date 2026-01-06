/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_optimize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:22:33 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/05 18:38:05 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	remove_last_op(t_oper **ops)
{
	t_oper	*tmp;
	t_oper	*prev;

	if (!ops || !(*ops))
		return ;
	tmp = *ops;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev)
		*ops = NULL;
	else
		prev->next = NULL;
	free(tmp->op);
	free(tmp);
}

static int	ops_cancel(char *op1, char *op2)
{
	if (!ft_strcmp(op1, "ra") && !ft_strcmp(op2, "rra"))
		return (1);
	if (!ft_strcmp(op1, "rra") && !ft_strcmp(op2, "ra"))
		return (1);
	if (!ft_strcmp(op1, "rb") && !ft_strcmp(op2, "rrb"))
		return (1);
	if (!ft_strcmp(op1, "rrb") && !ft_strcmp(op2, "rb"))
		return (1);
	if (!ft_strcmp(op1, "sa") && !ft_strcmp(op2, "sa"))
		return (1);
	if (!ft_strcmp(op1, "sb") && !ft_strcmp(op2, "sb"))
		return (1);
	return (0);
}

int	remove_canceling_ops(t_oper **ops)
{
	t_oper	*prev;
	t_oper	*last;

	if (!ops || !(*ops) || !(*ops)->next)
		return (0);
	prev = NULL;
	last = *ops;
	while (last && last->next)
	{
		prev = last;
		last = last->next;
	}
	if (!prev || !last)
		return (0);
	if (ops_cancel(prev->op, last->op))
	{
		remove_last_op(ops);
		remove_last_op(ops);
		return (1);
	}
	return (0);
}

static int	try_combine(t_oper *prev, t_oper *last)
{
	if ((!ft_strcmp(prev->op, "sa") && !ft_strcmp(last->op, "sb"))
		|| (!ft_strcmp(prev->op, "sb") && !ft_strcmp(last->op, "sa")))
	{
		free(prev->op);
		prev->op = ft_strdup("ss");
		return (1);
	}
	if ((!ft_strcmp(prev->op, "ra") && !ft_strcmp(last->op, "rb"))
		|| (!ft_strcmp(prev->op, "rb") && !ft_strcmp(last->op, "ra")))
	{
		free(prev->op);
		prev->op = ft_strdup("rr");
		return (1);
	}
	if ((!ft_strcmp(prev->op, "rra") && !ft_strcmp(last->op, "rrb"))
		|| (!ft_strcmp(prev->op, "rrb") && !ft_strcmp(last->op, "rra")))
	{
		free(prev->op);
		prev->op = ft_strdup("rrr");
		return (1);
	}
	return (0);
}

int	combine_operations(t_oper **ops)
{
	t_oper	*prev;
	t_oper	*last;

	if (!ops || !(*ops) || !(*ops)->next)
		return (0);
	prev = NULL;
	last = *ops;
	while (last && last->next)
	{
		prev = last;
		last = last->next;
	}
	if (!prev || !last)
		return (0);
	if (try_combine(prev, last))
		return (remove_last_op(ops), 1);
	return (0);
}
