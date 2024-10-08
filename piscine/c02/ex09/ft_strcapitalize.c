/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:57:07 by phan              #+#    #+#             */
/*   Updated: 2023/01/18 20:28:04 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
void	update_word(char *str, int *word_len);

void	update_word(char *str, int *word_len)
{
	if (*(str - *word_len) < '0' || *(str - *word_len) > '9')
	{
		if (*(str - *word_len) >= 'a' && *(str - *word_len) <= 'z')
			*(str - *word_len) -= ('a' - 'A');
	}
	while (*word_len > 0)
	{
		(*word_len)--;
		if (*(str - *word_len) >= 'A' && *(str - *word_len) <= 'Z')
			*(str - *word_len) += ('a' - 'A');
	}
}

char	*ft_strcapitalize(char *str)
{
	int	word_len;
	int	string_len;

	word_len = 0;
	string_len = 0;
	while (*str != '\0')
	{
		if ((*str < '0' || *str > '9') && \
				(*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
		{
			update_word(str, &word_len);
		}
		else
			word_len++;
		str++;
		string_len++;
	}
	update_word(str, &word_len);
	return (str - string_len);
}
