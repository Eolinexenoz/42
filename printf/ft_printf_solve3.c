/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_solve3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:43:02 by qdupless          #+#    #+#             */
/*   Updated: 2016/10/05 12:43:05 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_modif(va_list ap, t_list_printf *list)
{
	list->has_mod = 1;
	if (ft_strchr(list->fl_size, 'j'))
		list->max = (uintmax_t)va_arg(ap, uintmax_t);
	else if (ft_strchr(list->fl_size, 'z'))
		list->max = va_arg(ap, size_t);
	else if (ft_strchr(list->fl_size, 'l') && (ft_anco(list->fl_size, 'l') == 2))
		list->max = (long long int)va_arg(ap, long);
	else if (ft_strchr(list->fl_size, 'l') && (!(ft_anco(list->fl_size, 'l') == 2)))
		list->max = (long int)va_arg(ap, long);
	else if (ft_strchr(list->fl_size, 'h') && (!(ft_anco(list->fl_size, 'h') == 2)))
		list->max = (short int)va_arg(ap, int);
	else if (ft_strchr(list->fl_size, 'h') && (ft_anco(list->fl_size, 'h') == 2))
		list->max = (char)va_arg(ap, int);
	else
	{
		list->has_mod = 0;
		return ;
	}
}
