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

#include<math.h>

typedef struct s_window
{
	void	*mlx_ptr;
	int		w;
	int		h;
	void	*wall;
	int		tex_w;
	int		tex_h;
} t_win;

typedef struct s_put_size
{
	double	perpwalldist;
	int		lineheight;
	int		drawend;
	int		drawstart;
	double	wall_x;
	int		tex_x;
	int		side;
} t_size;

typedef struct s_renderargs
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
	t_size	size;
	t_win	window;
} t_render;

void	set_dir(t_game *game);
void	set_position(t_game *game);
char	get_spawn_dir(t_game *game);
void	set_plane(t_game *game, t_render *args);
void	set_raydir(t_game *game, t_render *args, double x);
int		init_window(t_render *args);
void	set_map(t_render *args, t_game *game);
void	get_raycast_arg(t_game *game, t_render *args, int x);
void	run_dda(t_render *args, t_game *game);
void	set_wall_size(t_render *args, t_game *game);