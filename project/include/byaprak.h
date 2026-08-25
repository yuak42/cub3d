/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byaprak.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:00:24 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:57:46 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct s_renderArgs
{
	double	plane_x;
	double	plane_y;
	double	ray_dirx;
	double	ray_diry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
} t_render;

typedef struct s_window
{
	void	*mlx_ptr;
	int		w;
	int		h;
} t_win;


void	set_dir(t_game *game);
void	set_position(t_game *game);
char	get_spawn_dir(t_game *game);
void	set_plane(t_game *game, t_render *args);
void	set_raydir(t_game *game, t_render *args, double width, double x);
int		init_window(t_win *s_window);
void	set_map(t_render *args, t_game *game);
void	get_raycast_arg(t_game *game, t_render *args, t_win *window, int x);
void	run_dda(t_render *args, t_map *map);