/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:41:30 by phan              #+#    #+#             */
/*   Updated: 2023/04/29 15:09:26 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 49152
# endif

char	*get_next_line(int fd);
char	*gnl_substr(char *s, int start, int len);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_clear(char *f_str1, char **back);
int		gnl_find(char *s, char c);
int		gnl_strlen(char *s);

#endif