/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:53:29 by walnaimi          #+#    #+#             */
/*   Updated: 2024/08/09 00:51:47 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
void copy_env_value(char *result, const char *env_value, size_t *j)
{
    if (env_value)
    {
        size_t value_len;
        value_len = ft_strlen(env_value);
        strncpy(&result[*j], env_value, value_len);//FT_STRNCPY THAT BICH
        *j += value_len;
    }
}

void setup_env_variables(const char *input,t_data *data)
{
    data->len_t = ft_strlen(input);
    data->s_quote_o = 0;
    data->d_quote_o = 0;
}

void single_q(const char *input, t_data *data, char *res, size_t *i, size_t *j)
{
    data->s_quote_o = !data->s_quote_o;
    res[(*j)++] = input[(*i)++];
}

void double_q(const char *input, t_data *data, char *res, size_t *i, size_t *j)
{
    data->d_quote_o = !data->d_quote_o;
    res[(*j)++] = input[(*i)++];
}

void handle_env_variable(const char *input, size_t *i, t_data *data, char *result, size_t *j)
{
    size_t new_len;
    char *env_value = expand_env_variable(input, i, data, &new_len);
    if (env_value)
        copy_env_value(result, env_value, j);
}