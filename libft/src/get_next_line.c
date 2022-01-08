/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlesdansembourg <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:36:36 by charlesda         #+#    #+#             */
/*   Updated: 2021/05/14 19:36:37 by charlesda        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_free(char **string, int nb)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
	return (nb);
}

char	*ft_strchr(const char *str, int c)
{
	int			i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i] + 1);
		i++;
	}
	if (c == 0)
		return ((char *)&str[i] + 1);
	return (NULL);
}

char	*ft_strndup(const char *str, const char c)
{
	int			i;
	int			j;
	char		*src;

	i = 0;
	j = 0;
	if (str == NULL)
		return (ft_strndup("", '\0'));
	while (str[j] != c)
		j++;
	src = malloc((j + 1) * sizeof(*src));
	if (src == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
	{
		src[i] = str[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

int	ft_read(int fd, char **line, char *rest, int ret)
{
	char		buf[50 + 1];

	if (rest != NULL)
	{
		*line = ft_strndup(rest, '\0');
		if (*line == NULL)
			return (ft_free(&rest, -1));
	}
	if (rest == NULL)
	{
		*line = ft_strndup("", '\0');
		if (*line == NULL)
			return (ft_free(line, -1));
	}
	while ((ft_strchr(*line, '\n') == NULL)
		&& (ret = read(fd, buf, 50)) > 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin_free_first(*line, buf);
		if (*line == NULL)
			return (ft_free(&rest, -1));
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*rest = NULL;
	char		*tmp;

	if (fd < 0 || 50 <= 0 || line == NULL)
		return (-1);
	ret = ft_read(fd, line, rest, 0);
	if (ret == -1)
		return (ft_free(&rest, -1));
	if (rest != NULL)
		ft_free(&rest, 1);
	rest = ft_strndup(ft_strchr(*line, '\n'), '\0');
	if (rest == NULL)
		return (ft_free(&rest, -1));
	if (ft_strchr(*line, '\n') == NULL)
		return (ft_free(&rest, 0));
	tmp = *line;
	*line = ft_strndup(*line, '\n');
	if (*line == NULL)
		return (ft_free(&rest, -1));
	free(tmp);
	tmp = NULL;
	return (1);
}
