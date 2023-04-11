/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:24:17 by alida-si          #+#    #+#             */
/*   Updated: 2023/04/11 15:39:15 by alida-si         ###   ########.fr       */
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
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
}

void	init_data_img(t_img **img)
{
	*img = (t_img *) malloc(sizeof(t_img));
	(*img)->mlx_img = NULL;
	(*img)->addr = NULL;
	(*img)->bpp = 0;
	(*img)->endian = 0;
	(*img)->line_len = 0;
}

void	init_player(t_player **player)
{
	*player = (t_player *) malloc(sizeof(t_player));
	(*player)->y_position = 0;
	(*player)->x_position = 0;
	(*player)->angle = 2 * PI;
	(*player)->delta_x = 0;
	(*player)->delta_y = 0;
}

void	init_ray(t_ray_casting **ray)
{
	*ray = (t_ray_casting *) malloc(sizeof(t_ray_casting));
	(*ray)->wall_color = 0;
	(*ray)->wall_plane = -1;
	(*ray)->x_coordinate = 0;
	(*ray)->y_coordinate = 0;
	(*ray)->length = 0;
}

void	init_data_texture_img(t_texture_img **texture_img, t_img *img)
{
	*texture_img = (t_texture_img *) malloc(sizeof(t_texture_img));
	init_data_img(&(*texture_img)->ea);
	init_data_img(&(*texture_img)->no);
	init_data_img(&(*texture_img)->so);
	init_data_img(&(*texture_img)->we);
}

void	init_data(t_game **game)
{
	t_map_header	*header;
	t_map			*map;
	t_data			*mlx_data;
	t_img			*img;
	t_player		*player;
	t_ray_casting	*ray;
	t_img			*teste;
	t_img			*teste2;
	t_texture_img	*texture_img;

	init_data_header(&header);
	init_data_map(&map);
	init_data_mlx(&mlx_data);
	init_data_img(&img);
	init_player(&player);
	init_ray(&ray);
	init_data_img(&teste);
	init_data_img(&teste2);
	init_data_texture_img(&texture_img, img);
	*game = (t_game *) malloc(sizeof(t_game));
	(*game)->map = map;
	(*game)->header = header;
	(*game)->mlx_data = mlx_data;
	(*game)->img_data = img;
	(*game)->player = player;
	(*game)->ray = ray;
	(*game)->teste_img = teste;
	(*game)->teste_img2 = teste2;
	(*game)->texture_img = texture_img;
	(*game)->file = NULL;
}
