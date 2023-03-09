/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:24:17 by alida-si          #+#    #+#             */
/*   Updated: 2023/03/08 19:44:03 by alida-si         ###   ########.fr       */
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

void	init_data_mlx(t_data **mlx_data)
{
	*mlx_data = (t_data *) malloc(sizeof(t_data));
	(*mlx_data)->mlx_ptr = mlx_init();
	(*mlx_data)->mlx_win = mlx_new_window((*mlx_data)->mlx_ptr,
			500, 500, "cub3D");
}

void	init_data_img(t_img **img)
{
	*img = (t_img *) malloc(sizeof(t_img));
	(*img)->mlx_img = NULL;
	(*img)->addr = NULL;
	(*img)->bpp = 0;
	(*img)->endian = 0;
	(*img)->line_len = 0;
	(*img)->y_position = 250;
	(*img)->x_position = 250;
}

void	init_data(t_game **game)
{
	t_map_header	*header;
	t_map			*map;
	t_data			*mlx_data;
	t_img			*img;

	init_data_header(&header);
	init_data_map(&map);
	init_data_mlx(&mlx_data);
	init_data_img(&img);
	*game = (t_game *) malloc(sizeof(t_game));
	(*game)->map = map;
	(*game)->header = header;
	(*game)->mlx_data = mlx_data;
	(*game)->img_data = img;
	(*game)->file = NULL;
}
