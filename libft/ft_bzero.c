/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:41:50 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/11 12:10:19 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	size_t			nul;
	unsigned char	*s;

	s = dest;
	nul = 0;
	while (n > nul)
	{
		s[nul] = 0;
		nul++;
	}	
}
