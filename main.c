/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalremei <aalremei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:36:00 by aalremei          #+#    #+#             */
/*   Updated: 2025/01/07 13:37:03 by aalremei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int	main(void)
{
	int		fd1, fd2;
	char	*line;

	fd1 = open("/Users/aalremei/Desktop/gnl-main/file.txt", O_RDONLY);
	// fd2 = open("/Users/aalremei/Desktop/gnl-main/file1.txt", O_RDONLY);
	line = get_next_line(fd1);
	// printf("%s", line);
	// free(line);
	// line = NULL;
	// close(fd1);
	// line = get_next_line(fd2);
	// printf("%s", line);
	// free(line);
	// line = NULL;
	// close(fd2);
	// fd1 = open("/Users/aalremei/Desktop/gnl-main/file.txt", O_RDONLY);
	// fd2 = open("/Users/aalremei/Desktop/gnl-main/file1.txt", O_RDONLY);
	// line = get_next_line(fd1);
	// printf("%s", line);
	// line = get_next_line(fd2);
	// printf("%s", line);
	// // line = get_next_line(fd1);
	// // printf("%s", line);
	// // line = get_next_line(fd2);
	// // printf("%s", line);
	// // line = get_next_line(fd1);
	// // printf("%s", line);
	// // line = get_next_line(fd2);
	// // printf("%s", line);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	printf("%s", line);
	close(fd1);
	return (0);
}