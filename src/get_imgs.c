/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:41:36 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/31 20:20:50 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img *get_imgs(t_mlx *mlx, t_img *imgs)
{
	int		a;

	imgs->zero = mlx_xpm_file_to_image(mlx->mlx, ZERO_IMG, &mlx->img_width, &mlx->img_height);
	imgs->obstacle = mlx_xpm_file_to_image(mlx->mlx, OBSTACLE_IMG, &a, &a);
	imgs->player = mlx_xpm_file_to_image(mlx->mlx, PLAYER_IMG, &a, &a);
	imgs->coin = mlx_xpm_file_to_image(mlx->mlx, COIN_IMG, &a, &a);
	imgs->exit = mlx_xpm_file_to_image(mlx->mlx, EXIT_IMG, &a, &a);
	imgs->enemy = mlx_xpm_file_to_image(mlx->mlx, ENEMY, &a, &a);
	return (0);
}