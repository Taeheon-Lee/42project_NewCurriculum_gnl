/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 22:06:14 by tlee              #+#    #+#             */
/*   Updated: 2020/04/17 22:23:02 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	copy = (char*)malloc(sizeof(char) * len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*arr;

	if (!s1 || !s2)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		arr[i] = s2[j];
		++i;
		++j;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)s;
	while (temp[i])
	{
		if (temp[i] == (char)c)
			return (temp + i);
		i++;
	}
	if (c == 0)
		return (temp + i);
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (!arr)
		return (NULL);
	while (i <= size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

char	*ft_strncpy(char *dst, const char *src, size_t num)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		if (i == num)
			return (dst);
		dst[i] = src[i];
		i++;
	}
	while (i < num)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
