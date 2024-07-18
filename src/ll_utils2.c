/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:35:09 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/07/18 15:50:31 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* should probably not use getenv() here */
char **env_arr_updater(t_env **env_ll)
{
    int     i;
	int		size;
    t_env   *tmp;
	char	**env;
   
    i = 0;
	tmp = (*env_ll);
	size = ll_size(env_ll);
	env = malloc(sizeof(char **) * size + 1);
	if (!env)
	{
		perror("Failed to allocate memory for data->env\n");
		return (NULL);
	}
	while (i < size)
	{
		env[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
        i++;
    }
    tmp = NULL;
	return (env);
}

int	ll_size(t_env **env_ll)
{
	t_env	*tmp;
	int		i;

	if (!env_ll || !*env_ll)
		return (0);
	i = 0;
	tmp = *env_ll;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = NULL;
	return (i);
}