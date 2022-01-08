/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:30:46 by chde-mar          #+#    #+#             */
/*   Updated: 2021/04/06 00:09:01 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_east_texture(t_index *m)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (m->el.elem[m->el.east_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (m->el.elem[m->el.east_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	m->el.e_path = malloc(sizeof(char) * count + 1);
	if (!m->el.e_path)
		return (NULL);
	while (m->el.elem[m->el.east_line][i] != '\0')
	{
		m->el.e_path[j] = m->el.elem[m->el.east_line][i];
		i++;
		j++;
	}
	m->el.e_path[j] = '\0';
	return ("");
}

char	*get_west_texture(t_index *m)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (m->el.elem[m->el.west_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (m->el.elem[m->el.west_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	m->el.w_path = malloc(sizeof(char) * count + 1);
	if (!m->el.w_path)
		return (NULL);
	while (m->el.elem[m->el.west_line][i] != '\0')
	{
		m->el.w_path[j] = m->el.elem[m->el.west_line][i];
		i++;
		j++;
	}
	m->el.w_path[j] = '\0';
	return ("");
}

char	*get_south_texture(t_index *m)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (m->el.elem[m->el.south_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (m->el.elem[m->el.south_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	m->el.s_path = malloc(sizeof(char) * count + 1);
	if (!m->el.s_path)
		return (NULL);
	while (m->el.elem[m->el.south_line][i] != '\0')
	{
		m->el.s_path[j] = m->el.elem[m->el.south_line][i];
		i++;
		j++;
	}
	m->el.s_path[j] = '\0';
	return ("");
}

char	*get_north_texture(t_index *m)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (m->el.elem[m->el.north_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (m->el.elem[m->el.north_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	m->el.n_path = malloc(sizeof(char) * count + 1);
	if (!m->el.n_path)
		return (NULL);
	while (m->el.elem[m->el.north_line][i] != '\0')
	{
		m->el.n_path[j] = m->el.elem[m->el.north_line][i];
		i++;
		j++;
	}
	m->el.n_path[j] = '\0';
	return ("");
}

char	*get_sprite_texture(t_index *m)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (m->el.elem[m->el.sprite_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (m->el.elem[m->el.sprite_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	m->el.spr_path = malloc(sizeof(char) * count + 1);
	if (!m->el.spr_path)
		return (NULL);
	while (m->el.elem[m->el.sprite_line][i] != '\0')
	{
		m->el.spr_path[j] = m->el.elem[m->el.sprite_line][i];
		i++;
		j++;
	}
	m->el.spr_path[j] = '\0';
	return ("");
}
