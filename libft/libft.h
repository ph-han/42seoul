/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:49:28 by phan              #+#    #+#             */
/*   Updated: 2023/03/18 17:48:03 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

char			*ft_strnstr(const char *haystack, \
		const char *needle, unsigned int len);
char			*ft_strchr(const char *string, int c);
char			*ft_strrchr(const char *string, int c);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size);
unsigned int	ft_strlen(const char *s);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);

#endif