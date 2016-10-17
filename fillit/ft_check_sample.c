/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sample.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:28:25 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/15 17:39:47 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fillit.h"
#include "Includes/libft.h"

static	int		ft_check_valid(char *buf, size_t k, size_t v)
{
	size_t	d;

	d = 0;
	if (buf[k - 5] == '#' && (k - (v * 20) - v) > 5)
		d++;
	if (buf[k + 1] == '#' && (k - (v * 20) - v) < 19)
		d++;
	if (buf[k + 5] == '#' && (k - (v * 20) - v) < 15)
		d++;
	if (buf[k - 1] == '#' && (k - (v * 20) - v) > 0)
		d++;
	return (d);
}

static	int		ft_check_pieces(int ret, char *buf, size_t v, size_t k)
{
	size_t	nb_d;
	size_t	b;

	k = 0;
	nb_d = 0;
	b = v;
	v = 0;
	while (buf[k])
	{
		while (k < (v * 21) + 20)
		{
			if (buf[k] == '#')
				nb_d = nb_d + ft_check_valid(buf, k, v);
			k++;
		}
		k++;
		if ((b - 1) > v)
			v++;
		if (nb_d < 5)
			return (-1);
		nb_d = 0;
	}
	return (ret);
}

static	int		ft_check_collumn(int ret, char *buf)
{
	size_t	k;
	size_t	j;
	size_t	v;

	k = 0;
	j = 0;
	v = 0;
	while (buf[k])
	{
		if (buf[k] == '\n')
			j++;
		k++;
	}
	v = k / 20;
	if (v > 20)
		v--;
	if ((v * 4) + (v - 1) != j)
		return (-1);
	if (buf[k - 2] != '.' && buf[k - 2] != '#')
		return (-1);
	ret = ft_check_pieces(ret, buf, v, k);
	return (ret);
}

static	int		ft_check_line(int ret, char *buf)
{
	size_t	i;
	size_t	k;

	k = 0;
	while (buf[k])
	{
		i = 0;
		while (i < 5)
		{
			while (buf[k] == '.' || buf[k] == '#')
			{
				i++;
				k++;
			}
			if (buf[k] == '\n')
				k++;
			if (i != 4)
				return (-1);
			i++;
		}
		if (buf[k] == '\n')
			k++;
	}
	return (ret);
}

int				ft_check(int ret, char *buf)
{
	size_t	i;
	size_t	j;
	size_t	b;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			j++;
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (-1);
		i++;
	}
	b = i / 20;
	if (b > 20)
		b--;
	if (b > 26)
		return (-1);
	if (j != (b * 4))
		return (-1);
	ret = ft_check_line(ret, buf);
	ret = ft_check_collumn(ret, buf);
	return (ret);
}
