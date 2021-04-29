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

/*
** BONUS
*/

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int		ft_list_size(t_list *begin);
void	ft_list_push_front(t_list **begin, void *data);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	*ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *));
int		ft_atoi_base(char *str, char *base);

#endif
