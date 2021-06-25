#ifndef TESTER_H
# define TESTER_H
# include "libasm.h"
# include <errno.h>
# include <stdlib.h>
# define CYAN "\033[36m"
# define CYANB "\033[1;36m"
# define WHITE "\033[0m"

void	test_strlen(void);
void	test_strcmp(void);
void	test_strcpy(void);
void	test_write(void);
void	test_read(void);
void	test_strdup(void);
void	test_list_size(void);
void	printt(char *str);
void	printst(char *str);

#endif
