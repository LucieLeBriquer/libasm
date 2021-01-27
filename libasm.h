#ifndef LIBASM_H
# define LIBASM_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_write(int fd, char *buff, int nb);
size_t	ft_read(int fd, char *buff, int nb);
char	*ft_strdup(char *src);

#endif
