/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:28:46 by phan              #+#    #+#             */
/*   Updated: 2023/04/23 13:44:47 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		gnl_strlen(char *s);
char	*gnl_substr(char *s, int start, int len);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *s, char c);

#endif
