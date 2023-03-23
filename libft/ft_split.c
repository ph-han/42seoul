/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:54:02 by phan              #+#    #+#             */
/*   Updated: 2023/03/23 21:54:58 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int wc;

	wc = 0;
	while (*(s + 1))
	{
		if (c == *s && c != )
			wc++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**w_list;
	int		w_list_len;
	int		idx;

	w_list_len = word_count(s, c);
}
