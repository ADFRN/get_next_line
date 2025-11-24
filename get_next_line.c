/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:48:17 by afournie          #+#    #+#             */
/*   Updated: 2025/11/24 15:22:08 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(stash) - i + 1);
	if (!new_stash)
		return (NULL);
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*ligne;
	int			i;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	while (!ft_find_break(stash))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			break ;
		buffer[i] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	if (!stash || stash[0] == '\0')
		return (NULL);
	ligne = extract_line(stash);
	stash = clean_stash(stash);
	return (ligne);
}
/*
int	main(void)
{
	int		fd;
	char	*res;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < 4)
	{
		res = get_next_line(fd);
		printf("get_next_line : '%s' \n", res);
		i++;
	}
}
*/
