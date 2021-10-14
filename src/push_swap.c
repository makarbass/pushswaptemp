/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:49:26 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/14 21:35:26 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	convert(char **strs, int **nums)
{
	int	i;
	int	ret;
	int	*tmp;

	i = 0;
	while (strs[i])
		if (!ft_isint(strs[i++]))
			return (0);
	ret = i;
	tmp = malloc(sizeof(int) * i);
	if (!tmp)
		return (0);
	while (i--)
		tmp[i] = ft_atoi(strs[i]);
	if (ft_hasdup(tmp, ret))
	{
		free(tmp);
		ret = 0;
	}
	*nums = tmp;
	return (ret);
}

void	ft_cleanup(char *str, char **strs, int *nums, t_list *stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	free(str);
	free(nums);
	while (strs[i])
		free(strs[i++]);
	free(strs);
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**strs;
	int		*nums;
	int		len;
	t_list	*stack;

	if (argc > 1)
	{
		nums = 0;
		stack = 0;
		str = ft_join(argv + 1, " ");
		strs = ft_split(str, ' ');
		len = convert(strs, &nums);
		if (!len)
		{
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(&nums[len]));
		if (!is_sorted(stack))
			ft_sort(&stack);
		ft_cleanup(str, strs, nums, stack);
	}
	return (0);
}
