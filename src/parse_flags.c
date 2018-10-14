/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 21:41:08 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/14 22:11:49 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_parse_flags(int ac, char **av, char *flags)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			while (av[i][j] && k < 254)
				flags[k++] = av[i][j++];
		}
		i++;
	}
	flags[k] = '\0';
	return (0);
}
