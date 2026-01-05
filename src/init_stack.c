/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:07:24 by hdyani            #+#    #+#             */
/*   Updated: 2025/12/31 19:34:23 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*create_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->stack_name = 'a';
	node->next = NULL;
	return (node);
}

int	stack_size(t_stack *s)
{
	int	count;

	count = 0;
	while (s)
	{
		s = s->next;
		count++;
	}
	return (count);
}

static int	flatten_arg(char *arg, char **flat, int *k)
{
	char	**split;
	int		i;

	if (!is_string_of_numbers(arg, 0))
	{
		flat[*k] = ft_strdup(arg);
		(*k)++;
		return (!flat[*k - 1]);
	}
	split = ft_split(arg, ' ');
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		flat[*k] = ft_strdup(split[i]);
		if (!flat[(*k)++])
			return (free_char_arr(split, i + 1), 1);
		free(split[i++]);
	}
	free(split);
	return (0);
}

char	**flatten_args(char **argv, int argc, int size)
{
	char	**flat;
	int		i;
	int		k;
	int		error;

	flat = malloc(sizeof(char *) * (size + 1));
	if (!flat)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		error = flatten_arg(argv[i], flat, &k);
		if (error)
			return (free_char_arr(flat, k), NULL);
		i++;
	}
	flat[k] = NULL;
	return (flat);
}

void	init_stack(t_stack **s, int size, int argc, char **argv)
{
	char	**flat;
	int		i;
	t_stack	*node;
	t_stack	*cur;

	flat = flatten_args(argv, argc, size);
	if (!flat)
		return ;
	i = 0;
	node = create_new_node((int)ft_atoll(flat[i]));
	if (!node)
	{
		free_char_arr(flat, size);
		return ;
	}
	*s = node;
	cur = node;
	while (i < size - 1)
	{
		node = create_new_node((int)ft_atoll(flat[++i]));
		cur->next = node;
		cur = node;
	}
	free_char_arr(flat, size);
}
