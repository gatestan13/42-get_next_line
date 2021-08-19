#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		n_exists(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*join_str(const char *s1, const char *s2);

#endif