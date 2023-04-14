/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:22:27 by alida-si          #+#    #+#             */
/*   Updated: 2023/04/13 19:49:39 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx_data->mlx_ptr, game->img_data->mlx_img);
	mlx_destroy_image(game->mlx_data->mlx_ptr, game->texture_img->ea->mlx_img);
	mlx_destroy_image(game->mlx_data->mlx_ptr, game->texture_img->no->mlx_img);
	mlx_destroy_image(game->mlx_data->mlx_ptr, game->texture_img->so->mlx_img);
	mlx_destroy_image(game->mlx_data->mlx_ptr, game->texture_img->we->mlx_img);
	mlx_destroy_window(game->mlx_data->mlx_ptr, game->mlx_data->mlx_win);
	mlx_destroy_display(game->mlx_data->mlx_ptr);
	free(game->mlx_data->mlx_ptr);
	close_game(&game, EXIT_SUCCESS);
}

void	close_game(t_game **game, int exit_code)
{
	free_cub3d(game);
	exit(exit_code);
}
