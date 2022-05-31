/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:45:29 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/31 21:20:31 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int allocate_component(void *img, t_img *imgs, t_mlx *mlx, char component)
{
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->map[mlx->y])
	{
		while (mlx->map[mlx->y][mlx->x])
		{
			if (mlx->map[mlx->y][mlx->x] == 'P' || mlx->map[mlx->y][mlx->x] == '2')
			{
				mlx->player.x = mlx->x;
				mlx->player.y = mlx->y;
			}
			if (mlx->map[mlx->y][mlx->x] == component || component == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, mlx->x * mlx->img_width, mlx->y * mlx->img_height);
			if (mlx->map[mlx->y][mlx->x] == '2')
			{	
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, imgs->zero, mlx->x * mlx->img_width, mlx->y * mlx->img_height);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, imgs->exit, mlx->x * mlx->img_width, mlx->y * mlx->img_height);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, imgs->player, mlx->x * mlx->img_width, mlx->y * mlx->img_height);
			}
			mlx->x++;
		}
		mlx->x = 0;
		mlx->y++;
	}
	return (0);
}

int	fill_window(t_mlx *mlx, t_img *imgs)
{
	int a;
	size_t win_width;
	size_t win_height;

	win_height = 0;
	win_width = ft_strlen(*(mlx)->map);
	while (mlx->map[win_height])
		win_height++;
	win_height += 2;
	if (!mlx->mlx_win)
		mlx->mlx_win = mlx_new_window(mlx->mlx, win_width * mlx->img_width, win_height * mlx->img_height, "so_long");
	allocate_component(imgs->zero, imgs, mlx, '0');
	allocate_component(imgs->obstacle, imgs, mlx, '1');
	allocate_component(imgs->player, imgs, mlx, 'P');
	allocate_component(imgs->coin, imgs, mlx, 'C');
	allocate_component(imgs->exit, imgs, mlx, 'E');
	allocate_component(imgs->enemy, imgs, mlx, 'e');
	return (1);
}

int ft_swap_components(t_mlx *mlx, char *current_place, char *place_to_go)
{
	if (*place_to_go == 'C')
		mlx->coin_num -= 1;
	if (*place_to_go == 'e')
		exit(1);
	if (*place_to_go == '0' ||
		*place_to_go == 'C')
	{
		if (*current_place == '2')
			*current_place = 'E';
		else
			*current_place = '0';
		*place_to_go = 'P';
	}
	if (*place_to_go == 'E')
	{	
		*place_to_go = '2';
		*current_place = '0';
	}
	return (1);
}

int ft_press(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
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
	mlx->player.step += 1;
	printf("%zu\n", mlx->player.step);
	fill_window(mlx, &mlx->imgs);
	if ((mlx->map[mlx->player.y][mlx->player.x] == '2'
		&& mlx->coin_num == 0) || mlx->map[mlx->player.y][mlx->player.x] == 'e')
		exit(1);
	mlx_hook(mlx->mlx_win, 3, 1L << 1, ft_press, mlx);
	return (1);
}

void count_coins(t_mlx *mlx)
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

int ft_close(t_mlx *mlx)
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

int main(int ac, char **av)
{    
	t_mlx   mlx;
	t_img	imgs;
	int i = 0;

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
