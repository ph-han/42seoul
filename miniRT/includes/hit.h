/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:50:16 by phan              #+#    #+#             */
/*   Updated: 2023/10/04 20:28:49 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "vec3.h"

typedef struct s_hit
{
	double			d;
	t_vec3			point;
	t_vec3			normal;
	struct s_object	*obj;
}	t_hit;

#endif
