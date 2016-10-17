/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:32:37 by qdupless          #+#    #+#             */
/*   Updated: 2016/01/13 19:57:57 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_lenbbn(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	return (i);
}

static	int		ft_check(int ret, char **line, char **str)
{
	if (ret < 0)
		return (-1);
	else if (str != 0 && ret == 0)
	{
		*line = ft_strdup(*str);
		if (**str == 0)
			return (0);
		*str = 0;
		free(*str);
		return (1);
	}
	else
		return (0);
}

static	int		ft_read(int fd, char **line, char **str, char *buf)
{
	int			ret;
	char		*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			tmp = ft_strsub(buf, 0, ft_lenbbn(buf));
			*line = ft_strjoin(*str, tmp);
			free(tmp);
			tmp = *str;
			*str = ft_strsub(buf, ft_lenbbn(buf) + 1, ft_strlen(buf));
			free(tmp);
			return (1);
		}
		tmp = *str;
		*str = ft_strjoin(*str, buf);
		free(tmp);
	}
	return (ft_check(ret, line, str));
}

void			ft_cppl(char **line, char **str)
{
	char	*tmp;

	*line = ft_strsub(*str, 0, ft_lenbbn(*str));
	tmp = *str;
	*str = ft_strsub(*str, ft_lenbbn(*str) + 1 \
		, ft_strlen(*str) - ft_lenbbn(*str));
	free(tmp);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str;
	char		*buf;

	if (line == NULL)
		return (-1);
	str = (str == NULL) ? ft_memalloc(1) : str;
	buf = ft_memalloc(BUFF_SIZE + 1);
	if (ft_strchr(str, '\n') == NULL)
	{
		if ((ret = ft_read(fd, line, &str, buf)) > 0)
		{
			free(buf);
			return (1);
		}
		*line = ft_strsub(str, 0, ft_strlen(str));
		str = 0;
		free(buf);
		return (ret == 0) ? 0 : -1;
	}
	ft_cppl(line, &str);
	return (1);
}
