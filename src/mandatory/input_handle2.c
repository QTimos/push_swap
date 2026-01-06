/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:55:01 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/05 18:32:09 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_handle_sign(const char *nptr, int *i, int *sign)
{
	if (nptr[*i] == '-')
		*sign = -(*sign);
	(*i)++;
}

int	there_is_duplicates(char **argv, int argc, int size)
{
	int		i;
	int		j;
	char	**arr;

	arr = flatten_args(argv, argc, size);
	if (!arr)
		return (1);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoll(arr[i]) == ft_atoll(arr[j]))
			{
				free_char_arr(arr, size);
				return (1);
			}
			j++;
		}
		i++;
	}
	free_char_arr(arr, size);
	return (0);
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			sign;
	long long	atoll;

	i = 0;
	atoll = 0;
	sign = 1;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		ft_handle_sign(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (sign == 1 && (atoll > 214748364 || (atoll == 214748364
					&& nptr[i] > '7')))
			return (9999999999);
		if (sign == -1 && (atoll > 214748364 || (atoll == 214748364
					&& nptr[i] > '8')))
			return (-9999999999);
		atoll = (atoll * 10) + (nptr[i] - '0');
		i++;
	}
	return (atoll * sign);
}
