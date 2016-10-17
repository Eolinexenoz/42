/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:21:41 by qdupless          #+#    #+#             */
/*   Updated: 2016/08/02 17:21:42 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct  	s_list_printf
{
	va_list ap;
	void			*ptr;
	unsigned int	ud;
	long			val;
	//wint_t			c_wt;
	int				i;
	int				j;
	int				k;
	int				l;	
	int				prec;
	int				mod;
	int				size;
	int				ret;
	int				num;
	int				ps;
	int				b;
	char			has_mod;
	int				*tab;
	short int		shor;
	intmax_t		max;
	char			*fl_size;
	char			c;
	char			*fl_opt;
	char			*fl;
	char			*str;
	char			*tab_c;
}					t_list_printf;

int		ft_printf(const char *format, ...);
void	ft_printf_solve(va_list ap, t_list_printf *list);
int		ft_printf_u(va_list ap, t_list_printf *list);
int		ft_printf_ld(va_list ap, t_list_printf *list);
int		ft_printf_p(va_list ap, t_list_printf *list);
int		ft_printf_lx(va_list ap, t_list_printf *list);
int		ft_printf_x(va_list ap, t_list_printf *list);
int		ft_printf_lu(va_list ap, t_list_printf *list);
int	 	ft_printf_lo(va_list ap, t_list_printf *list);
int		ft_printf_o(va_list ap, t_list_printf *list);
int		ft_printf_char(va_list ap, t_list_printf *list);
int		ft_printf_di(va_list ap, t_list_printf *list);
int		ft_printf_s(va_list ap, t_list_printf *list);
int		ft_printf_s2(t_list_printf *list);
void	ft_parse_0(t_list_printf *list);
void	ft_parse_less(t_list_printf *list);
void	ft_parse_diez(t_list_printf *list);
void	ft_parse_special(t_list_printf *list);
void	ft_parse_sp(t_list_printf *list);
void	ft_printf_solve2(t_list_printf *list);
void	ft_parse_sp_s(t_list_printf *list);
void	ft_parse_more(t_list_printf *list);
void	ft_prec(t_list_printf *list);
void	ft_parse_space(t_list_printf *list);
int		ft_printf_percent(t_list_printf *list);
void	ft_get_modif(va_list ap, t_list_printf *list);