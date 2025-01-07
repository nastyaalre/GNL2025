/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalremei <aalremei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:31:03 by aalremei          #+#    #+#             */
/*   Updated: 2025/01/07 13:31:21 by aalremei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *store, char *bufr)
{
	int		i;
	int		j;
	int		len;
	char	*p;

	i = 0;
	j = 0;
	if (!store)
		return (bufr);
	if (!bufr)
		return (store);
	len = ft_strlen(store) + ft_strlen(bufr);
	p = (char *)malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (store[i] != '\0')
		p[j++] = store[i++];
	i = 0;
	while (bufr[i] != '\0')
		p[j++] = bufr[i++];
	p[j] = '\0';
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
	int		full_len;
	int		i;
	char	*temp;

	i = 0;
	full_len = ft_strlen(str);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (full_len - i));
	if (!temp)
		return (NULL);
	full_len = 0;
	i++;
	while (str[i])
		temp[full_len++] = str[i++];
	temp[full_len] = '\0';
	free(str);
	return (temp);
}

char	*ft_lineout(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (src == NULL || src[0] == '\0')
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
