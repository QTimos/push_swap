/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:02:55 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/06 15:33:37 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	char			stack_name;
	struct s_stack	*next;
}					t_stack;

void				ft_swap(t_stack **s, char name);
void				ft_push(t_stack **s1, t_stack **s2, char name);
void				ft_rotate(t_stack **s, char name);
void				ft_rrotate(t_stack **s, char name);
void				init_stack(t_stack **s, int size, int argc, char **argv);
int					sorted(t_stack **s);
int					handle_input(int argc, char **argv);
long long			ft_atoll(const char *nptr);
size_t				is_string_of_numbers(char *s, int i);
int					there_is_duplicates(char **argv, int argc, int size);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				ft_putstr(char *str);
char				**ft_split(char const *s, char c);
int					ft_count_nums(char const *s, char c);
char				**flatten_args(char **argv, int argc, int size);
void				free_char_arr(char **arr, int k);
void				free_stack(t_stack **s);
char				*read_line(int fd);

#endif
