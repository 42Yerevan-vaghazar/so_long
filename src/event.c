/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:48:46 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/05 19:39:59 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	static	check_key(int key, size_t *count_step)
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
	if (!check_key(key, &mlx->player.step) || mlx->win || mlx->lose)
		return (0);
	if (key == KEY_ESC || key == KEY_Q)
		exit(1);
	if (key == KEY_W || key == KEY_ARROW_UP)
		ft_swap_components(mlx, &mlx->map[mlx->player.y][mlx->player.x],
			&mlx->map[mlx->player.y - 1][mlx->player.x]);
	if (key == KEY_S || key == KEY_ARROW_DOWN)
		ft_swap_components(mlx, &mlx->map[mlx->player.y][mlx->player.x],
			&mlx->map[mlx->player.y + 1][mlx->player.x]);
	if (key == KEY_A || key == KEY_ARROW_LEFT)
		ft_swap_components(mlx, &mlx->map[mlx->player.y][mlx->player.x],
			&mlx->map[mlx->player.y][mlx->player.x - 1]);
	if (key == KEY_D || key == KEY_ARROW_RIGHT)
		ft_swap_components(mlx, &mlx->map[mlx->player.y][mlx->player.x],
			&mlx->map[mlx->player.y][mlx->player.x + 1]);
	fill_window(mlx);
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
