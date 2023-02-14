/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_emp_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:42:51 by alida-si          #+#    #+#             */
/*   Updated: 2023/02/13 21:12:33 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	verify_empty_lines(char *file, t_game **game)
{
	int	i;
	int	k;
	int	flag;

	i = -1;
	k = 0;
	flag = 0;
	while (file[++i])
	{
		if (file[i] == '\n'
			&& (file[i + 1] == ' ' || file[i + 1] == '0'
				|| file[i + 1] == '1'))
				flag++;
		if (flag > 0 && file[i + 1] == '\n')
			k++;
	}
	if (k - flag > 0)
	{
		free(file);
		print_error_exit(game, "find error on map...\n");
	}
}

void	verify_onlyspace_line(t_game **game)
{
	int		i;
	int		j;
	int		c;
	t_map	*map;

	i = 0;
	j = 1;
	map = (*game)->map;
	while (j < map->map_higth - 1)
	{
		c = 0;
		while (++i < map->map_width - 1)
			if (map->map[j][i] == '0')
				c++;
		if (c == 0)
			print_error_exit(game, "find only spaces or ones in line...\n");
		j++;
	}
}