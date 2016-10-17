/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:22:00 by qdupless          #+#    #+#             */
/*   Updated: 2016/08/02 17:22:02 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		ft_printf_wint_t(va_list ap, const char *format, t_list_printf *list)
{
	list->c_wt = va_arg(ap, wint_t);
	ft_putwchar((wchar_t)(list->c_wt));
	return (1);
}*/

void	ft_parse_plus(const char *format, t_list_printf *list)
{
	if (list->tab_c)
		list->k -= ft_strlen(list->tab_c);
	else if (list->str)
		list->k -= ft_strlen(list->str);
	else if (list->str == NULL)
		list->k -= 6;
	if (list->k >= 0)
	{
		while (list->k != 0)
		{
			if (list->k == 1 && format[list->j] == '+')
			{
				ft_putchar('+');
				list->ret++;
			}
			else
			{
				ft_putchar(' ');
				list->ret++;
			}
			list->k--;
		}
	}
}

int		ft_printf_ul(va_list ap, const char *format, t_list_printf *list)
{
	list->val = va_arg(ap, long);
	list->tab_c = ft_convert_base_ul((unsigned long)(list->val), 10);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (list->val == 0)
	{
		ft_putchar('0');
		list->ret++;
	}
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_long(va_list ap, const char *format, t_list_printf *list)
{
	list->ud = va_arg(ap, long);
	list->tab_c = ft_convert_base_l(list->ud, 10);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (list->val == 0)
	{
		ft_putchar('0');
		list->ret++;
	}
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_point(va_list ap, t_list_printf *list)
{
	void	*ptr;

	ptr = va_arg(ap, void*);
	list->tab_c = ft_convert_base_uintmax_t((uintmax_t)ptr, 16);
	ft_putstr("0x");
	list->ret += 2;
	
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_hexa_maj(va_list ap, const char *format, t_list_printf *list)
{
	list->val = va_arg(ap, unsigned int);
	list->tab_c = ft_convert_base_maj(list->val, 16);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (format[list->j] == '0')
	{
		list->k -= ft_strlen(list->tab_c);
		if (list->k >= 0)
		{
			while (list->k != 0)
			{
				ft_putchar('0');
				list->ret++;
				list->k--;
			}
		}
	}
	if (list->val == 0)
	{
		ft_putchar('0');
		list->ret++;
	}
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_hexa(va_list ap, const char *format, t_list_printf *list)
{
	list->num = va_arg(ap, int);
	list->tab_c = ft_convert_base_un((unsigned int)(list->num), 16);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (format[list->j] == '0')
	{
		list->k -= ft_strlen(list->tab_c);
		if (list->k >= 0)
		{
			while (list->k != 0)
			{
				ft_putchar('0');
				list->ret++;
				list->k--;
			}
		}
	}
	if (list->num == 0)
	{
		ft_putchar('0');
		list->ret++;
	}
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_ud(va_list ap, const char *format, t_list_printf *list)
{
	list->ud = va_arg(ap, int);
	list->tab_c = ft_convert_base_un((unsigned int)(list->ud), 10);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (list->ud == 0)
	{
		ft_putchar('0');
		list->ret++;
	}
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

long 	ft_printf_octa_l(va_list ap, const char *format, t_list_printf *list)
{
	list->val = va_arg(ap, long);
	list->tab_c = ft_convert_base_ul((unsigned long)(list->val), 8);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (list->val == 0)
	{
		ft_putchar('0');
		list->ret++;
	}
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_octa(va_list ap, const char *format, t_list_printf *list)
{
	list->num = va_arg(ap, int);
	list->tab_c = ft_convert_base_un((unsigned int)(list->num), 8);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (format[list->j] == '0')
	{
		list->k -= ft_strlen(list->tab_c);
		if (list->k >= 0)
		{
			while (list->k != 0)
			{
				ft_putchar('0');
				list->ret++;
				list->k--;
			}
		}
	}
	if (list->num == 0)
	{
		ft_putchar('0');
		list->ret++;
	}
	ft_putstr_end(list->tab_c, ft_strlen(list->tab_c) - 1);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_char(va_list ap, const char *format, t_list_printf *list)
{
	list->c = va_arg(ap, int);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
	{
		list->k--;
		ft_parse_plus(format, list);
	}
	ft_putchar((unsigned char)(list->c));
	return (1);
}

int		ft_printf_num(va_list ap, const char *format, t_list_printf *list)
{
	list->num = va_arg(ap, int);
	list->tab_c = ft_itoa_printf(list->num);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (format[list->j] == '0')
	{
		list->k -= ft_strlen(list->tab_c);
		if (list->k >= 0)
		{
			while (list->k != 0)
			{
				ft_putchar('0');
				list->ret++;
				list->k--;
			}
		}
	}
	if (list->num == 0)
	{
		ft_putchar('0');
		list->ret++;
	}
	ft_putstr(list->tab_c);
	return (ft_strlen(list->tab_c));
}

int		ft_printf_put(va_list ap, const char *format, t_list_printf *list)
{
	list->str = va_arg(ap, char*);
	if (format[list->j] == '+' || format[list->j] == ' ' || \
		(format[list->j] >= '1' && format[list->j] <= '9'))
		ft_parse_plus(format, list);
	if (list->str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(list->str);
	return (ft_strlen(list->str));
}

void	ft_parse_m(t_list_printf *list)
{
	/*if (format[list->i] == 'd' || format[list->i + 1] == 'i')
		list->ret = list->ret + ft_printf_num(ap, format, list);
	else if (format[list->i] == 'o')
		list->ret = list->ret + ft_printf_octa(ap, format, list);
	else if (format[list->i] == 'u')
		list->ret = list->ret + ft_printf_ud(ap, format, list);
	else if (format[list->i] == 'x')
		list->ret = list->ret + ft_printf_hexa(ap, format, list);
	else if (format[list->i] == 'X')
		list->ret = list->ret + ft_printf_hexa_maj(ap, format, list);*/
	if (list->tab_c)
		list->k -= ft_strlen(list->tab_c);
	else if (list->str)
		list->k -= ft_strlen(list->str);
	if (list->k >= 0)
	{
		while (list->k != 0)
		{
			ft_putchar(' ');
			list->ret++;
			list->k--;
		}
	}
}

void		ft_fl_tab(const char *format, t_list_printf *list)
{
	list->j = list->i;
	while (format[list->j] != ' ' && format[list->j] != '\0' && format[list->j] != '\n')
	{
		list->size++;
		list->j++;
	}
	list->fl = (char*)malloc(sizeof(list->size + 1));
	list->j = list->i;
	list->size = 0;
	while (format[list->j] != ' ' && format[list->j] != '\0' && format[list->j] != '\n')
	{
		list->fl[list->size] = format[list->j];
		list->j++;
		list->size++;
	}
	list->fl[list->size] = '\0';	
}

void	ft_parse_diez(t_list_printf *list)
{
	if (ft_strchr(list->fl, 'o'))
	{
		ft_putchar('0');
		list->ret++;
	}
	else if (ft_strchr(list->fl, 'x'))
	{
		ft_putstr("0x");
		list->ret += 2;
	}
	else if (ft_strchr(list->fl, 'X'))
	{
		ft_putstr("0X");
		list->ret += 2;
	}
}

void	ft_parse(va_list ap, const char *format, t_list_printf *list)
{
	while (format[list->i])
	{
		if (format[list->i] == '%' && format[list->i + 1] == '%')
		{
			ft_putchar('%');
			list->ret++;
			list->i++;
		}	
		if (format[list->i] == '%' && format[list->i + 1] != '\0')
		{
			ft_fl_tab(format, list);
			if (format[list->i + 1] == '+' || format[list->i + 1] == ' ' || (format[list->i + 1]\
				>= '1' && format[list->i + 1] <= '9'))
			{
				list->j = list->i + 1;
				if (format[list->j] == ' ' || format[list->j] == '+')
					list->i++;
				while(format[list->i + 1] >= '0' && format[list->i + 1] <= '9')
				{
					list->k = (list->k * 10) + format[list->i + 1] - 48;
					list->i++;
				}
			}
			if (format[list->i + 1] == '-')
			{
				list->i++;
				list->j = list->i;
				while (format[list->i + 1] >= '0' && format[list->i + 1] <= '9')
				{
					list->k = (list->k * 10) + format[list->i + 1] - 48;
					list->i++;
				}
				if (ft_strchr(list->fl, '#') && ft_strchr(list->fl, '-'))
				{
					if (list->fl[ft_strlen(list->fl) - 1] == 'o')
						list->k--;
					else
						list->k -= 2;
				}
			}
			if (format[list->i + 1] == '#')
			{
				ft_parse_diez(list);
				list->i++;
			}
			if (format[list->i + 1] == '.')
			{
				ft_parse_p(ap, format, list);
				list->i++;
			}
			if (format[list->i + 1] == '0')
			{
				list->i++;
				list->j = list->i;
				while (format[list->i + 1] >= '0' && format[list->i + 1] <= '9')
				{
					list->k = (list->k * 10) + format[list->i + 1] - 48;
					list->i++;
				}
				if (ft_strchr(list->fl, '#') && ft_strchr(list->fl, '0'))
				{
					if (list->fl[ft_strlen(list->fl) - 1] == 'o')
						list->k--;
					else
						list->k -= 2;
				}
			}
			if (format[list->i + 1] == 's')
				list->ret += ft_printf_put(ap, format, list);
			else if (format[list->i + 1] == 'd' || format[list->i + 1] == 'i')
				list->ret += ft_printf_num(ap, format, list);
			else if (format[list->i + 1] == 'D')
				list->ret += ft_printf_long(ap, format, list);
			else if (format[list->i + 1] == 'c')
				list->ret += ft_printf_char(ap, format, list);
			/*else if (format[list->i + 1] == 'C')
				list->ret = ft_printf_wint_t(ap, format, list);*/
			else if (format[list->i + 1] == 'o')
				list->ret += ft_printf_octa(ap, format, list);
			else if (format[list->i + 1] == 'O')
				list->ret += ft_printf_octa_l(ap, format, list);
			else if (format[list->i + 1] == 'u')
				list->ret += ft_printf_ud(ap, format, list);
			else if (format[list->i + 1] == 'U')
				list->ret += ft_printf_ul(ap, format, list);
			else if (format[list->i + 1] == 'x')
				list->ret += ft_printf_hexa(ap, format, list);
			else if (format[list->i + 1] == 'X')
				list->ret += ft_printf_hexa_maj(ap, format, list);
			else if (format[list->i + 1] == 'p')
				list->ret += ft_printf_point(ap, list);
			if (ft_strchr(list->fl, '-'))
			{
				ft_parse_m(list);
				list->ret++;
			}
			list->i++;
		}
		else if (format[list->i] != '%')
		{
			list->ret++;
			ft_putchar(format[list->i]);
		}
		list->i++;
	}
	/*ft_putstr("-------------------\n");
	ft_putstr(list->fl);
	ft_putstr("\n-------------------");*/
}

int		ft_printf(const char *format, ...)
{
	t_list_printf	*list;
	va_list			ap;

	list = NULL;
	list = ft_memalloc(sizeof(t_list_printf));
	list->ret = 0;
	list->i = 0;
	list->size = 0;
	list->k = 0;
	va_start(ap, format);
	ft_parse(ap, format, list);
	va_end(ap);
	//ft_putnbr(list->ret);
	return (list->ret);
}