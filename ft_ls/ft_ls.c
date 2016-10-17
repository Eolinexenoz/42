#include "ft_ls.h"

int					ft_is_directory(int mode)
{
	if (((mode >> 12) & 15) == 4)
		return (1);
	return (0);
}

static	char		*ft_perm(int mode)
{
	const	char	*perm[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};
	const	char	type[] = {'?', 'p', 'c', '?', 'd', '?', 'b', '?', '-', '?', 'l', '?', 's', '?', 'w', '?'};
	static	char	bits[11];

	ft_memcpy(&bits[0], &type[(mode >> 12) & 15], 1);
	ft_strcpy(&bits[1], perm[(mode >> 6) & 7]);
	ft_strcpy(&bits[4], perm[(mode >> 3) & 7]);
	ft_strcpy(&bits[7], perm[(mode >> 0) & 7]);
	bits[10] = '\0';
	return (bits);
}

static	void		ft_disp_infola(t_ls_list *list)
{
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

static	void		ft_disp_info(t_ls_list *list)
{

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

static	void		ft_disp_ls(t_ls_list *list)
{
	while((list->filer = readdir(list->ope)) != NULL)
	{
		if (list->i == 1)
		{
			ft_putendl(list->tab_tri[list->index]);
			list->index++;
		}
		else if (list->i == 0)
		{
			if (ft_first_c(list->tab_tri[list->index], '.') == NULL)
				ft_putendl(list->tab_tri[list->index]);
			list->index++;
		}
		else if (list->i == 2)
		{
			ft_disp_info(list);
			break ;
		}
		else if (list->i == 3)
		{
			ft_disp_infola(list);
			break ;
		}
	}
}

static	void		ft_putR(t_ls_list *list)
{
	list->h = 4;  
	while (list->tab_tri[list->index])
	{
		if (ft_is_directory(list->info.st_mode))
			list->h = list->index;
		if (ft_first_c(list->tab_tri[list->index], '.') == NULL)
			ft_putstrsp(list->tab_tri[list->index]);
		list->index++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr("./");
	ft_putstr(list->tab_tri[list->h]);
	ft_putchar(':');
	list->avs = list->tab_tri[list->h];
	closedir(list->ope);
	list->ope = opendir(list->avs);
	ft_tri_list(list);
	if (list->tab_tri[list->index])
		ft_putR(list);
}

static	void		ft_check_flag(char *av, t_ls_list *list)
{
	if (ft_strchr(av, 'a') && ft_strchr(av, 'l'))
	{
		list->i = 3;
		ft_disp_ls(list);
	}
	else if (ft_strchr(av, 'a'))
	{
		list->i = 1;
		ft_disp_ls(list);
	}
	else if (ft_strchr(av, 'l'))
	{
		list->i = 2;
		ft_disp_ls(list);
	}
	else if (ft_strchr(av, 'R'))
	{
		list->i = 4;
		ft_putR(list);
	}
	else
		return ;
}

void	ft_tri_list(t_ls_list *list)
{
	char	*tmp;
	int		index2;

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
	index2 = 0;
	while (list->tab_tri[index2 + 1])
	{
		if (list->tab_tri[index2 + 1] != NULL)
		if (ft_strcmp(list->tab_tri[index2], list->tab_tri[index2 + 1]) > 0)
		{
			tmp = list->tab_tri[index2];
			list->tab_tri[index2] = list->tab_tri[index2 + 1];
			list->tab_tri[index2 + 1] = tmp;
			index2 = -1;
		}
		index2++;
	}
	list->index = 0;
	/*if ((list->filer = readdir(list->ope)) != NULL)
		ft_addlst(tri, list->filer->d_name);
	tmp = *tri;
	while ((list->filer = readdir(list->ope)) != NULL)
		ft_addlst(tri, list->filer->d_name);
	tmp3 = tmp;
	while (tmp3 && tmp3->next)
	{
		if (tmp3 && tmp3->next && ft_strcmp(tmp3->name, (tmp3->next->name)) < 0)
		{
			tmp2 = tmp3->next;
			tmp3->next = *tri;
			*tri = tmp2;
		}
		if (tmp3->next)
			tmp3 = tmp3->next;
	}
	*tri = tmp;
	while ((*tri)->next)
	{
		ft_putstr((*tri)->name);
		ft_putchar('\n');
		*tri = (*tri)->next;
	}*/
	list->index = 0;
}

int					main(int ac, char **av)
{
	t_ls_list	*list;
	t_ls 		*tri;

	tri = NULL;
	list = NULL;
	ac = 0;
	list = ft_memalloc(sizeof(t_ls_list));
	list->i = 0;
	list->avs = NULL;
	if (av[1] == 0)
	{
		list->avs = ".";
		list->ope = opendir(list->avs);
		ft_tri_list(list);
		closedir(list->ope);
		list->ope = opendir(list->avs);
		ft_disp_ls(list);
	}
	else if (ft_first_c(av[1], '-') == NULL)
	{
		list->avs = av[1];
		list->ope = opendir(list->avs);
		ft_tri_list(list);
		closedir(list->ope);
		list->ope = opendir(av[1]);
		ft_disp_ls(list);
	}
	else if (ft_first_c(av[1], '-') && av[2])
	{
		list->avs = av[2];
		list->ope = opendir(list->avs);
		ft_tri_list(list);
		closedir(list->ope);
		list->ope = opendir(list->avs);
		ft_check_flag(av[1], list);
	}
	else if (ft_first_c(av[1], '-') && av[2] == NULL)
	{
		list->avs = ".";
		list->ope = opendir(list->avs);
		ft_tri_list(list);
		closedir(list->ope);
		list->ope = opendir(list->avs);
		ft_check_flag(av[1], list);
	}
	//if (list != NULL)
		//free(list);
	if (list->ope == NULL)
		exit(1);
	if (closedir(list->ope) == -1)
		exit(-1);
	return (0);
}