/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2022/10/01 01:40:35 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include "../../../heads_global/minirt.h"

typedef struct world
{
	int		shape_counter;
	int		lights_counter;
	t_shape	**shapes;
	t_light	**lights;
	t_light	*ambienace;
}	t_world;

t_world	*make_world(t_shape **shapes, t_light **lights, int shape_counter,
					   int light_counter);
void	world_set_ambience(t_world *w, t_tuple *from, t_tuple *color);
t_world	*make_default_world(void);
void	free_world_deep(t_world *w);

#endif