/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:42:30 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/01 14:20:54 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_ops(t_oper *ops)
{
	t_oper	*cur;

	cur = ops;
	while (cur)
	{
		ft_putstr(cur->op);
		ft_putstr("\n");
		cur = cur->next;
	}
}

void	optimize_ops(t_oper **ops)
{
	int	changed;

	if (!ops || !(*ops))
		return ;
	changed = 1;
	while (changed)
	{
		changed = 0;
		if (remove_canceling_ops(ops))
			changed = 1;
		if (combine_operations(ops))
			changed = 1;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_oper	*o;
	int		size;

	size = handle_input(argc, argv);
	if (size == -1 || there_is_duplicates(argv, argc, size))
		return (write(2, "Error\n", 6), 1);
	a = NULL;
	b = NULL;
	o = NULL;
	init_stack(&a, size, argc, argv);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	if (sorted(&a))
		return (free_stack(&a), 0);
	sort_stack(&a, &b, &o);
	optimize_ops(&o);
	print_ops(o);
	free_stack(&a);
	free_ops_stack(&o);
	return (0);
}
