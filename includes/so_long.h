/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:32:35 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/31 20:25:22 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#  define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "keys.h"

# define COIN_IMG "./src_img/coin.xpm"
# define OBSTACLE_IMG "./src_img/obstacle.xpm"
# define PLAYER_IMG "./src_img/player.xpm"
# define ZERO_IMG "./src_img/zero.xpm"
# define EXIT_IMG "./src_img/exit.xpm"
# define ENEMY "./src_img/enemy.xpm"
# define COMPONENTS "CP01Ee"

typedef struct s_player
{
	int		x;
	int		y;
	size_t	step;
}				t_player;

typedef struct s_img
{
	void	*zero;
	void	*coin;
	void	*player;
	void	*exit;
	void	*enemy;
	void	*obstacle;
}				t_img;
typedef struct s_data
{
    void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
	char	**map;
	int		coin_num;
    int     x;
    int     y;
	t_player player;
	t_img	imgs;
}               t_mlx;



char    **get_map(char *av);
int		allocate_obstacles(char **map, t_mlx *mlx);
int		allocate_zero(char **map, t_mlx *mlx);
// int		allocate_component(char **map, t_mlx *mlx, char component, char upper);
// int		fill_window(t_mlx *mlx, char **map, t_imp imgs);
t_img	*get_imgs(t_mlx *mlx, t_img *imgs);

#endif