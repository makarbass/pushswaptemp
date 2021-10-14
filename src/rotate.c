/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:24:45 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/14 19:28:53 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b)
{
	const int	size_b = ft_lstsize(stack_b);
	int			i;
	int			j;
	int			num;
	int			x;

	x = -1;
	while (stack_b && ++x >= 0)
	{
		num = *((int *)stack_b->content);
		if (num < stack_min(stack_a) || num > stack_max(stack_a))
			i = stack_idx_minmax(stack_a, num);
		else
			i = stack_idx_mid(stack_a, num);
		j = x;
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (x == 0 || ft_abs(*a) + ft_abs(*b) > ft_abs(i) + ft_abs(j))
		{
			*a = i;
			*b = j;
		}
		stack_b = stack_b->next;
	}
}

void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		ft_action("rr", stack_a, stack_b, ft_less(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			ft_action("rb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			ft_action("ra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
	else
	{
		ft_action("rrr", stack_a, stack_b, ft_less(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			ft_action("rrb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			ft_action("rra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
}

void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a >= 0 && b < 0)
	{
		ft_action("ra", stack_a, 0, a);
		ft_action("rrb", stack_b, 0, ft_abs(ft_less(a, b)));
	}
	else
	{
		ft_action("rb", stack_b, 0, b);
		ft_action("rra", stack_a, 0, ft_abs(ft_less(a, b)));
	}
}
