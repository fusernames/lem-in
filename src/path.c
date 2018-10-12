/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:45:47 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/12 20:54:07 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*ft_path_contains(t_pipe *pipe, t_list *cur_path, t_room *room)
{
	t_room	*ret;

	if (pipe->room[1] == room)
		ret = (pipe->room[0]);
	else if (pipe->room[0] == room)
		ret = (pipe->room[1]);
	else
		return (NULL);
	while (cur_path)
	{
		if (ret == ((t_room *)cur_path->content))
			return (NULL);
		cur_path = cur_path->next;
	}
	return (ret);
}

static int		recursive(t_list **path, t_list *cur_path,
		t_room *room, t_list *pipe)
{
	t_list	*pipe_x;
	t_room	*ret;

	ft_lstnewadd(NULL, 0, &cur_path);
	cur_path->content = room;
	if (room->type == 2)
	{
		ft_lstnewadd(NULL, 0, path);
		(*path)->content = ft_lstcpy(cur_path);
		free(cur_path);
		return (0);
	}
	pipe_x = pipe;
	while (pipe_x)
	{
		ret = NULL;
		if ((ret = ft_path_contains(((t_pipe *)pipe_x->content),
			cur_path, room)))
			recursive(path, cur_path, ret, pipe);
		pipe_x = pipe_x->next;
	}
	free(cur_path);
	return (0);
}

t_list			*ft_find_path(t_room *room, t_list *pipe)
{
	t_list	*paths;

	paths = NULL;
	recursive(&paths, NULL, room, pipe);
	return (paths);
}
