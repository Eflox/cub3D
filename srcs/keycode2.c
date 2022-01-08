/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:28:31 by chde-mar          #+#    #+#             */
/*   Updated: 2021/04/06 00:29:25 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_key_states(int keycode, t_index *m)
{
	if (keycode == MLXK_A)
		m->el.left = 1;
	else if (keycode == MLXK_D)
		m->el.right = 1;
	else if (keycode == MLXK_W)
		m->el.forward = 1;
	else if (keycode == MLXK_S)
		m->el.backward = 1;
	else if (keycode == MLXK_LEFT)
		m->el.turn_left = 1;
	else if (keycode == MLXK_RIGHT)
		m->el.turn_right = 1;
	ft_key(keycode, m);
	return (0);
}

int	ft_key_off(int keycode, t_index *m)
{
	if (keycode == MLXK_A)
		m->el.left = 0;
	else if (keycode == MLXK_D)
		m->el.right = 0;
	else if (keycode == MLXK_W)
		m->el.forward = 0;
	else if (keycode == MLXK_S)
		m->el.backward = 0;
	else if (keycode == MLXK_LEFT)
		m->el.turn_left = 0;
	else if (keycode == MLXK_RIGHT)
		m->el.turn_right = 0;
	ft_key(keycode, m);
	return (0);
}
