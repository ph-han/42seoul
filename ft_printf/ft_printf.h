/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:54:58 by phan              #+#    #+#             */
/*   Updated: 2023/04/08 15:02:42 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);

#endif
