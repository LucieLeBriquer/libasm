#include <stdio.h>
#include <string.h>

int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);

void	test_strlen(void)
{
	char *s;

	printf("--- FT_STRLEN ---\n");
	s = "Hello world !";
	printf("orig : [%s], %d\n", s, ft_strlen(s));
	printf("mine : [%s], %d\n", s, ft_strlen(s));
	printf("\n");
}

void	test_strcmp(void)
{
	char *s;
	char *s2;

	printf("--- FT_STRCMP ---\n");
	s = "Hello world !";
	s2 = "Hellu";
	printf("mine : [%s], [%s], %d\n", s, s2, ft_strcmp(s, s2));
	printf("orig : [%s], [%s], %d\n", s, s2, strcmp(s, s2));
	s = "H";
	s2 = "Hello";
	printf("mine : [%s], [%s], %d\n", s, s2, ft_strcmp(s, s2));
	printf("orig : [%s], [%s], %d\n", s, s2, strcmp(s, s2));
	s = "Hello";
	s2 = "Hello";
	printf("mine : [%s], [%s], %d\n", s, s2, ft_strcmp(s, s2));
	printf("orig : [%s], [%s], %d\n", s, s2, strcmp(s, s2));
	printf("\n");
}

void	test_strcpy(void)
{
	char dest[20];
	char dest2[20];
	char *src;

	printf("--- FT_STRCPY ---\n");
	src = "Bonjour bonjour";
	printf("orig : src[%s], dest[%s]\n", src, strcpy(dest, src));
	printf("mine : src[%s], dest[%s]\n", src, ft_strcpy(dest2, src));
	src = "";
	printf("orig : src[%s], dest[%s]\n", src, strcpy(dest, src));
	printf("mine : src[%s], dest[%s]\n", src, ft_strcpy(dest2, src));
	printf("\n");
}

int	main(void)
{
	test_strlen();
	test_strcmp();
	test_strcpy();
	return (0);
}
