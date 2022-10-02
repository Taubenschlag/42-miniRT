/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2022/10/01 03:05:32 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../heads_global/minirt.h"

//todo mem
s_tuple	*nsphere_normal_at(s_tuple *p, s_matrix *m)
{
	s_tuple	*obj_normal;
	s_tuple	*world_normal;

	obj_normal = tuple_substract(tuple_copy(p), tuple_point(0, 0, 0));
	world_normal = tuple_apply_trans_matrix(
			matrix_transpose(matrix_invert(m)), obj_normal);
	world_normal->type = IS_VECTOR;
	tuple_free(p);
	return (tuple_normalize(world_normal));
}

s_nsphere	*nsphere_nsphere(s_tuple *centre)
{
	s_nsphere	*nsphere;

	nsphere = (s_nsphere *)malloc(sizeof(s_nsphere));
	nsphere->centre = centre;
	return (nsphere);
}

s_nsphere	*nsphere_unit(s_tuple *centre)
{
	return (nsphere_nsphere(centre));
}

void	nsphere_free(s_nsphere *s)
{
	if (s->centre)
		tuple_free((s->centre));
	free(s);
}