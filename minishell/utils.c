#include "minishell.h"

int	is_delim_in_dquote(char c)
{
	return (c == '<' || c == '>' || c == '\'' || c == '|' || c == '$' || c == ' ');
}
