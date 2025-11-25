/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:48:17 by afournie          #+#    #+#             */
/*   Updated: 2025/11/25 12:06:36 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_doc(int fd, char *buffer, char *stash)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (!(stash && ft_strchr(stash, '\n')) && read_line > 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (!stash)
			stash = ft_strdup("");
		char_temp = stash;
		stash = ft_strjoin(char_temp, buffer);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*set_line(char *line_buffer)
{
	size_t	count;
	size_t	total_len;
	char	*stash;

	count = 0;
	while (line_buffer[count] != '\n' && line_buffer[count] != '\0')
		count++;
	if (line_buffer[count] == '\0')
		return (NULL);
	total_len = ft_strlen(line_buffer);
	stash = ft_substr(line_buffer, count + 1, total_len - (count + 1));
	if (stash && stash[0] == 0)
	{
		free(stash);
		stash = NULL;
	}
	line_buffer[count + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buffer)
		return (NULL);
	line = read_doc(fd, buffer, stash);
	if (line == NULL)
		free (stash);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = set_line(line);
	return (line);
}
