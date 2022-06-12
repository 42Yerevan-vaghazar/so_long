/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:45:29 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/12 17:41:24 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	helper_allocate_component(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] == '2' && !mlx->win && !mlx->lose)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->imgs.zero,
			x * mlx->img_width, y * mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->imgs.exit,
			x * mlx->img_width + mlx->imgs.centre_exit,
			y * mlx->img_height + mlx->imgs.centre_exit);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->imgs.player,
			x * mlx->img_width + mlx->imgs.centre_player,
			y * mlx->img_height + mlx->imgs.centre_player);
	}
}

int	allocate_component(void *img, int a, t_mlx *mlx, char component)
{
	mlx->x = -1;
	mlx->y = -1;
	while (mlx->map[++mlx->y])
	{
		while (mlx->map[mlx->y][++mlx->x])
		{
			if (mlx->map[mlx->y][mlx->x] == 'P'
				|| mlx->map[mlx->y][mlx->x] == '2')
			{
				mlx->player.x = mlx->x;
				mlx->player.y = mlx->y;
			}
			if (mlx->map[mlx->y][mlx->x] == component || component == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
					img, mlx->x * mlx->img_width + a,
					mlx->y * mlx->img_height + a);
			helper_allocate_component(mlx, mlx->x, mlx->y);
		}
		mlx->x = -1;
	}
	return (0);
}

static void	helper_fill_window(t_mlx *mlx)
{
	allocate_component(mlx->imgs.zero,
		(mlx->img_width - mlx->imgs.width_zero) / 2, mlx, '0');
	allocate_component(mlx->imgs.obstacle,
		mlx->imgs.centre_obstacle, mlx, '1');
	allocate_component(mlx->imgs.player,
		mlx->imgs.centre_player, mlx, 'P');
	allocate_component(mlx->imgs.coin,
		mlx->imgs.centre_coin, mlx, 'C');
	allocate_component(mlx->imgs.exit,
		mlx->imgs.centre_exit, mlx, 'E');
	allocate_component(mlx->imgs.enemy,
		mlx->imgs.centre_enemy, mlx, 'e');
}

int	fill_window(t_mlx *mlx)
{
	mlx->win_height = 0;
	mlx->win_width = ft_strlen(*(mlx)->map);
	while (mlx->map[mlx->win_height] && mlx->map[mlx->win_height][0])
		mlx->win_height++;
	if (!mlx->mlx_win)
		mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->win_width * mlx->img_width,
				mlx->win_height * mlx->img_height, "so_long");
	helper_fill_window(mlx);
	if (!mlx->win && !mlx->lose)
		ft_paint_steps(mlx);
	return (1);
}

int	ft_paint_swaps(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		mlx->imgs.zero, x * mlx->img_width,
		y * mlx->img_height);
	if (mlx->map[y][x] == 'P' && !mlx->lose)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->imgs.player, (x * mlx->imgs.width_zero)
			+ mlx->imgs.centre_player,
			(y * mlx->imgs.height_zero) + mlx->imgs.centre_player);
	}
	else if (mlx->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->imgs.exit, (x * mlx->imgs.width_zero)
			+ mlx->imgs.centre_player,
			(y * mlx->imgs.height_zero) + mlx->imgs.centre_player);
	helper_allocate_component(mlx, x, y);
	if (!mlx->lose && !mlx->win)
		ft_paint_steps(mlx);
	return (0);
}
