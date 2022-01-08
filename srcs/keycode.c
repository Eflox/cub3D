/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:28:31 by chde-mar          #+#    #+#             */
/*   Updated: 2021/04/06 00:28:58 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keys_up_down(t_index *m)
{
	if (m->el.forward == 1 && m->el.left == 0 && m->el.right == 0)
	{
		if (m->parse.map[(int)m->big.posy][(int)(m->big.posx
			+ m->big.dirx * (m->big.movespeed + 0.1))] != '1')
			m->big.posx += m->big.dirx * m->big.movespeed;
		if (m->parse.map[(int)(m->big.posy + m->big.diry
				* (m->big.movespeed + 0.1))][(int)m->big.posx] != '1')
			m->big.posy += m->big.diry * m->big.movespeed;
	}
	if (m->el.backward == 1 && m->el.left == 0 && m->el.right == 0)
	{
		if (m->parse.map[(int)m->big.posy][(int)(m->big.posx
			- m->big.dirx * (m->big.movespeed * 0.1))] != '1')
			m->big.posx -= m->big.dirx * m->big.movespeed;
		if (m->parse.map[(int)(m->big.posy - m->big.diry
				* (m->big.movespeed * 0.1))][(int)m->big.posx] != '1')
			m->big.posy -= m->big.diry * m->big.movespeed;
	}
	return (1);
}

int	keys_rot1(t_index *m)
{
	if (m->el.turn_right == 1)
	{
		m->big.olddirx = m->big.dirx;
		m->big.dirx = m->big.dirx * cos(m->big.rotspeed)
			- m->big.diry * sin(m->big.rotspeed);
		m->big.diry = m->big.olddirx * sin(m->big.rotspeed)
			+ m->big.diry * cos(m->big.rotspeed);
		m->big.oldplanex = m->big.planex;
		m->big.planex = m->big.planex * cos(m->big.rotspeed)
			- m->big.planey * sin(m->big.rotspeed);
		m->big.planey = m->big.oldplanex * sin(m->big.rotspeed)
			+ m->big.planey * cos(m->big.rotspeed);
	}
	return (1);
}

int	keys_rot2(t_index *m)
{
	if (m->el.turn_left == 1)
	{
		m->big.olddirx = m->big.dirx;
		m->big.dirx = m->big.dirx * cos(-m->big.rotspeed)
			- m->big.diry * sin(-m->big.rotspeed);
		m->big.diry = m->big.olddirx * sin(-m->big.rotspeed)
			+ m->big.diry * cos(-m->big.rotspeed);
		m->big.oldplanex = m->big.planex;
		m->big.planex = m->big.planex * cos(-m->big.rotspeed)
			- m->big.planey * sin(-m->big.rotspeed);
		m->big.planey = m->big.oldplanex * sin(-m->big.rotspeed)
			+ m->big.planey * cos(-m->big.rotspeed);
	}
	return (1);
}

int	keys_right_left(t_index *m)
{
	if (m->el.left == 1)
	{
		if (m->parse.map[(int)(m->big.posy - m->big.dirx
				* (m->big.movespeed / 2 + 0.1))][(int)m->big.posx] != '1')
			m->big.posy -= m->big.dirx * m->big.movespeed / 2;
		if (m->parse.map[(int)m->big.posy][(int)(m->big.posx
			+ m->big.diry * (m->big.movespeed / 2 + 0.1))] != '1')
			m->big.posx += m->big.diry * m->big.movespeed / 2;
	}
	if (m->el.right == 1)
	{
		if (m->parse.map[(int)(m->big.posy + m->big.dirx
				* (m->big.movespeed / 2 * 0.1))][(int)m->big.posx] != '1')
			m->big.posy += m->big.dirx * m->big.movespeed / 2;
		if (m->parse.map[(int)m->big.posy][(int)(m->big.posx
			- m->big.diry * (m->big.movespeed / 2 + 0.1))] != '1')
			m->big.posx -= m->big.diry * m->big.movespeed / 2;
	}
	return (1);
}

int	ft_key(int keycode, t_index *m)
{
	m->big.oldplanex = m->big.planex;
	if (keycode == MLXK_ESC || keycode == MLXK_X)
		exit_all(m);
	keys_up_down(m);
	keys_rot1(m);
	keys_rot2(m);
	keys_right_left(m);
	mlx_clear_window(m->win.mlx_ptr, m->win.mlx_win);
	create_algo(m);
	return (0);
}
