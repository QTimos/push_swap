/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 10:13:42 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/06 14:46:49 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	free_char_arr(char **arr, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_stack **s)
{
	t_stack	*curr;
	t_stack	*prev;

	if (!s || !*s)
		return ;
	curr = *s;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}
