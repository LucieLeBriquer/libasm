#include "tester.h"

void	test_write(void)
{
	char	*s;

	printt("WRITE ");
	printst("write(1, s, len(s))");
	s = "Hello world!";
	errno = 0;
	printf("|\tret = %ld", ft_write(1, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|\tret = %ld", write(1, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);

	printst("write on wrong file descriptor");
	errno = 0;
	printf("|ret = %ld", ft_write(4, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|ret = %ld", write(4, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);

	printst("write only a part of the string");
	errno = 0;
	printf("|\t ret = %ld", ft_write(1, s, 4));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|\t ret = %ld", write(1, s, 4));
	printf("\terrno = %d\n", errno);

	printst("overwriting");
	errno = 0;
	printf("|\tret = %ld", ft_write(1, s, 20));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|\tret = %ld", write(1, s, 20));
	printf("\terrno = %d\n", errno);
	printf("\n");
	
	printst("NULL string");
	errno = 0;
	printf("|\tret = %ld", ft_write(1, NULL, 20));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|\tret = %ld", write(1, NULL, 20));
	printf("\terrno = %d\n", errno);
	printf("\n");
}
