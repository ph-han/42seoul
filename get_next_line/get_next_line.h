/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:28:46 by phan              #+#    #+#             */
/*   Updated: 2023/04/27 16:12:29 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_substr(char *s, int start, int len);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_find(char *s, char c);
int		gnl_strlen(char *s);

#endif
