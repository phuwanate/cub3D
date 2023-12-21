/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:01:24 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/15 18:01:25 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_main.h"

static void	player_move_forward(t_data *data)
{
	int	y;
	int	x;

	y = (int)data->var.position_y;
	x = (int)(data->var.position_x + data->var.dir_x
			* data->var.move_speed);
	if (data->map[y][x] != '1')
		data->var.position_x += data->var.dir_x * data->var.move_speed;
	y = (int)(data->var.position_y + data->var.dir_y * data->var.move_speed);
	x = (int)data->var.position_x;
	if (data->map[y][x] != '1')
		data->var.position_y += data->var.dir_y * data->var.move_speed;
}

static void	player_move_backwards(t_data *data)
{
	int	y;
	int	x;

	y = (int)data->var.position_y;
	x = (int)(data->var.position_x - data->var.dir_x * data->var.move_speed);
	if (data->map[y][x] != '1')
		data->var.position_x -= data->var.dir_x * data->var.move_speed;
	y = (int)(data->var.position_y - data->var.dir_y
			* data->var.move_speed);
	x = (int)data->var.position_x;
	if (data->map[y][x] != '1')
		data->var.position_y -= data->var.dir_y * data->var.move_speed;
}

static void	player_move_left(t_data *data)
{
	int	y;
	int	x;

	y = (int)data->var.position_y;
	x = (int)(data->var.position_x + data->var.dir_y * data->var.move_speed);
	if (data->map[y][x] != '1')
		data->var.position_x += data->var.dir_y * data->var.move_speed;
	y = (int)(data->var.position_y - data->var.dir_x * data->var.move_speed);
	x = (int)data->var.position_x;
	if (data->map[y][x] != '1')
		data->var.position_y -= data->var.dir_x * data->var.move_speed;
}

static void	player_move_right(t_data *data)
{
	int	y;
	int	x;

	y = (int)data->var.position_y;
	x = (int)(data->var.position_x - data->var.dir_y * data->var.move_speed);
	if (data->map[y][x] != '1')
		data->var.position_x -= data->var.dir_y * data->var.move_speed;
	y = (int)(data->var.position_y + data->var.dir_x * data->var.move_speed);
	x = (int)data->var.position_x;
	if (data->map[y][x] != '1')
		data->var.position_y += data->var.dir_x * data->var.move_speed;
}

void	movement(t_data *data)
{
	if (data->key.w == KEY_IS_PRESSED)
		player_move_forward(data);
	if (data->key.s == KEY_IS_PRESSED)
		player_move_backwards(data);
	if (data->key.a == KEY_IS_PRESSED)
		player_move_left(data);
	if (data->key.d == KEY_IS_PRESSED)
		player_move_right(data);
	if (data->key.left == KEY_IS_PRESSED)
		player_rotate_left(data);
	if (data->key.right == KEY_IS_PRESSED)
		player_rotate_right(data);
}
