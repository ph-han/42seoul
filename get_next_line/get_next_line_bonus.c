/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:41:25 by phan              #+#    #+#             */
/*   Updated: 2023/04/29 14:49:32 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_until_find_nl_or_end(int fd, char *backup, int rb)
{
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];

	while (1)
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb == 0)
			break ;
		if (rb < 0)
			return (gnl_clear(backup, &backup));
		if (!backup)
			backup = gnl_strjoin("", "");
		if (!backup)
			return (0);
		buff[rb] = '\0';
		tmp = backup;
		backup = gnl_strjoin(tmp, buff);
		free(tmp);
		if (!backup)
			return (0);
		if (backup[gnl_find(backup, '\n')] == '\n')
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*backup[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	tmp = read_until_find_nl_or_end(fd, backup[fd], 1);
	if (!tmp || !*tmp)
	{
		if (tmp)
			free(backup[fd]);
		backup[fd] = 0;
		return (0);
	}
	line = gnl_substr(tmp, 0, gnl_find(tmp, '\n') + 1);
	if (!line)
		return (gnl_clear(tmp, &backup[fd]));
	backup[fd] = gnl_substr(tmp, gnl_find(tmp, '\n') + 1, \
				gnl_strlen(tmp) - gnl_find(tmp, '\n'));
	free(tmp);
	if (!backup[fd])
		return (gnl_clear(line, &line));
	return (line);
}
