/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:16:02 by mcesar-d          #+#    #+#             */
/*   Updated: 2023/02/09 18:38:29 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file(char **file)
{
	free_matrix(file);
	file = NULL;
}

void	**read_file(int fd, t_game **game)
{
	char		*line;
	char		*ret;
	int			check_flag;

	check_flag = 0;
	ret = get_next_line(fd);
	check_flag += check_file_line(ret);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_flag += check_file_line(line);
		ret = ft_strjoin(ret, line);
		free(line);
	}
	close (fd);
	if (check_flag == 0)
		(*game)->file = ft_split(ret, '\n');
	free(ret);
}

void	verify_map(t_game **game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < (*game)->map->map_width)
		if ((*game)->map->map[0][y] != '1'
			|| (*game)->map->map[(*game)->map->map_higth - 1][y] != '1')
			print_error_exit(game, "Error: map needs to be closed...\n");
	x = -1;
	while (++x < (*game)->map->map_higth)
		if ((*game)->map->map[x][0] != '1'
			|| (*game)->map->map[x][(*game)->map->map_width - 1] != '1')
			print_error_exit(game, "Error: map needs to be closed...\n");
	x = -1;
	while (++x < (*game)->map->map_higth)
	{
		y = -1;
		while (++y < (*game)->map->map_width)
			if ((*game)->map->map[x][y] == 'E')
				print_error_exit(game, "Error: find error on map...\n");
	}
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	*game;

	fd = check_input(argc, argv);
	init_data(&game);
	read_file(fd, &game);
	if (game->file != NULL)
	{
		get_map(game->file, &game->map);
		get_header(&game);
		verify_map(&game);
		print_whole_map(game);
	}
	free_cub3d(&game);
	return (0);
}
