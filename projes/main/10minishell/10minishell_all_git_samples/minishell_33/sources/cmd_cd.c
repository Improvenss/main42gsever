/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:58:45 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 21:58:45 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_cd.c
 * @author Ahmet KARACA (akaraca)
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/minishell.h"

char	*env_findret_no_dup(t_base *base, char *env_name)
{
	t_env	*tmp;

	tmp = base->env;
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
		{
			if (tmp->data[1] != NULL)
				return (tmp->data[1]);
			else
				return (NULL);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * @brief 
 * 
 * 				!!!!! NOTE !!!!!!
 * 
 * Kral burada char bur[PATH_MAX] yap getcwd'yi sizeof(buf) yap dene, sonra
 *  sizeof(buf)'u PATH_MAX yap oyle dene, sonra malloc'lu olani ac freeyi ac
 *  sizeof(buf)'u yine PATH_MAX yap boyle dene cok bazen degistiriyor
 *  bazen degistirmiyor PWD= 'yi...
 * 
 * @param base 
 * @return int 
 */
static int	update_pwd(t_base *base)
{
	char	buf[PATH_MAX];

	if (env_findret_no_dup(base, "PWD"))
	{
		set_env(base, "OLDPWD", env_findret(base, "PWD"));
	}
	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		print_error_errno(SHELLNAME, "cd", NULL);
		return (ERROR);
	}
	set_env(base, "PWD", ft_strdup(buf));
	return (0);
}

/**
 * @brief direction'umuzu bulup return etmek icin.
 * 
 * Dir'imiz;
 * 		[cd], [cd --], [cd ~] komutalarini iceriyorsa $HOME dizinindeki dir'i
 *  donecek, eger yoksa set edilmedi diyecek(unset'lemisiz).
 * 		[cd -] varsa OLDPWD'yi dondurecek.
 * 		[ direction ] varsa da direkt girdigimiz yolu dondurecek.
 * 
 * @param base base->env'ler icin.
 * @param cmd cmd->full_cmd'ler icin.
 * @fn ft_strncmp(): komutlarimizin icinde sunlar varsa.
 * @fn env_findret(): base->env'lerimizin icindeki atamalarin
 *  degerlerini dondurur.
 * @fn print_error(): error mesaji.
 * @return char* 
 */
static char	*get_dir(t_base *base, t_cmd *cmd)
{
	char	*dir;

	dir = NULL;
	if ((cmd->full_cmd[0] && cmd->full_cmd[1] == NULL)
		|| ft_strncmp(cmd->full_cmd[1], "~", 2) == 0
		|| ft_strncmp(cmd->full_cmd[1], "--", 3) == 0)
	{
		dir = env_findret_no_dup(base, "HOME");
		if (dir == NULL)
			print_error(SHELLNAME, "cd", NULL, "HOME not set");
	}
	else if (cmd->full_cmd[0] && ft_strncmp(cmd->full_cmd[1], "-", 2) == 0)
	{
		dir = env_findret_no_dup(base, "OLDPWD");
		if (dir == NULL)
			print_error(SHELLNAME, "cd", NULL, "OLDPWD not set");
	}
	else
		dir = cmd->full_cmd[1];
	return (dir);
}

/**
 * @brief Buradan basliyor get_dir()'le diri alip direkt chdir()'le
 *  konumu degistiriyor, sonra - varsa OLD_PWD'yi yazidiriyor,
 *  sonra env'deki PWD ya da OLDPWD'leri falan guncelliyor.
 * 
 * @param base base->env'ler icin.
 * @param cmd cmd->full_cmd[] yani parserlenmis komutlarimiz.
 * @fn get_dir(): cd komutunun yanina girilen argumanlara gore;
 *  [ ] || [~] || [--] -> dir = $HOME.
 *  [-] -> dir = $OLDPWD.
 *  [dir] -> dir = cmd->full_cmd[1](yani dir).
 * @fn chdir(): Burada gelen dir'imizi terminalimizin konumu yapiyoruz.
 * @fn ft_strncmp(): cd komutunun yaninda '-' varsa oncdeki
 *  konumu yazdiriyoruz.
 * @fn ft_putendl_fd(): Burada fd(1)'e yaziyoruz.
 * @fn update_pwd(): Env'lerimizdeki PWD'yi su anki konumumuza guncelliyoruz,
 *  OLDPWD'yi de bir onceki konumumuza guncelliyoruz. Eger haricinde
 *  bir seyler varsa onlari da hallediyoruz burada.
 * @return int OK: 0, NOK: EXIT_FAILURE(1).
 */
int	cmd_cd(t_base *base, t_cmd *cmd)
{
	char	*dir;

	dir = get_dir(base, cmd);
	if (dir == NULL)
		return (EXIT_FAILURE);
	if (chdir(dir) == -1)
	{
		print_error_errno(SHELLNAME, "cd", dir);
		return (EXIT_FAILURE);
	}
	if (cmd->full_cmd[1] && ft_strncmp(cmd->full_cmd[1], "-", 2) == 0)
		ft_putendl_fd(dir, STDOUT_FILENO);
	if (update_pwd(base) == ERROR)
		return (EXIT_FAILURE);
	return (0);
}
