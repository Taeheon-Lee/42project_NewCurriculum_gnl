/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 02:36:59 by tlee              #+#    #+#             */
/*   Updated: 2020/04/17 22:25:43 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcut(char *str, char c)
{
	char	*rtnstr;
	size_t	str_len;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	str_len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == c)
		{
			i += 1;
			if (!(rtnstr = ft_strnew(str_len - i)))
				return (NULL);
			rtnstr = ft_strcpy(rtnstr, &(str[i]));
			free(str);
			return (rtnstr);
		}
		i++;
	}
	free(str);
	return (ft_strnew(0));
}

int		warehouse(int fd, char **wh)
{
	int		cnt;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	if (read(fd, buff, 0) < 0)
		return (-1);
	while ((cnt = read(fd, buff, BUFF_SIZE)))
	{
		buff[cnt] = '\0';
		if (!(*wh))
			*wh = ft_strdup(buff);
		else
		{
			temp = *wh;
			*wh = ft_strjoin(*wh, buff);
			free(temp);
		}
		if (ft_strchr(*wh, '\n'))
			break ;
	}
	return (cnt);
}

int		get_next_line(const int fd, char **line)
{
	static char	**wh = NULL;
	int			i;
	int			cnt;

	i = 0;
	if (!wh)
		wh = (char **)malloc(sizeof(char *) * 590432);
	if (fd < 0 || !line || (cnt = warehouse(fd, &(wh[fd]))) < 0)
		return (-1);
	while (wh[fd][i] != '\0' && wh[fd][i] != '\n')
		i++;
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, wh[fd], i);
	if (*(wh[fd]) || (**line && *line))
	{
		wh[fd] = ft_strcut(wh[fd], '\n');
		return (1);
	}
	return (cnt);
}
