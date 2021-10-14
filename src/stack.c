/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:27:07 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/14 19:28:59 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_min(t_list *stack)
{
	int		min;
	int		num;

	min = *((int *)stack->content);
	while (stack)
	{
		num = *((int *)stack->content);
		if (min > num)
			min = num;
		stack = stack->next;
	}
	return (min);
}

int	stack_max(t_list *stack)
{
	int		max;
	int		num;

	max = *((int *)stack->content);
	while (stack)
	{
		num = *((int *)stack->content);
		if (max < num)
			max = num;
		stack = stack->next;
	}
	return (max);
}

int	stack_idx_mid(t_list *stack, int num)
{
	const int	size = ft_lstsize(stack);
	int			ret;
	int			current;
	int			next;

	ret = 1;
	while (stack->next)
	{
		current = *((int *)stack->content);
		next = *((int *)stack->next->content);
		if (num > current && num < next)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret == size)
		ret = 0;
	else if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

int	stack_idx_minmax(t_list *stack, int num)
{
	const int	size = ft_lstsize(stack);
	int			ret;
	int			x;

	ret = 0;
	x = stack_max(stack);
	if (num <= stack_min(stack))
		x = stack_min(stack);
	else
		++ret;
	while (stack)
	{
		if (*((int *)stack->content) == x)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}
