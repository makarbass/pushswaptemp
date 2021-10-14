/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:20:09 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/14 19:35:37 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char **strs, char *sep)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	while (strs[i])
	{
		if (!i)
			str = ft_strdup(strs[i++]);
		else
		{
			tmp = str;
			str = ft_strjoin(str, sep);
			free(tmp);
			tmp = str;
			str = ft_strjoin(str, strs[i++]);
			free(tmp);
		}
	}
	return (str);
}
