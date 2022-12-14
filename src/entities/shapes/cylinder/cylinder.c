/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2022/10/01 03:12:54 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../heads_global/minirt.h"

t_cylinder	*cylinder_cylinder(void)
{
	t_cylinder	*c;

	c = (t_cylinder *)malloc(sizeof(t_cylinder));
	c->closed = 0;
	c->min = INFINITY * -1;
	c->max = INFINITY * 1;
	return (c);
}

t_cylinder	*cylinder_params(double h)
{
	t_cylinder	*c;

	c = cylinder_cylinder();
	c->min = 0;
	c->max = h;
	c->closed = 1;
	return (c);
}

t_tuple	*cylinder_normale_at(t_tuple *t, t_cylinder *c)
{
	double	dist;

	dist = t->x * t->x + t->z * t->z;
	if (dist < 1 && t->y >= (c->max - 0.00001))
		return (tuple_vector(0, 1, 0));
	if (dist < 1 && t->y <= (c->min + 0.00001))
		return (tuple_vector(0, -1, 0));
	return (tuple_vector(t->x, 0, t->z));
}

int	check_cap(t_ray *r, double t)
{
	double	x;
	double	z;
	double	temp;

	x = r->origin->x + t * r->dir->x;
	z = r->origin->z + t * r->dir->z;
	temp = fabs(x * x) + fabs(z * z);
	return (temp <= 1);
}

void	cylinder_free(t_cylinder *c)
{
	free(c);
}
