/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:13:08 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/06 14:53:07 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	ft_swap(t_stack **s, char name)
{
	t_stack	*head;
	t_stack	*next;

	(void)name;
	if (!s || !(*s) || !(*s)->next)
		return ;
	head = *s;
	next = (*s)->next;
	head->next = next->next;
	next->next = head;
	*s = next;
}

void	ft_push(t_stack **s1, t_stack **s2, char name)
{
	t_stack	*node;

	if (!s1 || !(*s1))
		return ;
	node = *s1;
	*s1 = node->next;
	node->next = *s2;
	node->stack_name = name;
	*s2 = node;
}

void	ft_rotate(t_stack **s, char name)
{
	t_stack	*head;
	t_stack	*top;

	if (!s || !(*s) || !(*s)->next)
		return ;
	(void)name;
	head = *s;
	*s = head->next;
	head->next = NULL;
	top = *s;
	while (top->next)
		top = top->next;
	top->next = head;
}

void	ft_rrotate(t_stack **s, char name)
{
	t_stack	*prev;
	t_stack	*top;

	(void)name;
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
}
