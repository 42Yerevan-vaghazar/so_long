/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:38:14 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/31 14:02:17 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	main(int ac, char **av)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;
// 	char	*relative_path = "./test.xpm";
// 	int		img_width;
// 	int		img_height;
// 	int     fd;
// 	char	*map_line;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img = mlx_xpm_file_to_image(mlx, ZERO_IMG, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
// 	mlx_loop(mlx); 

// 	// fd = open(av[1], O_RDONLY);
// 	// map_line = get_next_line(fd);
// 	// printf("%s\n", map_line);
// }

// #include <mlx.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
// }
