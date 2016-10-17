/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:27:31 by qdupless          #+#    #+#             */
/*   Updated: 2016/01/08 16:51:08 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fillit.h"
#include "Includes/libft.h"

static	void	ft_test(char *rst, int *str, int space, size_t i)
{
	int		index;
	int		div;

	index = 0;
	div = 0;
	rst[i] = str[4] + 65;
	index++;
	while (index < 4)
	{
		div = str[index] / 4;
		rst[str[index] + i + (div * space)] = str[4] + 65;
		index++;
	}
}

static	int		ft_position(int *str, char *rst, int space, size_t i)
{
	int		index;
	int		div;

	div = 0;
	index = 0;
	if (rst[i] != '.')
		return (0);
	index++;
	while (index < 4)
	{
		div = str[index] / 4;
		if (rst[str[index] + i + (div * space)] != '.')
			return (0);
		index++;
	}
	return (1);
}

static	int		ft_solver(char *rst, int **str, int space, int k)
{
	size_t	success;
	size_t	i;

	i = 0;
	success = 0;
	if (str[k])
	{
		while (rst[i])
		{
			if (ft_position(str[k], rst, space, i))
			{
				ft_test(rst, str[k], space, i);
				success = ft_solver(rst, str, space, k + 1);
				if (success == 1)
					return (1);
				ft_free(rst, str[k], space, i);
			}
			i++;
		}
		return (0);
	}
	return (1);
}

static	char	*ft_cre_new_tab(size_t i, char *rst)
{
	size_t	size;
	size_t	k;
	size_t	j;

	j = 0;
	k = 0;
	size = (i * (i + 1)) + 1;
	if (!(rst = ft_strnew(size)))
		return (NULL);
	rst[0] = '.';
	while (k < size)
	{
		if (j == i)
		{
			rst[k++] = '\n';
			j = 0;
		}
		else
		{
			rst[k++] = '.';
			j++;
		}
	}
	rst[size - 1] = '\0';
	return (rst);
}

void			ft_create_tab(int **str, size_t v)
{
	size_t	i;
	int		success;
	char	*rst;
	int		space;

	space = 0;
	rst = NULL;
	success = 0;
	i = 2;
	while (v * 4 > (i * i))
		i++;
	while (success == 0)
	{
		space = i - 4;
		rst = ft_cre_new_tab(i, rst);
		success = ft_solver(rst, str, space, 0);
		if (success == 0)
		{
			free(rst);
			i++;
		}
		if (success == 1)
			ft_putstr(rst);
	}
}
