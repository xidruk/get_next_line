/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <kbarkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:10:24 by kbarkan           #+#    #+#             */
/*   Updated: 2024/12/08 17:19:34 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE INT_MAX
# endif

char	*get_next_line(int fd);
size_t	get_length(const char *string);
char	*join_strings(char *s1, char *s2);
char	*c_search(const char *s_in_str, int c);
char	*duplicate_string(const char *or_str);

#endif
