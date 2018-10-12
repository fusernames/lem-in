/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:23:45 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/12 19:24:51 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*path_is_avalaible(t_list *path, t_list *ants)
{
	while (((t_room *)path->next->content)->type != 1)
		path = path->next;
	if (((t_room *)path->content)->type == 2)
		return (path->content);
	while (ants)
	{
		if (((t_ant *)ants->content)->room == path->content)
			return (NULL);
		ants = ants->next;
	}
	return (path->content);
}

static int		start_path(t_ant *ant, t_data *data)
{
	t_list	*shortest;
	t_list	*paths;

	paths = data->combs;
	shortest = NULL;
	while (paths)
	{
		if (path_is_avalaible(paths->content, data->ants) &&
			(shortest == NULL
			|| ft_lstlen(paths->content) < ft_lstlen(shortest)))
			shortest = paths->content;
		paths = paths->next;
	}
	if (shortest == NULL)
		return (1);
	ant->room = path_is_avalaible(shortest, data->ants);
	ft_print_move(ant);
	return (0);
}

int				ft_choose_path(t_data *data)
{
	t_list	*ants;

	ants = data->ants;
	while (ants)
	{
		if (((t_ant *)ants->content)->room->type == 1)
			start_path(ants->content, data);
		ants = ants->next;
	}
	return (0);
}
