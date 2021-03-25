#ifndef LIBASM_H
# define LIBASM_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_write(int fd, char *buff, int nb);
size_t	ft_read(int fd, char *buff, int nb);
char	*ft_strdup(char *src);
int		ft_list_size(t_list *begin);
void	ft_list_push_front(t_list **begin, void *data);

#endif