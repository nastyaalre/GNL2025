/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalremei <aalremei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:30:15 by aalremei          #+#    #+#             */
/*   Updated: 2025/01/07 13:30:25 by aalremei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *store, char *bufr);
char	*ft_lineout(char *src);
char	*ft_new_store(char *str);
int		ft_find_n(char *str);

#endif
