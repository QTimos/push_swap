/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:21:15 by hdyani            #+#    #+#             */
/*   Updated: 2025/12/31 19:30:36 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	do_move(char *move, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(move, "sa\n"))
		ft_swap(a, NULL, 'a');
	else if (!ft_strcmp(move, "sb\n"))
		ft_swap(b, NULL, 'b');
	else if (!ft_strcmp(move, "ss\n"))
		(ft_swap(a, NULL, 'a'), ft_swap(b, NULL, 'b'));
	else if (!ft_strcmp(move, "pa\n"))
		ft_push(b, a, NULL, 'a');
	else if (!ft_strcmp(move, "pb\n"))
		ft_push(a, b, NULL, 'b');
	else if (!ft_strcmp(move, "ra\n"))
		ft_rotate(a, NULL, 'a');
	else if (!ft_strcmp(move, "rb\n"))
		ft_rotate(b, NULL, 'b');
	else if (!ft_strcmp(move, "rr\n"))
		(ft_rotate(a, NULL, 'a'), ft_rotate(b, NULL, 'b'));
	else if (!ft_strcmp(move, "rra\n"))
		ft_rrotate(a, NULL, 'a');
	else if (!ft_strcmp(move, "rrb\n"))
		ft_rrotate(b, NULL, 'b');
	else if (!ft_strcmp(move, "rrr\n"))
		(ft_rrotate(a, NULL, 'a'), ft_rrotate(b, NULL, 'b'));
	else
		return (0);
	return (1);
}

static ssize_t	free_and_handle_error(int mode, t_stack **a, t_stack **b,
		char *move)
{
	free(move);
	free_stack(a);
	free_stack(b);
	if (mode == 1)
		return (write(2, "Error\n", 6));
	return (0);
}

char	*read_line(int fd)
{
	char	buffer[1024];
	char	*result;
	char	c;
	int		i;
	int		bytes;

	i = 0;
	bytes = read(fd, &c, 1);
	if (bytes <= 0)
		return (NULL);
	if (c == '\n')
		return (read_line(fd));
	buffer[i++] = c;
	while (i < 1023 && read(fd, &c, 1) > 0 && c != '\n')
		buffer[i++] = c;
	buffer[i] = 0;
	result = malloc(i + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, buffer, i + 1);
	result[i] = '\n';
	result[i + 1] = '\0';
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
	if (size == -1 || there_is_duplicates(argv, argc, size))
		return (write(2, "Error\n", 6), 1);
	init_stack(&a, size, argc, argv);
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
	return (free_and_handle_error(0, &a, &b, NULL));
}
