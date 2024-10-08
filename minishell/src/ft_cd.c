/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:27:55 by jonhan            #+#    #+#             */
/*   Updated: 2023/08/14 16:22:22 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cd_err(char *path, char *str)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	g_error_status = 1;
}

int	update_pwd(t_list ***environ)
{
	char	*getcwdstr;
	t_list	*tmp;

	getcwdstr = getcwd(NULL, 0);
	if (getcwdstr == NULL)
	{
		ft_putstr_fd("cd: error retrieving current directory: \
getcwd: cannot access parent ", 2);
		perror("directories");
		return (1);
	}
	tmp = ft_getenvnode(*environ, "PWD");
	if (tmp == NULL)
		return (1);
	free(tmp->content);
	tmp->content = ft_strjoin("PWD=", getcwdstr);
	free(getcwdstr);
	return (0);
}

char	*find_oldpwd(t_list **environ)
{
	char	*oldpwd;

	oldpwd = ft_getenv(environ, "PWD");
	if (oldpwd == NULL)
		return (NULL);
	return (oldpwd);
}

int	update_oldpwd(char *oldpwd_str, t_list **environ)
{
	t_list	*oldpwd;
	char	*str;

	oldpwd = ft_getenvnode(environ, "OLDPWD");
	if (oldpwd_str == NULL || oldpwd == NULL)
		return (1);
	str = ft_substr(oldpwd_str, \
		ft_indexof(oldpwd_str, '=') + 1, ft_strlen(oldpwd_str));
	if (oldpwd == NULL)
		ft_lstadd_back(environ, ft_lstnew((void *)ft_strjoin("OLDPWD=", str)));
	else
	{
		free(oldpwd->content);
		oldpwd->content = ft_strjoin("OLDPWD=", str);
	}
	free(str);
	free(oldpwd_str);
	return (0);
}

void	ft_cd(char **simple_cmd, t_list **environ, int fd)
{
	char	*pathname;
	char	*oldpwd;
	int		ch;

	(void)fd;
	g_error_status = 0;
	if (set_pathname(simple_cmd[1], &pathname, environ))
		return ;
	oldpwd = find_oldpwd(environ);
	ch = chdir(pathname);
	if (ch < 0)
		print_cd_err(pathname, "No such file or directory");
	else
	{
		update_pwd(&environ);
		update_oldpwd(oldpwd, environ);
	}
	free(pathname);
}
