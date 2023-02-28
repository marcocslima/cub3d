/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:24:17 by alida-si          #+#    #+#             */
/*   Updated: 2023/02/27 20:47:03 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data_header(t_map_header **header)
{
	*header = (t_map_header *) malloc(sizeof(t_map_header));
	(*header)->c = NULL;
	(*header)->ea = NULL;
	(*header)->f = NULL;
	(*header)->no = NULL;
	(*header)->so = NULL;
	(*header)->we = NULL;
}

void	init_data_map(t_map **map)
{
	*map = (t_map *) malloc(sizeof(t_map));
	(*map)->map_higth = 0;
	(*map)->map_width = 0;
	(*map)->init_map = 0;
	(*map)->map = NULL;
}

// void	init_img(t_img **img)
// {
// 	*img = (t_img *) malloc(sizeof(t_img));
// 	(*img)->img = NULL;
// 	(*img)->addr = NULL;
// 	(*img)->bpp = 0;
// 	(*img)->line_length = 0;
// 	(*img)->endian = 0;
// }

void	init_data(t_game **game)
{
	t_map_header	*header;
	t_map			*map;
	//t_img			*img;

	init_data_header(&header);
	init_data_map(&map);
	//init_img(&img);
	*game = (t_game *) malloc(sizeof(t_game));
	(*game)->map = map;
	(*game)->header = header;
	(*game)->file = NULL;
}
