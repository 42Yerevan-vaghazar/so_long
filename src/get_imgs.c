/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:41:36 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/05 17:58:51 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*get_imgs(t_mlx *mlx, t_img *imgs)
{
	mlx->imgs.zero = mlx_xpm_file_to_image(mlx->mlx, ZERO_IMG,
			&mlx->imgs.width_zero, &mlx->imgs.height_zero);
	mlx->img_height = mlx->imgs.height_zero;
	mlx->img_width = mlx->imgs.height_zero;
	mlx->imgs.obstacle = mlx_xpm_file_to_image(mlx->mlx, OBSTACLE_IMG,
			&mlx->imgs.width_obstacle, &mlx->imgs.height_obstacle);
	mlx->imgs.player = mlx_xpm_file_to_image(mlx->mlx, PLAYER_IMG,
			&mlx->imgs.width_player, &mlx->imgs.height_obstacle);
	mlx->imgs.coin = mlx_xpm_file_to_image(mlx->mlx, COIN_IMG,
			&mlx->imgs.width_coin, &mlx->imgs.height_coin);
	mlx->imgs.exit = mlx_xpm_file_to_image(mlx->mlx, EXIT_IMG,
			&mlx->imgs.width_exit, &mlx->imgs.height_exit);
	mlx->imgs.enemy = mlx_xpm_file_to_image(mlx->mlx, ENEMY,
			&mlx->imgs.width_enemy, &mlx->imgs.height_enemy);
	return (0);
}
