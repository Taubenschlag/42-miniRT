/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_advanced_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2022/10/01 01:52:59 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../heads_global/minirt.h"

t_tuple	*tuple_negate(t_tuple *t)
{
	t_tuple	*res;

	res = (t_tuple *)malloc(sizeof(t_tuple));
	res->x = t->x * -1;
	res->y = t->y * -1;
	res->z = t->z * -1;
	res->type = t->type * -1;
	tuple_free(t);
	return (res);
}

double	tuple_length(t_tuple *t)
{
	return (
		sqrt(
			t->x * t->x
			+ t->y * t->y
			+ t->z * t->z
			+ t->type * t->type)
	);
}

t_tuple	*tuple_normalize(t_tuple *t)
{
	double	length;
	t_tuple	*n;

	length = tuple_length(t);
	n = tuple_vector(
			t->x / length,
			t->y / length,
			t->z / length);
	tuple_free(t);
	return (n);
}

double	tuple_dot_product(t_tuple *t1, t_tuple *t2)
{
	return (
		t1->x * t2->x
		+ t1->y * t2->y
		+ t1->z * t2->z
	);
}

t_tuple	*tuple_cross_product(t_tuple *t1, t_tuple *t2)
{
	return (
		tuple_vector(
			t1->y * t2->z - t1->z * t2->y,
			t1->z * t2->x - t1->x * t2->z,
			t1->x * t2->y - t1->y * t2->x
		)
	);
}
