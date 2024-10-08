/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:30:17 by phan              #+#    #+#             */
/*   Updated: 2023/02/02 14:49:13 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	is_sep(char c, char *to_find)
{
	while (*to_find)
	{
		if (c == *to_find)
			return (1);
		to_find++;
	}
	return (0);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	dest_len;
	int	src_len;

	dest_len = 0;
	src_len = 0;
	while (*(src + src_len) && src_len < n)
	{
		*(dest + dest_len) = *(src + src_len);
		dest_len++;
		src_len++;
	}
	*(dest + dest_len) = '\0';
	return (dest);
}

void	input_word(int w_size, char **result, int r_idx, char *str)
{
	result[r_idx] = (char *)malloc(w_size + 1);
	result[r_idx] = ft_strncpy(result[r_idx], str - w_size, w_size);
}

void	update_result(char **result, int r_idx, char *str, char *charset)
{
	int	w_size;
	int	s_idx;

	s_idx = 0;
	w_size = 0;
	while (*(str + s_idx))
	{
		if (is_sep(str[s_idx], charset))
		{
			if (w_size)
				input_word(w_size, result, r_idx++, str + s_idx);
			w_size = 0;
		}
		else
			w_size++;
		s_idx++;
	}
	if (w_size)
		input_word(w_size, result, r_idx, str + s_idx);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_num;
	int		s_idx;

	word_num = 0;
	s_idx = 0;
	while (*(str + s_idx))
	{	
		if (!is_sep(str[s_idx], charset)  && !str[s_idx + 1])
			word_num++;
		else if (!is_sep(str[s_idx], charset)  && is_sep(str[s_idx + 1], charset))
			word_num++;
		s_idx++;
	}
	result = (char **)malloc(sizeof(char *) * (word_num + 1));
	update_result(result, 0, str, charset);
	result[word_num] = 0;
	return (result);
}
