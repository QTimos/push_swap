/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:50:50 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/07 17:31:57 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

static int	do_move(char *move, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(move, "sa\n"))
		ft_swap(a, 'a');
	else if (!ft_strcmp(move, "sb\n"))
		ft_swap(b, 'b');
	else if (!ft_strcmp(move, "ss\n"))
		(ft_swap(a, 'a'), ft_swap(b, 'b'));
	else if (!ft_strcmp(move, "pa\n"))
		ft_push(b, a, 'a');
	else if (!ft_strcmp(move, "pb\n"))
		ft_push(a, b, 'b');
	else if (!ft_strcmp(move, "ra\n"))
		ft_rotate(a, 'a');
	else if (!ft_strcmp(move, "rb\n"))
		ft_rotate(b, 'b');
	else if (!ft_strcmp(move, "rr\n"))
		(ft_rotate(a, 'a'), ft_rotate(b, 'b'));
	else if (!ft_strcmp(move, "rra\n"))
		ft_rrotate(a, 'a');
	else if (!ft_strcmp(move, "rrb\n"))
		ft_rrotate(b, 'b');
	else if (!ft_strcmp(move, "rrr\n"))
		(ft_rrotate(a, 'a'), ft_rrotate(b, 'b'));
	else
		return (0);
	return (1);
}

static int	free_and_handle_error(int mode, t_stack **a, t_stack **b,
		char *move)
{
	if (move)
		free(move);
	free_stack(a);
	free_stack(b);
	if (mode == 1)
		return (write(2, "Error\n", 6));
	return (0);
}

char	*read_line(int fd)
{
	char	c;
	ssize_t	bytes;
	char	*result;
	int		i;

	result = malloc(6);
	if (!result)
		return (NULL);
	i = 0;
	bytes = read(fd, &c, 1);
	while (bytes > 0 && c != '\n')
	{
		if (i < 3)
			result[i++] = c;
		bytes = read(fd, &c, 1);
	}
	if (bytes <= 0 && i == 0)
		return (free(result), NULL);
	if (bytes > 0 && (i < 2 || i > 3))
		return (free(result), NULL);
	result[i++] = c;
	result[i] = 0;
	return (result);
}

void	set_move(char **move)
{
	free(*move);
	*move = read_line(0);
}

int	main(int argc, char **argv)
{
	int		size;
	char	*move;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	size = handle_input(argc, argv);
	if (size == -1 || there_is_duplicates(argv, argc, size) || (init_stack(&a,
				size, argc, argv), !a))
		return (write(2, "Error\n", 6), 1);
	move = read_line(0);
	while (move)
	{
		if (!do_move(move, &a, &b))
			return (free_and_handle_error(1, &a, &b, move), 1);
		set_move(&move);
	}
	if (a && sorted(&a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_and_handle_error(0, &a, &b, move));
}
