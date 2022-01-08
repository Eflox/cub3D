/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:29:06 by chde-mar          #+#    #+#             */
/*   Updated: 2021/04/06 00:57:48 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	write_sprites(t_index *m)
{
	int	y;
	int	d;

	d = 0;
	y = m->spr.drawstarty;
	while (y < m->spr.drawendy)
	{
		d = (y - m->spr.vmovescreen) * 256 - m->el.res_y * 128
			+ m->spr.sprheight * 128;
		m->spr.texy = ((d * 64) / m->spr.sprheight) / 256;
		if ((m->spr.color[64 * m->spr.texy + m->spr.texx] & 0x00FFFFFF) != 0)
			m->img.addr[y * m->el.res_x + m->spr.stripe]
				= m->spr.color[64 * m->spr.texy + m->spr.texx];
		y++;
	}
}

void	verline_sprites(t_index *m)
{
	m->spr.stripe = m->spr.drawstartx;
	while (m->spr.stripe < m->spr.drawendx)
	{
		m->spr.texx = (int)((m->spr.stripe - (-m->spr.sprwidth / 2
						+ m->spr.spritescreenx)) * 64 / m->spr.sprwidth);
		if (m->spr.transformy > 0 && m->spr.stripe > 0 && m->spr.stripe
			< m->el.res_x && m->spr.transformy < m->spr.zbuffer[m->spr.stripe]
			&& m->spr.texx < 64)
		{
			write_sprites(m);
		}
		m->spr.stripe++;
	}
}
