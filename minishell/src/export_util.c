/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:40:09 by jonhan            #+#    #+#             */
/*   Updated: 2023/08/14 18:07:03 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_invalid_key(int c)
{
	return (c == '!' || c == ' ' || c == '\\'
		|| c == '?' || c == '\'' || c == '\"');
}

int	print_export_err(char *str)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
	return (0);
}

char	*make_word(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	ret = ft_substr(str, 0, i);
	return (ret);
}

int	is_valid_export_arg(char *str, char *simple_cmd)
{
	int	i;

	i = 0;
	if (str[0] && ft_isdigit(str[0]))
		return (print_export_err(str));
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (print_export_err(str));
		++i;
	}
	if (i == 0)
		return (print_export_err(simple_cmd));
	return (1);
}

void	print_export_list(t_list **environ, int fd)
{
	t_list	*tmp;

	tmp = *environ;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putendl_fd(tmp->content, fd);
		tmp = tmp->next;
	}
}
