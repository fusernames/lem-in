#include "lem_in.h"

static int	ft_check_duplicate(t_list *rooms, t_list *pipes)
{
	t_pipe	*pipe;
	while (rooms)
	{
		if (ft_find_room_by_name(rooms->next, ((t_room *)rooms->content)->name))
			ft_error("rooms with same name.");
		rooms = rooms->next;
	}
	while (pipes)
	{
		pipe = pipes->content;
		if (!ft_strcmp(pipe->room[0]->name, pipe->room[1]->name))
			ft_error("pipe between the same room.");
		pipes = pipes->next;
	}
	return (0);
}

int			ft_check_rooms(t_list *rooms)
{
	int		end;
	int		start;

	start = 0;
	end = 0;
	if (ft_lstlen(rooms) <= 1)
		ft_error("not enough rooms.");
	while (rooms)
	{
		if (((t_room *)rooms->content)->type == 1)
			start++;
		if (((t_room *)rooms->content)->type == 2)
			end++;
		rooms = rooms->next;
	}
	if (start != 1 || end != 1)
		ft_error("please set 1 start and 1 end");
	return (0);
}

int			ft_check_exceptions(t_list *rooms, t_list *pipes)
{
	ft_check_duplicate(rooms, pipes);
	ft_check_rooms(rooms);
	return (0);
}
