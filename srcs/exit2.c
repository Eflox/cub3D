/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:28:07 by chde-mar          #+#    #+#             */
/*   Updated: 2021/04/06 00:18:35 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_spr(t_index *m)
{
	if (m->spr.zbuffer)
	{
		free(m->spr.zbuffer);
		m->spr.zbuffer = 0;
	}
	if (m->spr.sprites_x)
	{
		free(m->spr.sprites_x);
		m->spr.sprites_x = 0;
	}
	if (m->spr.sprites_y)
	{
		free(m->spr.sprites_y);
		m->spr.sprites_y = 0;
	}
}

void	free_tex(t_index *m)
{
	if (m->tex.color_n)
	{
		free(m->tex.color_n);
		m->tex.color_n = 0;
	}
	if (m->tex.color_s)
	{
		free(m->tex.color_s);
		m->tex.color_s = 0;
	}
	if (m->tex.color_e)
	{
		free(m->tex.color_e);
		m->tex.color_e = 0;
	}
	if (m->tex.color_w)
	{
		free(m->tex.color_w);
		m->tex.color_w = 0;
	}
}
