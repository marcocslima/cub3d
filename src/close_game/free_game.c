/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:22:44 by alida-si          #+#    #+#             */
/*   Updated: 2023/04/17 16:36:15 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_matrix(char **ptr)
{
	int	i;

	if (ptr != NULL)
	{
		i = 0;
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(ptr);
	}
}

void	free_ptr(void **ptr)
{
	if (ptr != NULL)
		free(ptr);
}

void	free_map_header(t_map_header **header)
{
	free_ptr((void *)(*header)->no);
	free_ptr((void *)(*header)->so);
	free_ptr((void *)(*header)->we);
	free_ptr((void *)(*header)->ea);
	free_ptr((void *)(*header)->f);
	free_ptr((void *)(*header)->c);
}

void	free_game_assets(t_game **game)
{
	free((*game)->texture_img->ea);
	free((*game)->texture_img->no);
	free((*game)->texture_img->so);
	free((*game)->texture_img->we);
	free((*game)->background_color);
	free((*game)->texture_img);
	free((*game)->img);
	free((*game)->mlx);
}

void	free_cub3d(t_game **game)
{
	free_map_header(&(*game)->header);
	free_matrix((*game)->map->matrix);
	free_matrix((*game)->file);
	free((*game)->header);
	free((*game)->map);
	free(*game);
}
