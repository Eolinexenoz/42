/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:22:42 by qdupless          #+#    #+#             */
/*   Updated: 2016/02/12 07:30:23 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fillit.h"
#include "Includes/libft.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	size_t	i;
	char	buf[BUFF_SIZE];

	i = 0;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	ret = ft_check(ret, buf);
	if (ret < 0)
	{
		ft_putendl("error");
		return (0);
	}
	ft_grid(buf);
	close(fd);
	return (0);
}
