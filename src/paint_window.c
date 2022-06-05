/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:45:29 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/05 19:20:56 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	helper_allocate_component(t_mlx *mlx, int a)
{
	if (mlx->map[mlx->y][mlx->x] == '2' && !mlx->win && !mlx->lose)
	{	
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->imgs.zero,
			mlx->x * mlx->img_width, mlx->y * mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->imgs.exit,
			mlx->x * mlx->img_width + a, mlx->y * mlx->img_height + a);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->imgs.player,
			mlx->x * mlx->img_width + a, mlx->y * mlx->img_height + a);
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
			helper_allocate_component(mlx, a);
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
		(mlx->img_width - mlx->imgs.width_obstacle) / 2, mlx, '1');
	allocate_component(mlx->imgs.player,
		(mlx->img_width - mlx->imgs.width_player) / 2, mlx, 'P');
	allocate_component(mlx->imgs.coin,
		(mlx->img_width - mlx->imgs.width_coin) / 2, mlx, 'C');
	allocate_component(mlx->imgs.exit,
		(mlx->img_width - mlx->imgs.width_exit) / 2, mlx, 'E');
	allocate_component(mlx->imgs.enemy,
		(mlx->img_width - mlx->imgs.width_enemy) / 2, mlx, 'e');
}

int	fill_window(t_mlx *mlx)
{
	int		a;
	size_t	win_width;
	size_t	win_height;

	win_height = 0;
	win_width = ft_strlen(*(mlx)->map);
	while (mlx->map[win_height] && mlx->map[win_height][0])
		win_height++;
	if (!mlx->mlx_win)
		mlx->mlx_win = mlx_new_window(mlx->mlx, win_width * mlx->img_width,
				win_height * mlx->img_height, "so_long");
	helper_fill_window(mlx);
	return (1);
}

int	ft_swap_components(t_mlx *mlx, char *current_place, char *place_to_go)
{
	if (*place_to_go == 'C')
		mlx->coin_num -= 1;
	if (*place_to_go == 'e' && ++mlx->lose)
		mlx->lose = 1;
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
		&& ft_printf("%d\n", mlx->player.step))
	{	
		*place_to_go = '2';
		*current_place = '0';
	}
	return (1);
}
