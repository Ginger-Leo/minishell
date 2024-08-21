/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:38:16 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/08/21 12:04:54 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_fds_init(t_data *data)
{
	int	i;

	i = 0;
	while (data->heredoc_fd[i])
	{
		data->heredoc_fd[i] = -1;
		i++;
	}
}

void	ll_env(t_env **env_ll, char **env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	if (*env_ll == NULL)
		*env_ll = ft_listnew(env[i++]);
	tmp = (*env_ll);
	while (env[i])
		ft_listadd_back(env_ll, ft_listnew(env[i++]));
	(*env_ll) = tmp;
}

void	find_bin(t_env **env_ll, t_data *data)
{
	t_env	*tmp;

	tmp = (*env_ll);
	while ((*env_ll)->next != NULL)
	{
		if (!ft_strncmp((*env_ll)->content, "PATH=", 5))
			data->bin = bin_extract((*env_ll)->content);
		(*env_ll) = (*env_ll)->next;
	}
	(*env_ll) = tmp;
}

char	*bin_extract(char *path)
{
	int	i;

	i = 0;
	if (!path)
		return (NULL);
	while (path)
	{
		if (!ft_strncmp(path, "PATH=", 5))
			return (path + 5);
		i++;
	}
	return (NULL);
}

void	initializer(t_data *data, t_env **env_ll, char **env)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	ft_bzero(data, sizeof(t_data));
	ll_env(env_ll, env);
	find_bin(env_ll, data);
	heredoc_fds_init(data);
	data->binary_paths = ft_split(data->bin, ':');
	data->envll = *env_ll;
	data->in_quotes = 0;
	data->echoed = false;
	data->echoed = false;
	data->cmd_ignore = false;
}
