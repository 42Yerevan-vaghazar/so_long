/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:45:29 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/05 16:05:34 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	helper_allocate_component(t_mlx *mlx, t_img *imgs)
{
	if (mlx->map[mlx->y][mlx->x] == '2')
	{	
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, imgs->zero,
			mlx->x * mlx->img_width, mlx->y * mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, imgs->exit,
			mlx->x * mlx->img_width, mlx->y * mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, imgs->player,
			mlx->x * mlx->img_width, mlx->y * mlx->img_height);
	}
}

int	allocate_component(void *img, t_img *imgs, t_mlx *mlx, char component)
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
					img, mlx->x * mlx->img_width, mlx->y * mlx->img_height);
			helper_allocate_component(mlx, imgs);
		}
		mlx->x = -1;
	}
	return (0);
}

int	fill_window(t_mlx *mlx, t_img *imgs)
{
	int		a;

	mlx->win_height = 0;
	mlx->win_width = ft_strlen(*(mlx)->map);
	while (mlx->map[mlx->win_height] && mlx->map[mlx->win_height][0])
		mlx->win_height++;
	if (!mlx->mlx_win)
		mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->win_width * mlx->img_width,
				mlx->win_height * mlx->img_height, "so_long");
	allocate_component(imgs->zero, imgs, mlx, '0');
	allocate_component(imgs->obstacle, imgs, mlx, '1');
	allocate_component(imgs->player, imgs, mlx, 'P');
	allocate_component(imgs->coin, imgs, mlx, 'C');
	allocate_component(imgs->exit, imgs, mlx, 'E');
	allocate_component(imgs->enemy, imgs, mlx, 'e');
	return (1);
}

int	ft_swap_components(t_mlx *mlx, char *current_place, char *place_to_go)
{
	if (*place_to_go == 'C')
		mlx->coin_num -= 1;
	if (*place_to_go == 'e')
		exit(1);
	if ((*place_to_go == '0'
			|| *place_to_go == 'C') && ++mlx->player.step
		&& ft_printf("%d\n", mlx->player.step))
	{
		if (*current_place == '2')
			*current_place = 'E';
		else
			*current_place = '0';
		*place_to_go = 'P';
	}
	if (*place_to_go == 'E' && ++mlx->player.step
		&& mlx_string_put(mlx->mlx, mlx->mlx_win, 30, mlx->win_height, 800000, "barev"))
	{	
		*place_to_go = '2';
		*current_place = '0';
	}
	return (1);
}
