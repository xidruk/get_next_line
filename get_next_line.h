#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

char    *get_next_line(int fd);
size_t get_length(const char *string);
char *join_strings(char *s1,  char *s2);
char *c_search(const char *s_in_str, int c);
char *duplicate_string(const char *or_str);

#endif