/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:37:26 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/12 17:35:39 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_swap_components(t_mlx *mlx, char *c_place, char *place_to_go)
{
	if (*place_to_go == '1')
	{
		mlx->player.x = mlx->p_x;
		mlx->player.y = mlx->p_y;
	}
	if (*place_to_go == 'C')
		mlx->coin_num -= 1;
	if (*place_to_go == 'e' && ++mlx->lose)
		paint_result(mlx);
	if ((*place_to_go == '0'
			|| *place_to_go == 'C') && ++mlx->player.step)
	{
		if (*c_place == '2')
			*c_place = 'E';
		else
			*c_place = '0';
		*place_to_go = 'P';
	}
	if (*place_to_go == 'E' && ++mlx->player.step)
	{	
		*place_to_go = '2';
		*c_place = '0';
	}
}
