#include <dirent.h>
#include "ft_ls.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "Includes/libft/libft.h"

/*static char		*ft_check_d_name(char *av)
{
	char	*tmp;

	if (ft_strchr(av, '/') && av != NULL)
	{
		tmp = ft_strjoin(av, "/");
	}
	else
		tmp = ft_strdup(av);
	return (tmp);	
}*/

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

static	void	ft_disp_infola(struct dirent *filer, DIR *ope)
{
	struct stat		info;
	char			*fuck;
	char			*fuck1;
	char			*fuck2;
	int				j;

	while ((filer = readdir(ope)) != NULL)
	{
		j = lstat(filer->d_name, &info);
		ft_putstrsp(ft_perm(info.st_mode));
		fuck = ft_strdup(getpwuid(info.st_uid)->pw_name);
		fuck1 = ft_strdup(getgrgid(info.st_gid)->gr_name);
		ft_putnbr(info.st_nlink);
		ft_putchar(' ');
		ft_putstrsp(fuck);
		ft_putstrsp(fuck1);
		ft_putnbr(info.st_size);
		ft_putchar(' ');
		fuck2 = ctime(&info.st_mtime);
		fuck2 = ft_strsub(fuck2, 4, 12);
		ft_putstrsp(fuck2);
		ft_putendl(filer->d_name);
	}
}

static	void	ft_disp_info(struct dirent *filer, DIR *ope)
{
	struct stat		info;
	char			*fuck;
	char			*fuck1;
	char			*fuck2;
	int				j;

	while ((filer = readdir(ope)) != NULL)
	{
		j = lstat(filer->d_name, &info);
		if (ft_first_c(filer->d_name, '.') == NULL)
		{
			ft_putstrsp(ft_perm(info.st_mode));
			fuck = ft_strdup(getpwuid(info.st_uid)->pw_name);
			fuck1 = ft_strdup(getgrgid(info.st_gid)->gr_name);
			ft_putnbr(info.st_nlink);
			ft_putchar(' ');
			ft_putstrsp(fuck);
			ft_putstrsp(fuck1);
			ft_putnbr(info.st_size);
			ft_putchar(' ');
			fuck2 = ctime(&info.st_mtime);
			fuck2 = ft_strsub(fuck2, 4, 12);
			ft_putstrsp(fuck2);
			if (ft_first_c(filer->d_name, '.') == NULL)
				ft_putendl(filer->d_name);
		}
	}
}

static	void	ft_disp_ls(DIR *ope, int i)
{
	struct dirent	*filer;

	while ((filer = readdir(ope)) != NULL)
	{
		if (i == 1)
			ft_putendl(filer->d_name);
		else if (i == 0)
		{
			if (ft_first_c(filer->d_name, '.') == NULL)
				ft_putendl(filer->d_name);
		}
		else if (i == 2)
		{
			ft_disp_info(filer, ope);
			break ;
		}
		else if (i == 3)
		{
			ft_disp_infola(filer, ope);
			break ;
		}
	}
}

static	void		ft_putR(DIR *ope)
{
	struct dirent	*filer;
	struct stat 	info;
	int				j;
	int				mode;

	mode = 1;
	j = 0;
	ft_disp_ls(ope, j);
	while ((filer = readdir(ope)) != NULL)
	{
		j = lstat(filer->d_name, &info);	
		closedir(ope);
		ft_putR(ope = opendir(filer->d_name));
	}
}

static	void	ft_check_flag(DIR *ope, char *av)
{
	int				i;

	if (ft_strchr(av, 'a') && ft_strchr(av, 'l'))
	{
		i = 3;
		ft_disp_ls(ope, i);
	}
	else if (ft_strchr(av, 'a'))
	{
		i = 1;
		ft_disp_ls(ope, i);
	}
	else if (ft_strchr(av, 'l'))
	{
		i = 2;
		ft_disp_ls(ope, i);
	}
	else if (ft_strchr(av, 'R'))
	{
		ft_putR(ope);
	}
	else
		return ;
}

int				main(int ac, char **av)
{
	DIR 			*ope;
	int				i;

	ac = 0;
	i = 0;
	if (av[1] == 0)
	{
		ope = opendir(".");
		ft_disp_ls(ope, i);
	}
	else if (ft_first_c(av[1], '-'))
	{
		ope = opendir(".");
		ft_check_flag(ope, av[1]);
	}
	else
		return (0);
	if (ope == NULL)
		exit(1);
	if (closedir(ope) == -1)
		exit(-1);
	return (0);
}