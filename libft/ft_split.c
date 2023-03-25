/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:54:02 by phan              #+#    #+#             */
/*   Updated: 2023/03/25 15:52:35 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	wc;

	wc = 0;
	if (*s && *s != c)
		wc++;
	while (*s && *(s + 1))
	{
		if (c == *s && c != *(s + 1))
			wc++;
		s++;
	}
	return (wc);
}

char	*make_str(char const *s, int w_len)
{
	char	*w;
	char	*new_w;

	w = (char *)malloc(sizeof(char) * (w_len + 1));
	if (!w)
		return (0);
	ft_memmove(w, s, w_len);
	w[w_len] = '\0';
	new_w = ft_strdup(w);
	free(w);
	return (new_w);
}

char	**ft_split(char const *s, char c)
{
	char	**w_list;
	int		w_list_len;
	int		w_len;
	int		idx;

	w_list_len = word_count(s, c);
	w_list = (char **)malloc(sizeof(char *) * (w_list_len + 1));
	if (!w_list)
		return (0);
	idx = 0;
	while (idx < w_list_len)
	{
		while (*s && *s == c)
			s++;
		w_len = 0;
		while (*(s + w_len) && *(s + w_len) != c)
			w_len++;
		if (w_len)
		{
			w_list[idx++] = make_str(s, w_len);
			s += w_len;
		}
	}
	w_list[w_list_len] = 0;
	return (w_list);
}
