/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:54:55 by hdyani            #+#    #+#             */
/*   Updated: 2026/01/05 20:53:46 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_oper
{
	char			*op;
	struct s_oper	*next;
}					t_oper;

typedef struct s_stack
{
	int				value;
	char			stack_name;
	struct s_stack	*next;
}					t_stack;

typedef struct s_push_params
{
	int				target;
	int				size;
	int				min_val;
	int				max_val;
	int				median;
	int				range;
	int				pushed;
}					t_push_params;

long long			ft_atoll(const char *nptr);
char				**ft_split(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				ft_putstr(char *str);
int					ft_count_nums(char const *s, char c);
size_t				is_string_of_numbers(char *s, int i);
int					handle_input(int argc, char **argv);
int					there_is_duplicates(char **argv, int argc, int size);
char				**flatten_args(char **argv, int argc, int size);
void				init_stack(t_stack **s, int size, int argc, char **argv);
int					stack_size(t_stack *s);
void				record_op(char *op, t_oper **ops);
void				ft_swap(t_stack **s, t_oper **ops, char name);
void				ft_push(t_stack **s1, t_stack **s2, t_oper **ops, char n);
void				ft_rotate(t_stack **s, t_oper **ops, char name);
void				ft_rrotate(t_stack **s, t_oper **ops, char name);
void				remove_last_op(t_oper **ops);
int					remove_canceling_ops(t_oper **ops);
int					combine_operations(t_oper **ops);
void				optimize_ops(t_oper **ops);
void				print_ops(t_oper *ops);
int					sorted(t_stack **s);
void				sort_three(t_stack **s, t_oper **ops);
void				bring_min_to_top(t_stack **s, t_oper **ops);
void				sort_stack(t_stack **s1, t_stack **s2, t_oper **ops);
t_stack				*find_min_or_max_of_stack(t_stack *s, const char *flag);
int					get_position(t_stack *stack, t_stack *node);
void				sync_rotate(t_stack **a, t_stack **b, int reverse,
						t_oper **ops);
int					get_combined_cost(int cost_a, int cost_b, int rotate_a,
						int rotate_b);
void				finish_stack(t_stack **s, t_stack *target, int rotate,
						t_oper **ops);
int					get_push_condition(t_stack **a, t_push_params par,
						int rotations);
void				push_first_two(t_stack **a, t_stack **b, int *pushed,
						t_oper **ops);
void				push_remaining(t_stack **a, t_stack **b, t_oper **ops,
						t_push_params *par);
void				push_to_b(t_stack **a, t_stack **b, int size, t_oper **ops);
t_stack				*find_target_in_a(t_stack *a, int value);
int					get_move_cost(t_stack *a, t_stack *b, t_stack *node_b);
t_stack				*find_cheapest(t_stack *a, t_stack *b);
void				do_cheapest_move(t_stack **a, t_stack **b, t_stack *node,
						t_oper **ops);
void				push_back(t_stack **a, t_stack **b, t_oper **ops);
void				free_char_arr(char **arr, int k);
void				free_stack(t_stack **s);
void				free_ops_stack(t_oper **s);

#endif
