/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:20:14 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/20 16:57:25 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_cd(t_data *data, t_env *env_ll)
{
	char	*old_cwd;
	char	*path;
	
	data->home_pwd = get_home(env_ll);
	if (!data->home_pwd)
		return ;
	old_cwd = getcwd(NULL, 0);
	path = data->line_read + 2;
	go_home(data, path); // probably need to split this one
	// update_env_cd(data, env_ll);
	printf("home_pwd:%s\n", data->home_pwd);
	printf("old_cwd:%s\n", old_cwd);
	printf("come back later, we are working on it\n");
}
void	go_home(t_data *data, char *path)
{
	int	status = 0;
	
	if (!ft_isalnum((*path)))
		path = NULL;
	printf("path in go_home:%s\n", path);
	if (!path)
		status = chdir(data->home_pwd); // NOT UPDATING SO DONT TRY PWD
	printf("value of home_pwd:%s\n", data->home_pwd);
	printf("value of status:%d\n", status);
}

char	*get_home(t_env *env_ll)
{
	t_env	*tmp;

	tmp = env_ll;
	while (env_ll->next != NULL)
	{
		if (!ft_strncmp(env_ll->content, "HOME=", 5))
			return (env_ll->content + 5);
		env_ll = env_ll->next;		
	}
	env_ll = tmp;
	return (NULL);
}

// char	*update_env_cd(t_data *data, t_env *env_ll)
// {
// 	t_env	*tmp;

// 	tmp = env_ll;
// 	while (env_ll->next != NULL)
// 	{
// 		if (!ft_strncmp(env_ll->content, "OLDPWD=", 7))
// 			return (env_ll->content = data->home_pwd); // wrong
// 		env_ll = env_ll->next;		
// 	}
// 	return (NULL);
// }


			// if (path[i + 2] == "." || path[i + 2] == ".." || ft_isalnum(path[i]))
			// {
			// 	if (chdir(data->home_pwd) == -1)
			// 	{
			// 		ft_printf("Karen: cd: %s: No such file or directory\n", 
			// 		path + 3);
			// 		return (NULL);
			// 	}
			// }
			// return (path + 3);