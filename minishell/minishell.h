#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"

typedef struct s_exp_vars
{

	char	*exp;
	char	*new;
	char	*parsed_env;
	int		env_size;
}	t_exp_vars;
/**
 * env tonkenizer test cases
 * 
 * "'"'$USER'"'"
 * '$USER'
 * "'$USER'"
 */

/** 확장시 1 안되면 0
 * "$USER" 1
 * '$USER' 0
 * "'"$USER"'" 1
 * "'"'$USER'"'" 0
 */
#endif


