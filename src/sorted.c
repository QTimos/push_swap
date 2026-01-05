/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:56:16 by hdyani            #+#    #+#             */
/*   Updated: 2025/12/31 19:32:21 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sorted(t_stack **s)
{
	t_stack	*current;
	t_stack	*prev;

	current = *s;
	while (current->next)
	{
		prev = current;
		current = current->next;
		if (prev->value > current->value)
			return (0);
	}
	return (1);
}
