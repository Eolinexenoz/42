/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:04:59 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/20 17:05:01 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_size(t_list_printf *list)
{
	const char	*size = "hjlz";

	list->size = 0;
	list->j = 0;
	list->fl_size = ft_strnew(6);
	while (list->fl[list->j])
	{
		if (ft_strchr(size, list->fl[list->j]))
		{
			if (ft_anco(list->fl_size, list->fl[list->j]) < 2 && \
				(list->fl[list->j] == 'l' || list->fl[list->j] == 'h'))
				list->fl_size[list->size++] = list->fl[list->j];
			else if (!(ft_strchr(list->fl_size, list->fl[list->j])))
				list->fl_size[list->size++] = list->fl[list->j];
		}
		list->j++;
	}
}

void	ft_parse_prec(t_list_printf *list)
{
	list->j = 0;
	while (list->fl[list->j])
	{
		if (list->fl[list->j] == '.')
		{
			list->j++;
			while (ft_isdigit(list->fl[list->j]))
				list->prec = (list->prec * 10) + list->fl[list->j++] - 48;
		}
		list->j++;
	}
}

void	ft_parse_width(t_list_printf *list)
{
	list->j = 0;
	while (list->fl[list->j])
	{
		if (ft_isdigit(list->fl[list->j]) && list->fl[list->j - 1] != '.' && \
			list->j > 0)
			list->k = (list->k * 10) + list->fl[list->j] - 48;
		if (list->fl[list->j] == '.')
			break;
		list->j++;
	}
}

void	ft_parse_opt(t_list_printf *list)
{
	const char *opt = "#0 -+";

	list->fl_opt = ft_strnew(5);
	while (list->fl[list->j])
	{
		if (!(ft_strchr(list->fl_opt, list->fl[list->j])) && ft_strchr(opt, list->fl[list->j]))
		{
			if (list->fl[list->j] == '0')
			{
				if (!(list->fl[list->j - 1] >= '1' && list->fl[list->j - 1] <= '9'))
					list->fl_opt[list->size] = list->fl[list->j];
			}
			else
				list->fl_opt[list->size] = list->fl[list->j];
			list->size++;
		}
		list->j++;
	}
}

void	ft_fl_tab(const char *format, t_list_printf *list)
{
	const char	*str = "disScCoOxXpDuU";

	list->b = 0;
	while (format[list->j])
	{
		if (ft_strchr(str, format[list->j]) || format[list->j + 1] == '%')
		{
			if (format[list->j + 1] == '%')
				list->b = 1;
			list->size++;
			break ;
		}
		list->size++;
		list->j++;
	}
	if (list->b)
		list->size++;
	list->fl = ft_strnew(list->size + 1);
	list->fl = ft_strncpy(list->fl, &format[list->i], list->size);
	list->size = 0;
	list->j = 0;
}

void	ft_parse(va_list ap, const char *format, t_list_printf *list)
{
	while (format[list->i])
	{
		if (format[list->i] == '%')
		{
			list->j = list->i;
			ft_fl_tab(format, list);
			ft_parse_opt(list);
			ft_parse_width(list);
			ft_parse_prec(list);
			ft_parse_size(list);
			ft_printf_solve(ap, list);
		}
		else
		{
			list->ret++;
			ft_putchar(format[list->i]);
		}
		if (format[list->i] == '%')
			list->i += ft_strlen(list->fl);
		else
			list->i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_list_printf	*list;
	va_list			ap;
	int				res;

	list = NULL;
	list = ft_memalloc(sizeof(t_list_printf));
	list->ret = 0;
	list->i = 0;
	list->j = 0;
	list->size = 0;
	list->k = 0;
	list->ps = 0;
	list->prec = 0;
	list->l = 0;
	list->has_mod = 0;
	va_start(ap, format);
	ft_parse(ap, format, list);
	va_end(ap);
	res = list->ret;
	free(list);
	/*//ft_putnbr(list->ret);
	ft_putendl(list->fl);
	//ft_putchar('\n');
	ft_putendl(list->fl_opt);
	ft_putnbr(list->k);
	ft_putchar('\n');
	ft_putnbr(list->prec);
	ft_putchar('\n');
	ft_putstr(list->fl_size);*/
	return (res);
}
