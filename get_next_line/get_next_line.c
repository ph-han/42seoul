/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:40:09 by phan              #+#    #+#             */
/*   Updated: 2023/04/15 19:31:53 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			read_bytes;
	int			nl_idx;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	static char	*backup = "";
	
	while (find_nl(backup) == -1 && (read_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_bytes] = '\0';
		nl_idx = find_nl(buff);
		if (nl_idx >= 0)
		{
			if (nl_idx == 0)
				line = (char *)malloc(1 + gnl_strlen(backup) + 1);
			else
				line = (char *)malloc(nl_idx + gnl_strlen(backup) + 1);
			gnl_memcpy(line, backup, gnl_strlen(backup));
			gnl_memcpy(line, buff, nl_idx);
			backup = gnl_substr(buff, nl_idx + 1, read_bytes - nl_idx);
			return (line);
		}
		if (gnl_strlen(backup))
			gnl_memcpy(backup, buff, read_bytes);
		else
			backup = gnl_substr(buff, 0, read_bytes);
	}
	if (find_nl(backup) >= 0)
	{
		if (find_nl(backup) == 0)
			line = (char *)malloc(1 + 1);
		else
			line = (char *)malloc(find_nl(backup));
		gnl_memcpy(line, backup, find_nl(backup));
		gnl_memcpy(backup, backup + find_nl(backup) + 1, \
		gnl_strlen(backup) - find_nl(backup));
		return (line);
	}
	return (0);
}
