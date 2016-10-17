/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:19:42 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/30 16:19:43 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->str = va_arg(ap, char*);
	if (!(ft_strchr(list->fl_opt, '-')))
		if (list->k > 0)
			ft_parse_sp_s(list);
	if (list->str == NULL)
	{
		ft_putstr("(null)");
		if (ft_strchr(list->fl_opt, '-') && list->k != 0)
			ft_parse_less(list);
		return (6);
	}
	list->ret += ft_printf_s2(list);
	return (0);
}

int		ft_printf_s2(t_list_printf *list)
{
	if (list->prec == 0 || list->prec > ft_strlen(list->str))
	{
		ft_putstr(list->str);
		if (ft_strchr(list->fl_opt, '-') && list->k != 0)
			ft_parse_less(list);
	}
	else
	{
		while (list->str && list->l < list->prec)
		{
			ft_putchar(list->str[list->l]);
			list->l++;
		}
		if (ft_strchr(list->fl_opt, '-') && list->k != 0)
			ft_parse_less(list);
		return (list->prec);
	}
	return (ft_strlen(list->str));
}

int		ft_printf_percent(t_list_printf *list)
{
	list->tab_c = ft_strdup("%");
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k != 0)
			ft_parse_sp(list);
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (list->prec > ft_strlen(list->tab_c) && list->prec < list->k)
		ft_prec(list);	
	ft_putchar('%');
	if (ft_strchr(list->fl_opt, '-') && list->k != 0)
		ft_parse_less(list);
	return(1);
}

