/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlesdansembourg <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:35:36 by charlesda         #+#    #+#             */
/*   Updated: 2021/05/14 19:35:38 by charlesda        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*last;
	int		i;

	str = (char *)s;
	last = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			last = &str[i];
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (last);
}
