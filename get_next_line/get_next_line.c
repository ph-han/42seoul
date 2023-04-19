/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:40:09 by phan              #+#    #+#             */
/*   Updated: 2023/04/18 21:05:58 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			rb;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	static char	*backup;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	if (!backup)
	{
		while (1)
		{
			rb = read(fd, buff, BUFFER_SIZE);
			if (rb <= 0)
				break ;
			buff[rb] = '\0';
			if (!backup)
				backup = gnl_str_join_dup(backup, "");
			temp = backup;
			backup = gnl_str_join_dup(temp, buff);
			free(temp);
			if (!backup)
				return (0);
		}
		if (rb < 0)
			return (0);
	}
	if (backup && find_nl(backup) != -1)
	{
		line = (char *)malloc(find_nl(backup) + 1 + 1);
		if (!line)
			return (0);
		gnl_memcpy(line, backup, find_nl(backup));
		line[find_nl(backup) + 1] = '\0';
		temp = backup;
		backup = gnl_substr(temp, find_nl(temp) + 1, gnl_strlen(temp));
		free(temp);
		temp = NULL;
		return (line);
	}
	if (!backup)
		return (0);
	line = (char *)malloc(gnl_strlen(backup) + 1);
	if (!line)
		return (0);
	gnl_memcpy(line, backup, gnl_strlen(backup));
	free(backup);
	backup = NULL;
	return (line);
}
