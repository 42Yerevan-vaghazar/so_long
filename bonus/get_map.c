/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:05:37 by vaghazar          #+#    #+#             */
/*   Updated: 2022/06/05 15:55:24 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_format(char *str)
{
	char	*dot;

	dot = ft_strchr(str, '.');
	if (dot)
	{
		if (!ft_strcmp(dot, ".ber"))
			return (1);
	}
	ft_printf("Error: wrong format\n");
	return (0);
}

static int	check_components(char **map)
{
	int	i;
	int	j;
	int	count_p;
	int	count_c;
	int	count_e;

	initilizer_zero(&i, &j, &count_c, &count_p);
	count_e = 0;
	while (map[++i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count_p++;
			if (map[i][j] == 'E')
				count_e++;
			if (map[i][j++] == 'C')
				count_c++;
		}
		j = 0;
	}
	if (count_p == 1 && count_e > 0 && count_c > 0)
		return (1);
	ft_printf("Error: wrong component\n");
	return (0);
}

int	valid_map(char **map)
{
	int	i;
	int	j;
	int	sline;

	initilizer_zero(&i, &j, &i, &j);
	sline = ft_strlen(map[0]);
	while (map[i][j])
		if ((map[i][j++] != '1' || ft_strlen(map[i]) != sline)
			&& ft_printf("Error: wrong wall\n"))
			return (0);
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			if (((map[i][ft_strlen(map[i]) - 1] != '1' || map[i][0] != '1')
			&& ft_printf("Error: wrong wall")) || ((ft_strlen(map[i]) != sline
			|| !ft_strchr("CP01Ee", map[i][j]))
			&& ft_printf("Error: wrong component\n")))
				return (0);
		j = -1;
	}
	while (map[i - 1][++j])
		if (map[i - 1][j] != '1' && ft_printf("Error: wrong wall\n"))
			return (0);
	return (1);
}

char	**get_map(char *av)
{
	char	*line;
	char	**map;
	int		i;
	int		len;
	int		fd;

	initilizer_zero(&len, &i, &i, &len);
	line = 0;
	fd = open(av, O_RDONLY);
	while (++len && free_arr(line) && fd != -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	map = malloc(sizeof(char *) * len);
	if ((!close(fd) && !map) || !check_format(av))
		exit (1);
	fd = open(av, O_RDONLY);
	while (i < len && fd != -1)
		map[i++] = get_next_line(fd);
	if (fd == -1 || (!close(fd) && (!check_components(map)
				|| (!valid_map(map)))))
		exit (1);
	return (map);
}
