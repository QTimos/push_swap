/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:00:42 by hdyani            #+#    #+#             */
/*   Updated: 2025/12/31 19:31:01 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_nums(char const *s, char c)
{
	int	i;
	int	wc;
	int	in_word;

	i = 0;
	wc = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			wc++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (wc);
}

static int	*ft_count_wlens(char const *s, char c, int wc)
{
	int	i;
	int	j;
	int	count;
	int	*wlens;

	i = 0;
	j = 0;
	wlens = malloc(sizeof(int) * wc);
	if (!wlens)
		return (NULL);
	while (s[i] && j < wc)
	{
		count = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		wlens[j++] = count;
	}
	return (wlens);
}

static void	ft_fill_split(char const *s, char c, char **split, int wc)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < wc)
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			split[j][k++] = s[i];
			i++;
		}
		split[j][k] = 0;
		j++;
	}
}

static int	ft_allocate_split(int wc, char **split, int *wlens)
{
	int	i;

	i = 0;
	while (i < wc)
	{
		split[i] = malloc(sizeof(char) * (wlens[i] + 1));
		if (!split[i])
		{
			while (i > 0)
				free(split[--i]);
			free(wlens);
			free(split);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	int		*wlens;
	int		allo;
	char	**split;

	if (!s)
		return (NULL);
	wc = ft_count_nums(s, c);
	split = malloc((sizeof(char *) * (wc + 1)));
	if (!split)
		return (NULL);
	wlens = ft_count_wlens(s, c, wc);
	if (!wlens)
	{
		free(split);
		return (NULL);
	}
	allo = ft_allocate_split(wc, split, wlens);
	if (allo)
		return (NULL);
	ft_fill_split(s, c, split, wc);
	split[wc] = NULL;
	free(wlens);
	return (split);
}
