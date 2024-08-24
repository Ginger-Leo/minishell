/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:58:57 by walnaimi          #+#    #+#             */
/*   Updated: 2024/08/23 13:27:47 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Handles the output redirection token.
 *
 * @param token The token to be handled.
 * @param current_token The current token being processed.
 *
 * @return 0 if the token is an output redirection token, 1 otherwise.
 */
int	handle_redirect_out(char *token, t_token *current_token)
{
	if (ft_strncmp(token, ">", 2) == 0 && current_token->in_q == false)
	{
		current_token->value = ft_strdup(token);
		current_token->type = RED_OUT;
		free(token);
		token = NULL;
		return (0);
	}
	return (1);
}

/**
 * Handles the append redirection token.
 *
 * @param token The token to be handled.
 * @param current_token The current token being processed.
 *
 * @return 0 if the token is an append redirection token, 1 otherwise.
 */
int	handle_append(char *token, t_token *current_token)
{
	if (ft_strncmp(token, ">>", 3) == 0 && current_token->in_q == false)
	{
		current_token->value = ft_strdup(token);
		current_token->type = APPEND;
		free(token);
		token = NULL;
		return (0);
	}
	return (1);
}

/**
 * Handles the input redirection token.
 *
 * @param token The token to be handled.
 * @param current_token The current token being processed.
 *
 * @return 0 if the token is an input redirection token, 1 otherwise.
 */
int	handle_redirect_in(char *token, t_token *current_token)
{
	if (ft_strncmp(token, "<", 2) == 0 && current_token->in_q == false)
	{
		current_token->value = ft_strdup(token);
		current_token->type = RED_IN;
		free(token);
		token = NULL;
		return (0);
	}
	return (1);
}

/**
 * Handles the heredoc redirection token.
 *
 * @param token The token to be handled.
 * @param current_token The current token being processed.
 *
 * @return 0 if the token is a heredoc redirection token, 1 otherwise.
 */
int	handle_heredoc(char *token, t_token *current_token)
{
	if (ft_strncmp(token, "<<", 3) == 0 && current_token->in_q == false)
	{
		current_token->value = ft_strdup(token);
		current_token->type = HEREDOC;
		free(token);
		token = NULL;
		return (0);
	}
	return (1);
}