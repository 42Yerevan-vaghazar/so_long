/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:48:46 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/19 09:44:06 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	static	check_key(int key)
{
	if (key == KEY_W || key == KEY_ARROW_UP || key == KEY_S \
		|| key == KEY_ARROW_DOWN || key == KEY_A || key == KEY_ARROW_LEFT \
		|| key == KEY_D || key == KEY_ARROW_RIGHT \
		|| key == KEY_ESC || key == KEY_Q)
		return (1);
	return (0);
}

int	ft_press(int key, t_mlx *mlx)
{
	char	*c_place;

	c_place = &mlx->map[mlx->player.y][mlx->player.x];
	mlx->p_x = mlx->player.x;
	mlx->p_y = mlx->player.y;
	if (key == KEY_ESC || key == KEY_Q)
		exit(1);
	if (!check_key(key) || mlx->win || mlx->lose)
		return (0);
	if (key == KEY_W || key == KEY_ARROW_UP)
		mlx->player.y = mlx->player.y - 1;
	if (key == KEY_S || key == KEY_ARROW_DOWN)
		mlx->player.y = mlx->player.y + 1;
	if (key == KEY_A || key == KEY_ARROW_LEFT)
		mlx->player.x = mlx->player.x - 1;
	if (key == KEY_D || key == KEY_ARROW_RIGHT)
		mlx->player.x = mlx->player.x + 1;
	ft_swap_components(mlx, c_place, &mlx->map[mlx->player.y][mlx->player.x]);
	ft_paint_swaps(mlx, mlx->p_x, mlx->p_y);
	ft_paint_swaps(mlx, mlx->player.x, mlx->player.y);
	if ((mlx->map[mlx->player.y][mlx->player.x] == '2'
		&& mlx->coin_num == 0) && ++mlx->win)
		paint_result(mlx);
	return (1);
}

int	ft_close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->imgs.zero);
	mlx_destroy_image(mlx->mlx, mlx->imgs.coin);
	mlx_destroy_image(mlx->mlx, mlx->imgs.enemy);
	mlx_destroy_image(mlx->mlx, mlx->imgs.exit);
	mlx_destroy_image(mlx->mlx, mlx->imgs.obstacle);
	mlx_destroy_image(mlx->mlx, mlx->imgs.player);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (0);
}
