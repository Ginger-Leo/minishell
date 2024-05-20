/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:13:01 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/20 16:36:57 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*************************************************/
/* libft *****************************************/
/*************************************************/
# include "libft.h"

/*************************************************/
/* external libraries ****************************/
/*************************************************/
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

/*************************************************/
/* macro *****************************************/
/*************************************************/
//Errors
# define ERR "Error\n"
# define EXIT "Exit\n"
# define ERR_ARG "Wrong number of arguments, Karen\n"
# define PATH_MAX 1024

/*************************************************/
/* structs ***************************************/
/*************************************************/
typedef struct s_env
{
	int				dummy;
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
}			t_env;

typedef struct s_data
{
	char 	**env;
	int		exit_status;
	int		pipe;
	char	*bin;
	char	*home_pwd;
	int		dummy;
	// need to insert pids, tokens, and commands
	char	*line_read;
	t_env	*envll;
}	t_data;

/*************************************************/
/* functions *************************************/
/*************************************************/

/* in main.c */
//usually I leave main.c alone. Its a style choice.

/* in init.c */
void	ll_env(t_env **env_ll, char **env);
void	initializer(t_data *data, t_env **env_ll, char **env);
void	find_bin(t_env **env_ll, t_data *data);
char	*bin_extract(char *path);

/* in exit_handler.c */
void	error_exit(int num);

/* in line_handler.c */
int		sniff_line(t_data *data);
// int		line_parsing(t_data *data, char *line); // future parsing

/* in ll_utils.c */
t_env	*ft_listnew(void *content);
void	ft_listadd_back(t_env **lst, t_env *new);
t_env	*ft_list_last(t_env *lst);
void	free_ll(t_env *env_ll);

/* in built_ins.c */
void	built_ins(t_data *data, t_env *env_ll);
void	print_env(t_env *env_ll);
void	print_pwd(t_env *env_ll);
void	get_the_hell_out(t_env *env_ll);
void	yodeling(char *echoes);

/* in built_ins2.c */
void	shell_cd(t_data *data, t_env *env_ll);
void	go_home(t_data *data, char *path);
char	*get_home(t_env *env_ll);
// char	*update_env_cd(t_data *data, t_env *env_ll);

#endif