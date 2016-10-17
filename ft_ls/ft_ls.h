#ifndef FT_LS_H
# define FT_LS_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include "Includes/libft/libft.h"

typedef	struct  s_ls_list
{
	struct s_ls_list	*next;
	DIR					*ope;
	struct dirent		*filer;
	struct stat			info;
	struct stat			info2;
	struct timespec		nano;
	long				nanos2;
	long				nanos;
	int					mode;
	int					index;
	int					index2;
	int					j;
	int					i;
	int					h;
	int					k;
	char				*tmp;
	char				*l;
	char				*lsb;
	char				*lasb;
	char				*avs;
	char				*avs2;
	char				**tab_tri;
	unsigned	char	c;		
}				t_ls_list;

typedef	struct 	s_ls
{
	struct s_ls 		*next;
	char				*name;
	int					k;
}				t_ls;

int		main(int ac, char **av);
void	ft_addlst(t_ls **list, char *d_name);
void	ft_tri_list(t_ls_list *list);

#endif