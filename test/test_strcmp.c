#include "tester.h"

void	test_strcmp(void)
{
	char *s;
	char *s2;

	printt("STRCMP");
	printst("strcmp(\"Hello world !\", \"Hell!\")");
	s = "Hello world !";
	s2 = "Hell!";
	errno = 0;
	printf("mine : %d", ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : %d", strcmp(s, s2));
	printf("\terrno = %d\n", errno);

	printst("strcmp(\"H\", \"Hello\")");
	s = "H";
	s2 = "Hello";
	errno = 0;
	printf("mine : %d", ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : %d", strcmp(s, s2));
	printf("\terrno = %d\n", errno);

	printst("strcmp(\"Hello\", \"Hello\")");
	s = "Hello";
	s2 = "Hello";
	errno = 0;
	printf("mine : %d", ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : %d", strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	
	printf("\n");
}
