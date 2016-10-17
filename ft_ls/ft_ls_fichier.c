#include "ft_ls.h"

void	ft_disp(t_ls_list *list)
{
	while (list->tab_tri[list->index] != NULL)
	{
		if (ft_first_c(list->tab_tri[list->index], '.') == NULL)
			ft_putendl(list->tab_tri[list->index]);
		list->index++;
	}
}

void	ft_disp_a(t_ls_list *list)
{
	while (list->tab_tri[list->index] != NULL)
	{
		ft_putendl(list->tab_tri[list->index]);
		list->index++;
	}
}

char	*ft_perm(int	mode)
{
	const	char	*perm[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};
	const	char	type[] = {'?', 'p', 'c', '?', 'd', '?', 'b', '?', '-', '?', 'l', '?', 's', '?', 'w', '?'};
	static	char	bits[11];

	ft_memcpy(&bits[0], &type[(mode >> 12) & 15], 1);
	ft_strcpy(&bits[1], perm[(mode >> 6) & 7]);
	if (mode & S_ISUID)
		bits[3] = mode & S_IXUSR ? 's' : 'S';
	ft_strcpy(&bits[4], perm[(mode >> 3) & 7]);
	ft_strcpy(&bits[7], perm[(mode >> 0) & 7]);
	bits[10] = '\0';
	return (bits);	
}

void	ft_disp_info(t_ls_list *list)
{
	while (list->tab_tri[list->index])
	{
		if (ft_first_c(list->tab_tri[list->index], '.') == NULL)
		{
			list->j = lstat(list->tab_tri[list->index], &list->info);
			list->h += list->info.st_blocks;
		}
		list->index++;		
	}
	list->index = 0;
	ft_putstrsp("total");
	ft_putnbr(list->h);
	ft_putchar('\n');
	while (list->tab_tri[list->index])
	{
		list->j = lstat(list->tab_tri[list->index], &list->info);		
		if (ft_first_c(list->tab_tri[list->index], '.') == NULL)
		{
			ft_putstrsp(ft_perm(list->info.st_mode));
			list->l = ft_strdup(getpwuid(list->info.st_uid)->pw_name);
			list->lsb = ft_strdup(getgrgid(list->info.st_gid)->gr_name);
			ft_putnbr(list->info.st_nlink);
			ft_putchar(' ');
			ft_putstrsp(list->l);
			ft_putstrsp(list->lsb);
			ft_putnbr(list->info.st_size);
			ft_putchar(' ');
			list->lasb = ctime(&list->info.st_mtime);
			list->lasb = ft_strsub(list->lasb, 4, 12);
			ft_putstrsp(list->lasb);
			ft_putendl(list->tab_tri[list->index]);
		}
		list->index++;
	}
}

void	ft_disp_info_la(t_ls_list *list)
{
	while (list->tab_tri[list->index])
	{
		list->j = lstat(list->tab_tri[list->index], &list->info);
		list->h += list->info.st_blocks;
		list->index++;
	}
	list->index = 0;
	ft_putstrsp("total");
	ft_putnbr(list->h);
	ft_putchar('\n');
	while (list->tab_tri[list->index])
	{
		list->j = lstat(list->tab_tri[list->index], &list->info);
		ft_putstrsp(ft_perm(list->info.st_mode));
		list->l = ft_strdup(getpwuid(list->info.st_uid)->pw_name);
		list->lsb = ft_strdup(getgrgid(list->info.st_gid)->gr_name);
		ft_putnbr(list->info.st_nlink);
		ft_putchar(' ');
		ft_putstrsp(list->l);
		ft_putstrsp(list->lsb);
		ft_putnbr(list->info.st_size);
		ft_putchar(' ');
		list->lasb = ctime(&list->info.st_mtime);
		list->lasb = ft_strsub(list->lasb, 4, 12);
		ft_putstrsp(list->lasb);
		ft_putendl(list->tab_tri[list->index]);
		list->index++;
	}
}

void	ft_tri_ti(t_ls_list *list)
{
	while (list->tab_tri[list->index2 + 1])
	{
		list->j = lstat(list->tab_tri[list->index2], &list->info);
		list->k = lstat(list->tab_tri[list->index2 + 1], &list->info2);
		if (list->info.st_ctime > list->info2.st_ctime)
		{
			list->tmp = list->tab_tri[list->index2];
			list->tab_tri[list->index2] = list->tab_tri[list->index2 + 1];
			list->tab_tri[list->index2 + 1] = list->tmp;
			list->index2 = -1;
		}
		list->index2++;
	}
	list->index = 0;
}

void	ft_tri_t(t_ls_list *list)
{
	while (list->tab_tri[list->index2 + 1])
	{
		list->j = lstat(list->tab_tri[list->index2], &list->info);
		list->k = lstat(list->tab_tri[list->index2 + 1], &list->info2);
		if (list->info.st_ctime < list->info2.st_ctime)
		{
			list->tmp = list->tab_tri[list->index2];
			list->tab_tri[list->index2] = list->tab_tri[list->index2 + 1];
			list->tab_tri[list->index2 + 1] = list->tmp;
			list->index2 = -1;
		}
		list->index2++;
	}
	list->index = 0;
}

void	ft_tri_i(t_ls_list *list)
{
	while (list->tab_tri[list->index2 + 1])
	{
		if (list->tab_tri[list->index2 + 1] != NULL)
		if (ft_strcmp(list->tab_tri[list->index2], list->tab_tri[list->index2 + 1]) < 0)
		{
			list->tmp = list->tab_tri[list->index2];
			list->tab_tri[list->index2] = list->tab_tri[list->index2 + 1];
			list->tab_tri[list->index2 + 1] = list->tmp;
			list->index2 = -1;
		}
		list->index2++;
	}
	list->index = 0;
}

void	ft_tri_n(t_ls_list *list)
{
	while (list->tab_tri[list->index2 + 1])
	{
		if (list->tab_tri[list->index2 + 1] != NULL)
		if (ft_strcmp(list->tab_tri[list->index2], list->tab_tri[list->index2 + 1]) > 0)
		{
			list->tmp = list->tab_tri[list->index2];
			list->tab_tri[list->index2] = list->tab_tri[list->index2 + 1];
			list->tab_tri[list->index2 + 1] = list->tmp;
			list->index2 = -1;
		}
		list->index2++;
	}
	list->index = 0;
}

void	ft_create_tab(t_ls_list *list)
{
	list->ope = opendir(list->avs);
	while ((list->filer = readdir(list->ope)) != NULL)
		list->index++;
	list->tab_tri = (char**)malloc(sizeof(char*) * list->index + 1);
	list->index = 0;
	closedir(list->ope);
	list->ope = opendir(list->avs);
	while ((list->filer = readdir(list->ope)) != NULL)
	{
		list->tab_tri[list->index] = (char*)malloc(sizeof(char) * ft_strlen(list->filer->d_name) + 1);
		list->tab_tri[list->index] = list->filer->d_name;
		list->index++;
	}
	list->tab_tri[list->index] = 0;
	list->index2 = 0;
}

void	ft_parse(t_ls_list *list)
{
	ft_create_tab(list);
	if (list->avs2 && ft_strchr(list->avs2, 't'))
	{
		if (ft_strchr(list->avs2, 'r'))
			ft_tri_ti(list);
		else
			ft_tri_t(list);
	}	
	else if (list->avs2 && ft_strchr(list->avs2, 'r'))
		ft_tri_i(list);
	else
		ft_tri_n(list);
	if (list->avs2 && ft_strchr(list->avs2, 'l'))
	{
		if (ft_strchr(list->avs2, 'a'))
			ft_disp_info_la(list);
		else
			ft_disp_info(list);
	}
	else if (list->avs2 && ft_strchr(list->avs2, 'a'))
		ft_disp_a(list);
}

int		main(int ac, char **av)
{
	t_ls_list	*list;
	t_ls 		*tri;

	tri = NULL;
	list = NULL;
	list = ft_memalloc(sizeof(t_ls_list));	
	list->index = 0;
	list->index2 = 0;
	list->h = 0;
	if (ac > 0)
	{
		if (av[1] == 0)
		{
			list->avs = ".";
		}
		else if (ft_first_c(av[1], '-') == NULL)
		{
			list->avs = av[1];
		}
		else if (ft_first_c(av[1], '-') && av[2])
		{
			list->avs2 = av[1];
			list->avs = av[2];
		}
		else if (ft_first_c(av[1], '-') && av[2] == NULL)
		{
			list->avs = ".";
			list->avs2 = av[1];
		}
		ft_parse(list);
	}
	ft_disp(list);
	free(list->tab_tri);
	free(list);
}