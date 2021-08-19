/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:24:59 by gatan             #+#    #+#             */
/*   Updated: 2021/05/18 14:32:04 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*new_save(char *save)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(save) - i) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i++;
	while (save[i])
		res[j++] = save[i++];
	free(save);
	return (res);
}

char	*extract_line(char *save)
{
	int		i;
	char	*res;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	return (res);
}

int	gnl_helper(char **buffer, char ***line, char **save, int reader)
{
	free(*buffer);
	**line = extract_line(*save);
	*save = new_save(*save);
	if (reader == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*save;
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (-1);
	while (!n_exists(save) && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		save = join_str(save, buffer);
	}
	if (gnl_helper(&buffer, &line, &save, reader) == 0)
		return (0);
	return (1);
}
