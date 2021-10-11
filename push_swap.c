/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:49:26 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/11 15:22:59 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		++i;
	}
	if (i < dstsize)
		*dst = 0;
	while (*src++)
		++i;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dst && i < dstsize)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, dstsize - i);
	return (ret + i);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, len + 1);
	return (ret);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(len);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, len);
	ft_strlcat(ret, s2, len);
	return (ret);
}


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

char	*ft_substr(const char *s,int start, int len)
{
	char	*ret;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

static size_t	ft_toklen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			++len;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_toklen(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (ret > INT_MAX)
			return (-1);
		else if (ret < INT_MIN)
			return (0);
	}
	return ((int)ret);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (sign < 0 && ret > 0)
			return (LONG_MIN);
		else if (sign > 0 && ret < 0)
			return (LONG_MAX);
	}
	return (ret);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (0);
	return (1);
}

static int	ft_hasdup(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
			if (nums[i] == nums[j++])
				return (1);
		++i;
	}
	return (0);
}

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

void	cleanup_1(char *str, char **strs)
{
	int	i;

	i = 0;
	free(str);
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int is_sorted(int *nums)
{
	int i;

	i = 0;
	while (nums[i+1])
	{
		if (nums[i] <= nums[i+1])
		{
			printf("nums [i] in sort %d \n", nums[i]);
			i++;
		}
		else
		{
			printf("NOT SORTED");
			return(1);
		}
	}
	printf("SORTED");
	return(0);
}

int main(int argc, char **argv)
{
	char 	*str;
	char	**strs;
	int 	*nums;
	int 	len;
	t_list	*stack;

	int i = 0; // counter

	if (argc > 1)
	{
		nums = 0;
		stack = 0;

		str = ft_join(argv + 1, " "); // argv + 1 берём только переданные аргументы (без ./a.out)
		printf("str : %s\n", str);	
		strs = ft_split(str, ' '); // разделяем str по пробелам
		while (strs[i]) // del from here ...
		{
			printf("strs [%d] : %s\n", i, strs[i]); 
			i++;
		}
		i = 0; //.. to here
		len = convert(strs, &nums); // переводим массив строк в массив чисел
		printf("len : %d \n", len);
		while (i < len) // del from here ...
		{
			printf("nums [%d] :%d\n", i, nums[i]);
			i++;
		}
		i = 0; //.. to here
		cleanup_1(str, strs); // free str, strs
		is_sorted(nums);
	}
}
