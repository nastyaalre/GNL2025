/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalremei <aalremei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:30:33 by aalremei          #+#    #+#             */
/*   Updated: 2025/01/07 13:30:49 by aalremei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_handle_error(char **store)
{
	if (*store)
	{
		free(*store);
		*store = NULL;
	}
	return (NULL);
}

static char	*ft_read(int fd)
{
	static char		*store;
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	int				r;

	while (1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (ft_handle_error(&store));
		buf[r] = '\0';
		if (!store)
			store = ft_strdup("");
		store = ft_strjoin(store, buf);
		if (ft_find_n(store) == 1 || (r == 0 && store))
		{
			line = ft_lineout(store);
			store = ft_new_store(store);
			return (line);
		}
	}
}

char	*get_next_line(int fd)
{
	char	*line_out;

	line_out = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_out = ft_read(fd);
	return (line_out);
}
