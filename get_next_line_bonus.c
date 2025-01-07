/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalremei <aalremei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:31:39 by aalremei          #+#    #+#             */
/*   Updated: 2025/01/07 13:31:53 by aalremei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*ft_free_store(char **store, int fd)
{
	if (store[fd])
	{
		free(store[fd]);
		store[fd] = NULL;
	}
	return (NULL);
}

char	*ft_read(int fd)
{
	static char		*store[1024];
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	int				r;

	while (1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (ft_free_store(store, fd));
		buf[r] = '\0';
		if (!store[fd])
			store[fd] = ft_strdup("");
		store[fd] = ft_strjoin(store[fd], buf);
		if (ft_find_n(store[fd]) == 1 || (r == 0 && store[fd]))
		{
			line = ft_lineout(store[fd]);
			store[fd] = ft_new_store(store[fd]);
			return (line);
		}
		if (r == 0)
			return (ft_free_store(store, fd));
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
