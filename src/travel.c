#include "lem_in.h"

int		ft_print_move(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->id);
	ft_putchar('-');
	ft_putstr(ant->room->name);
	ft_putchar(' ');
	return (0);
}

static int	move_ant(t_room *src, t_room *dest, t_list *ants)
{
	t_ant	*ant;

	ant = NULL;
	while (ants && ((t_ant *)ants->content)->room != src)
		ants = ants->next;
	if (ants)
		ant = ants->content;
	if (ant && ant->room == src)
	{
		ant->room = dest;
		ft_print_move(ant);
	}
	return (0);
}

int		path_travel(t_data *data)
{
	t_list	*paths;
	t_list	*path;
	t_list	*prev;
	
	paths = data->combs;
	while (paths)
	{
		path = paths->content;
		prev = NULL;
		while (path && ((t_room *)path->content)->type != 1)
		{
			if (prev)
				move_ant(path->content, prev->content, data->ants);
			prev = path;
			path = path->next;
		}
		paths = paths->next;
	}	
	return (0);		
}

static int	is_finished(t_data *data)
{
	t_list 	*ants;

	ants = data->ants;
	while (ants)
	{
		if (((t_ant *)ants->content)->room->type != 2)
			return (0);
		ants = ants->next;
	}
	return (1);
}

int			ft_travel(t_data *data)
{
	while (!is_finished(data))
	{
		path_travel(data);
		ft_choose_path(data);
		ft_putchar('\n');
	}
	return (0);
}
