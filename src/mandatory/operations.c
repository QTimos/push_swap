/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:13:08 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/05 18:38:10 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	record_op(char *op, t_oper **ops)
{
	t_oper	*node;
	t_oper	*tmp;

	node = malloc(sizeof(t_oper));
	if (!node || !ops)
		return ;
	node->op = ft_strdup(op);
	node->next = NULL;
	if (!(*ops))
	{
		*ops = node;
		return ;
	}
	tmp = *ops;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	ft_swap(t_stack **s, t_oper **ops, char name)
{
	t_stack	*head;
	t_stack	*next;

	if (!s || !(*s) || !(*s)->next)
		return ;
	head = *s;
	next = (*s)->next;
	head->next = next->next;
	next->next = head;
	*s = next;
	if (name == 'a' && ops)
		record_op("sa", ops);
	else if (name == 'b' && ops)
		record_op("sb", ops);
}

void	ft_push(t_stack **s1, t_stack **s2, t_oper **ops, char name)
{
	t_stack	*node;

	if (!s1 || !(*s1))
		return ;
	node = *s1;
	*s1 = node->next;
	node->next = *s2;
	node->stack_name = name;
	*s2 = node;
	if (name == 'a' && ops)
		record_op("pa", ops);
	else if (name == 'b' && ops)
		record_op("pb", ops);
}

void	ft_rotate(t_stack **s, t_oper **ops, char name)
{
	t_stack	*head;
	t_stack	*top;

	if (!s || !(*s) || !(*s)->next)
		return ;
	head = *s;
	*s = head->next;
	head->next = NULL;
	top = *s;
	while (top->next)
		top = top->next;
	top->next = head;
	if (name == 'a' && ops)
		record_op("ra", ops);
	else if (name == 'b' && ops)
		record_op("rb", ops);
}

void	ft_rrotate(t_stack **s, t_oper **ops, char name)
{
	t_stack	*prev;
	t_stack	*top;

	if (!s || !(*s) || !(*s)->next)
		return ;
	prev = NULL;
	top = *s;
	while (top->next)
	{
		prev = top;
		top = top->next;
	}
	prev->next = NULL;
	top->next = *s;
	*s = top;
	if (name == 'a' && ops)
		record_op("rra", ops);
	else if (name == 'b' && ops)
		record_op("rrb", ops);
}
