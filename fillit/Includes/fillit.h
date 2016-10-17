/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:26:50 by qdupless          #+#    #+#             */
/*   Updated: 2016/01/07 17:54:58 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 546

int		ft_check(int ret, char *buf);
void	ft_grid(char *buf);
void	ft_create_tab(int **str, size_t v);
void	ft_free(char *rst, int *str, int space, size_t i);

#endif
