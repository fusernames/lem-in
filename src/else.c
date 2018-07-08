#include "lem_in.h"

t_room	*ft_find_room_by_name(t_list *start, char *name)
{
	while (start)
	{
		if (!ft_strcmp(name, ((t_room *)start->content)->name))
			return (((t_room *)start->content));
		start = start->next;
	}
	return (NULL);
}

t_room	*ft_find_room_by_type(t_list *start, int type)
{
	while (start)
	{
		if (type == ((t_room *)start->content)->type)
			return (((t_room *)start->content));
		start = start->next;
	}
	return (NULL);
}

t_room	*ft_path_contains(t_pipe *pipe, t_list *current_path, t_room *room)
{
	t_room	*ret;

	if (pipe->room[1] == room)
		ret = (pipe->room[0]);
	else if (pipe->room[0] == room)
		ret = (pipe->room[1]);
	else
		return (NULL);
	while (current_path)
	{
		if (ret == ((t_path *)current_path->content)->room)
			return (NULL);
		current_path = current_path->next;
	}
	return (ret);
}

int		ft_path_is_in_comb(t_list *comb, t_list *path)
{
	while (comb)
	{
		if (comb->content == path)
			return (1);
		comb = comb->next;
	}
	return (0);
}
