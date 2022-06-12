/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:46:52 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/12 17:52:59 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_coins(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				mlx->coin_num += 1;
			j++;
		}
		i++;
	}
}

void	initilizer_zero(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

int	paint_result(t_mlx *mlx)
{
	allocate_component(mlx->imgs.zero, 0, mlx, '0');
	if (mlx->win)
		mlx_string_put(mlx->mlx, mlx->mlx_win,
			(mlx->win_width * mlx->img_width) / 2 - (mlx->imgs.width_zero / 2),
			(mlx->win_height * mlx->img_height) / 2, 0x0000FF00, "You won!");
	else
		mlx_string_put(mlx->mlx, mlx->mlx_win,
			(mlx->win_width * mlx->img_width) / 2 - (mlx->imgs.width_zero / 2),
			(mlx->win_height * mlx->img_height) / 2, 0x00FF0000, "You lost!");
	return (1);
}
