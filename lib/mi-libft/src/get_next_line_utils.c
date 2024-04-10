/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:53:08 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/24 10:16:16 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(char *str, int c)
{
	int	index;

	if (!str)
		return (NULL);
	index = 0;
	while (str[index])
	{
		if (str[index] == (char) c)
			return ((char *) &str[index]);
		index++;
	}
	return (NULL);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size)
{
	size_t	length;
	size_t	index;

	length = ft_strlen_gnl(src);
	if (size > 0)
	{
		index = 0;
		while (src[index] && index < size - 1)
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (length);
}

char	*ft_strdup_gnl(const char *str)
{
	char	*clone;

	clone = malloc(sizeof(char) * ft_strlen_gnl(str) + 1);
	if (!clone)
		return (NULL);
	ft_strlcpy_gnl(clone, str, ft_strlen_gnl(str) + 1);
	return (clone);
}

char	*ft_strjoin_gnl(char *s1, char const *s2, size_t length)
{
	size_t	length_s1;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	length_s1 = ft_strlen_gnl(s1);
	result = (char *)malloc((length_s1 + length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy_gnl(result, s1, length_s1 + 1);
	ft_strlcpy_gnl((result + length_s1), s2, length + 1);
	free(s1);
	return (result);
}
