/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:28:29 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/14 19:04:52 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*((int *)stack->content) > *((int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_3(t_list **stack)
{
	const int	num_1 = *((int *)(*stack)->content);
	const int	num_2 = *((int *)(*stack)->next->content);
	const int	num_3 = *((int *)(*stack)->next->next->content);

	if (num_1 == stack_min(*stack) && num_2 == stack_max(*stack))
	{
		ft_action("sa", stack, 0, 1);
		ft_action("ra", stack, 0, 1);
	}
	else if (num_2 == stack_min(*stack) && num_3 == stack_max(*stack))
		ft_action("sa", stack, 0, 1);
	else if (num_3 == stack_min(*stack) && num_2 == stack_max(*stack))
		ft_action("rra", stack, 0, 1);
	else if (num_2 == stack_min(*stack) && num_1 == stack_max(*stack))
		ft_action("ra", stack, 0, 1);
	else
	{
		ft_action("sa", stack, 0, 1);
		ft_action("rra", stack, 0, 1);
	}
}

void	sort_big(t_list **stack_a)
{
	int		a;
	int		b;
	t_list	*stack_b;

	stack_b = 0;
	while (ft_lstsize(*stack_a) > 3)
		ft_action("pb", stack_a, &stack_b, 1);
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	while (ft_lstsize(stack_b))
	{
		a = 0;
		b = 0;
		find_min_rotate(*stack_a, stack_b, &a, &b);
		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
			rotate_same(stack_a, &stack_b, a, b);
		else
			rotate_diff(stack_a, &stack_b, a, b);
		ft_action("pa", &stack_b, stack_a, 1);
	}
}

void	sort_final(t_list **stack)
{
	const int	i = stack_idx_minmax(*stack, stack_min(*stack));

	if (i < 0)
		ft_action("rra", stack, 0, -i);
	else
		ft_action("ra", stack, 0, i);
}

void	ft_sort(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		ft_action("sa", stack, 0, 1);
	else if (ft_lstsize(*stack) == 3)
		sort_3(stack);
	else
		sort_big(stack);
	sort_final(stack);
}
