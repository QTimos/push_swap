/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:01:22 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/03 12:56:38 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	is_number(char *s)
{
	int			i;
	long long	num;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	num = ft_atoll((const char *)s);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

static int	check_number(char *s, int start, int len)
{
	char	*n;

	n = malloc(len + 1);
	if (!n)
		return (0);
	ft_strlcpy(n, &s[start], len + 1);
	if (!is_number(n))
		return (free(n), 0);
	free(n);
	return (1);
}

static int	check_digits(char *s, int *i, int *len, int *has_digit)
{
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		(*len)++;
		(*i)++;
		*has_digit = 1;
	}
	return (1);
}

size_t	is_string_of_numbers(char *s, int i)
{
	int	len;
	int	has_digit;

	has_digit = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		if (s[i] == '-' || s[i] == '+')
		{
			i++;
			len++;
		}
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		check_digits(s, &i, &len, &has_digit);
		if (s[i] && s[i] != ' ')
			return (0);
		if (!check_number(s, i - len, len))
			return (0);
	}
	return (has_digit);
}

int	handle_input(int argc, char **argv)
{
	int	count;

	count = 0;
	if (argc >= 2)
	{
		argv++;
		while (*argv)
		{
			if (!is_number(*argv) && !is_string_of_numbers(*argv, 0))
				return (-1);
			if (is_string_of_numbers(*argv, 0))
				count += ft_count_nums(*argv, ' ');
			else
				count++;
			argv++;
		}
		return (count);
	}
	return (-1);
}
