/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:06:48 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/14 19:14:26 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sx(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	(void)stack_2;
	if (ft_lstsize(*stack_1) >= 2)
	{
		tmp = (*stack_1)->next;
		(*stack_1)->next = tmp->next;
		ft_lstadd_front(stack_1, tmp);
	}
}

void	ft_px(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_1))
	{
		tmp = *stack_1;
		*stack_1 = (*stack_1)->next;
		ft_lstadd_front(stack_2, tmp);
	}
}

void	ft_rx(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	(void)stack_2;
	if (ft_lstsize(*stack_1) >= 2)
	{
		tmp = *stack_1;
		*stack_1 = (*stack_1)->next;
		tmp->next = 0;
		ft_lstadd_back(stack_1, tmp);
	}
}

void	ft_rrx(t_list **stack_1, t_list **stack_2)
{
	t_list	*last;
	t_list	*tmp;

	(void)stack_2;
	if (ft_lstsize(*stack_1) >= 2)
	{
		last = *stack_1;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = 0;
		last->next = *stack_1;
		*stack_1 = last;
	}
}

void	ft_action(char *cmd, t_list **stack_1, t_list **stack_2, int q)
{
	const int	len = ft_strlen(cmd);
	int			tmp;
	void		(*f)(t_list **, t_list **);

	tmp = ft_abs(q);
	if (!ft_strncmp(cmd, "sa", len) || !ft_strncmp(cmd, "sb", len)
		|| !ft_strncmp(cmd, "ss", len))
		f = &ft_sx;
	else if (!ft_strncmp(cmd, "pa", len) || !ft_strncmp(cmd, "pb", len))
		f = &ft_px;
	else if (!ft_strncmp(cmd, "ra", len) || !ft_strncmp(cmd, "rb", len)
		|| !ft_strncmp(cmd, "rr", len))
		f = &ft_rx;
	else
		f = &ft_rrx;
	while (tmp--)
	{
		f(stack_1, stack_2);
		if (stack_2 && f != ft_px)
			f(stack_2, 0);
		if (q > 0)
			ft_putendl_fd(cmd, 1);
	}
}
