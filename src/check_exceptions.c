#include "lem_in.h"

int		ft_check_exceptions(t_list *rooms, t_list *pipes)
{
	t_pipe	*pipe;
	while (rooms)
	{
		if (ft_find_room_by_name(rooms->next, ((t_room *)rooms->content)->name))
			return (1);
		rooms = rooms->next;
	}
	while (pipes)
	{
		pipe = pipes->content;
		if (!ft_strcmp(pipe->room[0]->name, pipe->room[1]->name))
			return (1);
		pipes = pipes->next;
	}
	return (0);
}
