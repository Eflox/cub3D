/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:30:59 by chde-mar          #+#    #+#             */
/*   Updated: 2021/05/14 19:48:04 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*create_new_line(char *str, int diff)
{
	int		i;
	char	*new;
	int		len;

	len = ft_strlen(str);
	i = 0;
	new = malloc(sizeof(char *) * (len + diff + 1));
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	while (diff > 0)
	{
		new[i] = ' ';
		i++;
		diff--;
	}
	new[i] = '\0';
	return (new);
}

int	create_good_size_map(t_index *m)
{
	int	i;
	int	len;
	int	diff;

	i = 0;
	diff = 0;
	len = ft_strlen(m->parse.map[i]);
	while (m->parse.map[i] != NULL)
	{
		if ((int)ft_strlen(m->parse.map[i]) > len)
			len = ft_strlen(m->parse.map[i]);
		i++;
	}
	i = -1;
	while (m->parse.map[++i] != NULL)
	{
		if ((int)ft_strlen(m->parse.map[i]) < len)
		{
			diff = len - ft_strlen(m->parse.map[i]);
			m->parse.map[i] = create_new_line(m->parse.map[i], diff);
			if (!m->parse.map[i])
				return (-1);
		}
	}
	return (1);
}

int	get_position2(t_index *m, int i, int j)
{
	if ((ft_isalpha(m->parse.map[i][j])))
	{
		m->parse.pos_x_init = j + 0.5;
		m->parse.pos_y_init = i + 0.5;
		if (m->parse.dir == 0)
			m->parse.dir = m->parse.map[i][j];
		else
			return (return_error(m));
		m->parse.map[i][j] = '0';
	}
	if (m->parse.map[i][j] == '2')
		m->spr.numsprites += 1;
	return (1);
}

int	get_position(t_index *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->parse.map[i] != NULL)
	{
		j = 0;
		while (m->parse.map[i][j] != '\0')
		{
			get_position2(m, i, j);
			j++;
		}
		i++;
	}
	m->parse.line_nbr = i;
	m->parse.column_nbr = j;
	return (1);
}

int	create_map(t_index *m)
{
	m->parse.map = ft_split(m->parse.map_string, '\n');
	if (!m->parse.map)
		return (-1);
	if (get_position(m) < 0)
		return (-1);
	if (check_borders_lines(m) < 0)
		return (-1);
	if (check_borders_columns(m) < 0)
		return (-1);
	return (1);
}
