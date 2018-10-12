/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:08:54 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/12 19:05:06 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinline(char *str, char *line)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(str) + ft_strlen(line) + 1);
	if (new == NULL)
		return (NULL);
	if (str)
	{
		ft_strcat(new, str);
		free(str);
	}
	if (line)
		ft_strcat(new, line);
	ft_strcat(new, "\n");
	return (new);
}
