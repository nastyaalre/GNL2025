/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalremei <aalremei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:32:09 by aalremei          #+#    #+#             */
/*   Updated: 2025/01/07 13:32:22 by aalremei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *store, char *bufr);
char	*ft_lineout(char *src);
char	*ft_new_store(char *str);
int		ft_find_n(char *str);

#endif