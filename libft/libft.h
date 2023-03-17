#ifndef LIBFT_H
# define LIBFT_H

char			*ft_strchr(const char *string, int c);
char			*ft_strrchr(const char *string, int c);
unsigned int	strlen(const char *s);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int 			ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
int				strncmp(const char *s1, const char *s2, unsigned int n);

#endif
