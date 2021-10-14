/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:15:40 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/11 15:16:20 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numc(char const *s, char c)
{
	int	t;
	int	i;

	i = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			t++;
		i++;
	}
	return (t);
}

void	*ft_clean(char **arr, size_t n)
{
	while (n--)
		free(arr[n]);
	free(arr);
	return (NULL);
}

char	*ft_osnova(char const **s, char c)
{
	char	*a;
	size_t	i;

	i = 0;
	while ((*s)[i] != c && (*s)[i])
		i++;
	a = ft_substr(*s, 0, i);
	if (!a)
		return (NULL);
	*s += i;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (numc(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			arr[i] = ft_osnova(&s, c);
			if (arr[i] == NULL)
				return (ft_clean(arr, i));
			i++;
		}
	}
	arr[i] = NULL;
	if (!arr)
		return (NULL);
	return (arr);
}
