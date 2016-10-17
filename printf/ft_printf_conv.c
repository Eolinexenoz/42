/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:19:22 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/30 16:19:24 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_lu(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->max = (unsigned long)va_arg(ap, int);
	list->tab_c = ft_convert_base_uintmax_t(list->max, 10);
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k != 0)
			ft_parse_sp(list);
	if (list->prec > ft_strlen(list->tab_c))
		ft_prec(list);	
	//ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	ft_putstr(list->tab_c);
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_ld(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->max = (long)va_arg(ap, int);
	list->tab_c = ft_convert_base_uintmax_t(list->max, 10);
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_p(va_list ap, t_list_printf *list)
{
	void	*ptr;

	ptr = va_arg(ap, void*);
	list->tab_c = ft_convert_base_uintmax_t((uintmax_t)ptr, 16);
	ft_putstr("0x");
	list->ret += 2;
	//ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	ft_putstr(list->tab_c);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_lx(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->max = (unsigned int)va_arg(ap, int);
	list->tab_c = ft_convert_base_maj(list->max, 16);
	if (ft_strchr(list->fl_opt, '#') && list->max)
		list->k -= 2;	
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k != 0)
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

int		ft_printf_x(va_list ap, t_list_printf *list)
{
	if (list->has_mod == 0)
		list->max = (unsigned int)va_arg(ap, int);
	list->tab_c = ft_convert_base_uintmax_t(list->max, 16);
	if (ft_strchr(list->fl_opt, '#') && list->max != 0)
		list->k -= 2;
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k != 0)
			ft_parse_sp(list);
	if (list->prec > ft_strlen(list->tab_c))
		ft_prec(list);
	if (ft_strchr(list->fl_opt, '#') && list->max != 0)
		ft_parse_diez(list);
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	//ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	ft_putstr(list->tab_c);
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
	return (ft_strlen(list->tab_c));
}
