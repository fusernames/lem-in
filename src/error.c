/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:59:49 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/11 15:39:52 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(char *str, t_data *data)
{
	if (!str)
		ft_putstr_fd("ERROR", 2);
	else
	{
		ft_putstr_fd("ERROR : ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	ft_free_data(data);
	exit(1);
}
