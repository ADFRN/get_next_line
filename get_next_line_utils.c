/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:48:37 by afournie          #+#    #+#             */
/*   Updated: 2025/11/18 18:12:56 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_break(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strtrim(const char *s1)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*s2;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	i = 0;
	j = s1_len;
	while (ft_find_break(s1[i]))
		i++;
	while (ft_find_break(s1[--j]))
		if (j == 0)
			break ;
	s2_len = (s1_len - i) - (s1_len - j) + 2;
	if (s2_len < 1)
		s2_len = 1;
	s2 = malloc(s2_len);
	if (!s2)
		return (0);
	ft_strlcpy(s2, (char *)&s1[i], s2_len);
	return (s2);
}

