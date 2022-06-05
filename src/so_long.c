/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:38:14 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/05 13:14:11 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	imgs;
	int		i;

	i = 0;
	mlx.mlx_win = 0;
	mlx.player.step = 0;
	mlx.map = get_map(av[1]);
	count_coins(&mlx);
	mlx.mlx = mlx_init();
	get_imgs(&mlx, &mlx.imgs);
	fill_window(&mlx, &mlx.imgs);
	mlx_hook(mlx.mlx_win, 17, 1L << 17, ft_close, &mlx);
	mlx_hook(mlx.mlx_win, 3, 1L << 1, ft_press, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
