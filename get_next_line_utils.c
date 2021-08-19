/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:35:04 by gatan             #+#    #+#             */
/*   Updated: 2021/05/12 16:36:50 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	strlen;

	if (!s)
		return (0);
	strlen = 0;
	while (s[strlen])
		strlen++;
	return (strlen);
}

int	n_exists(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = NULL;
	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest_mod;
	const unsigned char	*src_mod;

	dest_mod = dst;
	src_mod = src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		dest_mod += len;
		src_mod += len;
		while (len--)
			*--dest_mod = *--src_mod;
	}
	else
	{
		while (len--)
			*dest_mod++ = *src_mod++;
	}
	return (dst);
}

char	*join_str(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memmove(res, s1, s1_len);
	ft_memmove(res + s1_len, s2, s2_len);
	free((char *)s1);
	return (res);
}
