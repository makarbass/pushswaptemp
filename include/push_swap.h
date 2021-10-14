/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:58:06 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/14 19:38:25 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_isint(char *str);
int		ft_hasdup(int *nums, int len);
int		convert(char **strs, int **nums);
void	ft_cleanup(char *str, char **strs, int *nums, t_list *stack);
int		is_sorted(t_list *stack);
int		stack_min(t_list *stack);
int		stack_max(t_list *stack);
void	sx(t_list **stack_1, t_list **stack_2);
void	px(t_list **stack_1, t_list **stack_2);
void	rx(t_list **stack_1, t_list **stack_2);
void	rrx(t_list **stack_1, t_list **stack_2);
void	ft_action(char *cmd, t_list **stack_1, t_list **stack_2, int q);
int		stack_idx_mid(t_list *stack, int num);
int		stack_idx_minmax(t_list *stack, int num);
void	find_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);
void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b);
void	sort_3(t_list **stack);
void	sort_big(t_list **stack_a);
void	sort_final(t_list **stack);
void	ft_sort(t_list **stack);

#endif
