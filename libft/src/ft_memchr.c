/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlesdansembourg <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:31:52 by charlesda         #+#    #+#             */
/*   Updated: 2021/05/14 19:31:54 by charlesda        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*source;

	source = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
			return (&source[i]);
		i++;
	}
	return (NULL);
}
