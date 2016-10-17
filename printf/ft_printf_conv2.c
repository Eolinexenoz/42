/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:21:22 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/30 16:21:23 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_u(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->max = (unsigned int)va_arg(ap, int);
	list->tab_c = ft_convert_base_uintmax_t(list->max, 10);
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k > 0)
			ft_parse_sp(list);
	if (list->prec > ft_strlen(list->tab_c))
		ft_prec(list);	
	//ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	ft_putstr(list->tab_c);
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
	return (ft_strlen(list->tab_c));
}

int 	ft_printf_lo(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->max = (unsigned long)va_arg(ap, int);
	list->tab_c = ft_convert_base_uintmax_t(list->max, 8);
	if (ft_strchr(list->fl_opt, '#') && list->max != 0)
		list->k--;
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k > 0)
			ft_parse_sp(list);
	if (list->prec > ft_strlen(list->tab_c))
		ft_prec(list);
	if (ft_strchr(list->fl_opt, '#') && list->max != 0)
		ft_parse_diez(list);
	//ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	ft_putstr(list->tab_c);
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_o(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->max = (unsigned int)va_arg(ap, int);
	list->tab_c = ft_convert_base_uintmax_t(list->max, 8);
	if (ft_strchr(list->fl_opt, '#') && list->max != 0)
		list->k--;
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k > 0)
			ft_parse_sp(list);
	if (list->prec > ft_strlen(list->tab_c))
		ft_prec(list);
	if (ft_strchr(list->fl_opt, '#') && list->max != 0)
		ft_parse_diez(list);
	//ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	ft_putstr(list->tab_c);
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_char(va_list ap, t_list_printf *list)
{
	list->c = va_arg(ap, int);
	if (list->k > 0)
		list->k--;
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k > 0)
			ft_parse_sp(list);
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (!(list->c))
	{
		ft_putchar(0);
		return (1);
	}
	ft_putchar((unsigned char)(list->c));
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
	return (1);
}

int		ft_printf_di(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->max = va_arg(ap, int);
	list->tab_c = ft_ultoabase(list->max, 10);
	if (!(ft_strchr(list->fl_opt, '-')) && (!(ft_strchr(list->fl_opt, '0'))))
		if (list->k > 0)
			ft_parse_sp(list);
	if (list->max < 0)
	{
		ft_putchar('-');
		list->ret++;
	}
	if (ft_strchr(list->fl_opt, '+') && list->max >= 0)
		ft_parse_more(list);
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (list->prec > ft_strlen(list->tab_c))
		ft_prec(list);
	if (ft_strchr(list->fl_opt, ' ') && (!(ft_strchr(list->fl_opt, '+')) \
		 && list->prec == 0 && !(ft_strchr(list->fl_opt, '0')) && \
		 list->max >= 0))
		ft_parse_space(list);
	ft_putstr(list->tab_c);
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
	return (ft_strlen(list->tab_c));
}
