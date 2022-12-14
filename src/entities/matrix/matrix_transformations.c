/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2022/10/01 22:33:49 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../heads_global/minirt.h"

t_matrix	*matrix_translate(double x, double y, double z)
{
	t_matrix	*trans;

	trans = matrix_identity(4);
	trans->matrix[0][3] = x;
	trans->matrix[1][3] = y;
	trans->matrix[2][3] = z;
	return (trans);
}

t_matrix	*matrix_scale(double x, double y, double z)
{
	t_matrix	*scl;

	scl = matrix_identity(4);
	scl->matrix[0][0] = x;
	scl->matrix[1][1] = y;
	scl->matrix[2][2] = z;
	return (scl);
}

t_matrix	*matrix_x_rotate(double r)
{
	t_matrix	*scl;

	scl = matrix_identity(4);
	if (r != 0)
	{
		scl->matrix[1][1] = cos(r);
		scl->matrix[1][2] = -1 * sin(r);
		scl->matrix[2][1] = sin(r);
		scl->matrix[2][2] = cos(r);
	}
	return (scl);
}

t_matrix	*matrix_y_rotate(double r)
{
	t_matrix	*scl;

	scl = matrix_identity(4);
	if (r != 0)
	{
		scl->matrix[0][0] = cos(r);
		scl->matrix[2][0] = -1 * sin(r);
		scl->matrix[0][2] = sin(r);
		scl->matrix[2][2] = cos(r);
	}
	return (scl);
}

t_matrix	*matrix_z_rotate(double r)
{
	t_matrix	*scl;

	scl = matrix_identity(4);
	if (r != 0)
	{
		scl->matrix[0][0] = cos(r);
		scl->matrix[0][1] = -1 * sin(r);
		scl->matrix[1][0] = sin(r);
		scl->matrix[1][1] = cos(r);
	}
	return (scl);
}
