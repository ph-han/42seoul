/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:36:30 by phan              #+#    #+#             */
/*   Updated: 2023/02/02 10:48:40 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef	t_bool int;
# define EVEN(nbr) nbr % 2 == 0
# define TRUE 1
# define FALSE 0
# define EVEN_MSG "I have an even number of arguments"
# define ODD_MSG "I have an odd number of arguments"
# define SUCCESS 0

#endif
