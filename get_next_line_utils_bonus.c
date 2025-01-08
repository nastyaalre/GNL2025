/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalremei <aalremei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:32:41 by aalremei          #+#    #+#             */
/*   Updated: 2025/01/07 13:33:20 by aalremei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *store, char *bufr)
{
	int		sa;
	int		sb;
	int		len;
	char	*p;

	sa = 0;
	sb = 0;
	if (!store)
		return (bufr);
	if (!bufr)
		return (store);
	len = ft_strlen(store) + ft_strlen(bufr);
	p = (char *)malloc(len * sizeof(char) + 1);
	if (!p)
		return (0);
	while (store[sa] != '\0')
		p[sb++] = store[sa++];
	sa = 0;
	while (bufr[sa] != '\0')
		p[sb++] = bufr[sa++];
	p[sb] = '\0';
	free (store);
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != 0)
		count ++;
	return (count);
}

int	ft_find_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_new_store(char *str)
{
	int		i;
	int		s;
	char	*temp;

	s = 0;
	i = ft_strlen(str);
	while (str[s] != '\n' && str[s])
		s++;
	if (str[s] == '\0')
	{
		free(str);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (i - s));
	if (!temp)
		return (NULL);
	i = 0;
	s++;
	while (str[s])
		temp[i++] = str[s++];
	temp[i] = '\0';
	free(str);
	return (temp);
}

char	*ft_lineout(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (src[0] == '\0')
		return (NULL);
	while (src[i] != '\n' && src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1 + (src[i] == '\n')));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '\n')
		{
			dest[i] = src[i];
			dest[i + 1] = '\0';
			return (dest);
		}
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
