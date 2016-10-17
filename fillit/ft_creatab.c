/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:25:47 by qdupless          #+#    #+#             */
/*   Updated: 2016/04/30 21:46:31 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#include "Includes/fillit.h"
#include <stdio.h>

static	int	*ft_change_d(int **grid, int k, char *str, size_t start)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	space;

	i = 0;
	j = 0;
	d = 0;
	grid[k] = (int*)malloc(sizeof(int) * 6);
	while (i < 21)
	{
		if (str[start] == '#' && d != 0)
			grid[k][j++] = i - space;
		if (str[start] == '#' && d == 0)
		{
			grid[k][j++] = 0;
			d++;
			space = i;
		}
		start++;
		i++;
	}
	grid[k][j] = '\0';
	grid[k][4] = k;
	return (grid[k]);
}

void		ft_free(char *rst, int *str, int space, size_t i)
{
	int		index;
	int		div;

	index = 0;
	div = 0;
	rst[i] = 46;
	index++;
	while (index < 4)
	{
		div = str[index] / 4;
		rst[str[index] + i + (div * space)] = 46;
		index++;
	}
}

void		ft_grid(char *buf)
{
	int		**grid;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(buf) / 21 + 1;
	k = 0;
	grid = (int**)malloc(sizeof(int*) * j + 1);
	while (k < j)
	{
		grid[k] = ft_change_d(grid, k, buf, i);
		i = i + 21;
		k++;
	}
	grid[k] = NULL;
	int l = 0;
	while(grid[l] != '\0')
	{
		l++;
	}
	ft_create_tab(grid, j);
}
