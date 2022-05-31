/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:05:37 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/31 20:06:26 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	valid_map(char **map)
{
	int	i;
	int	j;
	int	sline;
	
	i = 0;
	j = 0;
	sline = ft_strlen(map[0]);
	while (map[i][j])
		if (map[i][j++] != '1' || ft_strlen(map[i]) != sline)
			return (0);
	j = 0;
	i++;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((map[i][ft_strlen(map[i]) - 1] != '1' || map[i][0] != '1') 
				|| ft_strlen(map[i]) != sline || !ft_strchr(COMPONENTS, map[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	while (map[i - 1][j])
		if (map[i - 1][j++] != '1')
			return (0);
	return (1);
}

char    **get_map(char *av)
{
	char	*line;
	char	**map;
	int		i;
	int		len;
	int		fd;

	len = 0;
	fd = open(av, O_RDONLY);
	while (++len)
	{
		line = get_next_line(fd);
		if (!line)
			break ;	
		free(line);
	}
	map = malloc(sizeof(char *) * len);
	if (!map)
		return (NULL);
	i = 0;
	close(fd);
	fd = open(av, O_RDONLY);
	while (i < len)
		map[i++] = get_next_line(fd);
	close(fd);
	valid_map(map);
	return (map);
}

// int main(int ac, char **av)
// {
// 	char	**str;
// 	int i = 0;
// 	if (ac != 2)
// 		exit(1);

// 	str = get_map(av[1]);
// 	printf("%d\n", valid_map(str));
// 	while (str[i])
// 		printf("%s\n", str[i++]);
// }