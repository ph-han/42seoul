/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:40:09 by phan              #+#    #+#             */
/*   Updated: 2023/04/23 14:19:33 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_nl_or_end(int fd, char *backup)
{
	int		rb;
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];

	while (1)
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb < 0)
			return (0);
		buff[rb] = '\0';
		if (rb == 0)
			break ;
		if (!backup)
			backup = gnl_strjoin("", "");
		tmp = backup;
		backup = gnl_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
		if (!backup)
			return (0);
		if (gnl_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	int			nl_idx;
	static char	*backup;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	tmp = read_until_nl_or_end(fd, backup);
	if (!tmp || !*tmp)
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
	nl_idx = 0;
	while (tmp[nl_idx] && tmp[nl_idx] != '\n')
		nl_idx++;
	if (tmp[nl_idx] == '\0')
		nl_idx -= 1;
	line = gnl_substr(tmp, 0, nl_idx + 1);
	if (!line || !*line)
		return (0);
	backup = gnl_substr(tmp, nl_idx + 1, gnl_strlen(tmp) - nl_idx);
	if (!backup)
		return (0);
	free(tmp);
	tmp = NULL;
	return (line);
}
