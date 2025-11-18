/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:48:17 by afournie          #+#    #+#             */
/*   Updated: 2025/11/18 18:20:01 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*stash;
	char	*ligne;
	int		i;

	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	while (!ft_find_break(stash))
	{
		printf("ici");
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			break ;
		printf("la");
		stash = ft_strjoin(stash, buffer);
		printf("%s", stash);
	}
	printf("%s", stash);
	if (i == -1)
		return ("error");
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
	printf("\n ici : %s", res);
}
