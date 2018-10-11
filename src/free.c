/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:16:42 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/11 17:14:35 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_free_paths(t_list *paths)
{
	t_list	*tmp;
	t_list	*path;

	while (paths)
	{
		path = paths->content;
		ft_lstfree(&path);
		tmp = paths;
		paths = paths->next;
		free(tmp);
	}
	return (0);
}

int			ft_free_data(t_data *data)
{
	ft_free_paths(data->paths);
	ft_lstfree(&(data->combs));
	ft_lstfree(&(data->pipes));
	ft_lstfree(&(data->ants));
	ft_lstfree(&(data->rooms));
	free(data->str);
	return (0);
}
