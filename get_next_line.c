/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:48:17 by afournie          #+#    #+#             */
/*   Updated: 2025/11/19 14:39:52 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_new_line(const char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\n';
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*ligne;
	int			i;

	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	stash = malloc(BUFFER_SIZE + 1);
	while (!ft_find_break(stash) && (i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (i == -1)
			break ;
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	ligne = malloc(sizeof(char) * ft_strlen(stash + 1));
	if (!ligne)
		return (NULL);
	ft_new_line(stash, ligne);
	printf("stash : %s", stash);
	return (ligne);
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture");
		return (0);
	}
	res = get_next_line(fd);
	printf("\nget_next_line : %s", res);
}
