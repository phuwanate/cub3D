/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:36:59 by plertsir          #+#    #+#             */
/*   Updated: 2023/11/23 16:21:05 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	//dst pointed to data_addr which is pointed to image
	//data->addr + arr_index in screen.
	dst = data->addr + ((y * data->line_len) + (x * (data->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

void draw_rectangle(t_data *img, int x1, int y1, int x2, int y2, int color) 
{
    int i;
    // Draw the top and bottom lines of the rectangle
    for (i = x1; i <= x2; i++) {
        my_mlx_pixel_put(img, i, y1, color);
        my_mlx_pixel_put(img, i, y2, color);
    }

    // Draw the left and right lines of the rectangle
    for (i = y1; i <= y2; i++) {
        my_mlx_pixel_put(img, x1, i, color);
        my_mlx_pixel_put(img, x2, i, color);
    }
}

void get_background(t_data *data)
{
	int	*bg;
	int	i;

	i = 0;
	ft_bzero(data->addr, 1920 * 1080 * (data->bits_per_pixel / 8));
	bg = (int *)(data->addr);
	while (i < 1920 * 1080)
	{
		bg[i] = 0x00000000;
		i++;
	}
}

int close_win(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	else if (keycode == 13)
	{
		data->y -= 100;
		mlx_clear_window(data->mlx, data->mlx_win);
		get_background(data);
		draw_rectangle(data, data->x/2, data->y/2, (data->x/2)+50, (data->y/2)+50, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	else if (keycode == 1)
	{
		data->y += 100;
		mlx_clear_window(data->mlx, data->mlx_win);
		get_background(data);
		draw_rectangle(data, data->x/2, data->y/2, (data->x/2)+50, (data->y/2)+50, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	else if (keycode == 0)
	{
		data->x -= 100;
		mlx_clear_window(data->mlx, data->mlx_win);
		get_background(data);
		draw_rectangle(data, data->x/2, data->y/2, (data->x/2)+50, (data->y/2)+50, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
		else if (keycode == 2)
	{
		data->x += 100;
		mlx_clear_window(data->mlx, data->mlx_win);
		get_background(data);
		draw_rectangle(data, data->x/2, data->y/2, (data->x/2)+50, (data->y/2)+50, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	else
		printf("%d\n", keycode);
	return (0);
}

int	main()
{
	t_data	img;

	img.x = 1920;
	img.y = 1080;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	//img.addr pointed to the address's index on the screen
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	draw_rectangle(&img, img.x/2, img.y/2, (img.x/2)+50, (img.y/2)+50, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 0, close_win, &img);
	mlx_loop(img.mlx);
}