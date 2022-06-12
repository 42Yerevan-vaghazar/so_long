/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:41:37 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/12 17:42:14 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_paint_steps(t_mlx *mlx)
{
	int		x;
	char	*steps;

	x = 0;
	while (x < mlx->win_width)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->imgs.zero, x * mlx->img_width, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->imgs.obstacle, x * mlx->img_width + mlx->imgs.centre_obstacle,
			mlx->imgs.centre_obstacle);
		x++;
	}
	steps = ft_itoa(mlx->player.step);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 15,
		35, 0x00FF0000, "steps  ");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 120,
		35, 0x00FF0000, steps);
	return (0);
}
