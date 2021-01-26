#include <stdio.h>
#include <string.h>

int	ft_strlen(char *s);
int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char *s;
	char *s2;

	s = "Hello world !";
	printf("[%s], %d\n", s, ft_strlen(s));
	
	s2 = "Hello";
	printf("[%s], [%s], %d\n", s, s2, ft_strcmp(s, s2));
	printf("[%s], [%s], %d\n", s, s2, strcmp(s, s2));
	return (0);
}
