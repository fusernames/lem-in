/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exceptions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:23:12 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/12 19:23:14 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_duplicate(t_data *data)
{
	t_list	*rooms;
	t_list	*pipes;
	t_pipe	*pipe;

	pipes = data->pipes;
	rooms = data->rooms;
	while (rooms)
	{
		if (ft_find_room_by_name(rooms->next, ((t_room *)rooms->content)->name))
			ft_error("rooms with same name.", data);
		rooms = rooms->next;
	}
	while (pipes)
	{
		pipe = pipes->content;
		if (!ft_strcmp(pipe->room[0]->name, pipe->room[1]->name))
			ft_error("pipe between the same room.", data);
		pipes = pipes->next;
	}
	return (0);
}

int			ft_check_rooms(t_data *data)
{
	int		end;
	int		start;
	t_list	*rooms;

	rooms = data->rooms;
	start = 0;
	end = 0;
	if (ft_lstlen(rooms) <= 1)
		ft_error("not enough rooms.", data);
	while (rooms)
	{
		if (((t_room *)rooms->content)->type == 1)
			start++;
		if (((t_room *)rooms->content)->type == 2)
			end++;
		rooms = rooms->next;
	}
	if (start != 1 || end != 1)
		ft_error("please set 1 start and 1 end", data);
	return (0);
}

int			ft_check_exceptions(t_data *data)
{
	ft_check_duplicate(data);
	ft_check_rooms(data);
	return (0);
}
