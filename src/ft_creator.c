#include "lem_in.h"

int		ft_create_room(char *line, int type, t_list **room)
{
	char 	**tab;
	t_room	new;

	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3
		|| !ft_isdigit(tab[1][0])
		|| !ft_isdigit(tab[2][0]))
		return (1);
	ft_strcpy(new.name, tab[0]);
	new.x = ft_atoi(tab[1]);
	new.y = ft_atoi(tab[2]);
	new.type = type;
	ft_lstnewadd(&new, sizeof(new), room);
	ft_tabfree(tab);
	return (0);
}

int		ft_create_pipe(char *line, t_list **pipe, t_list **room)
{
	char	**tab;
	t_pipe	new;

	tab = ft_strsplit(line, '-');
	if (ft_tablen(tab) != 2)
		return (1);
	if ((new.room[0] = ft_find_room_by_name(*room, tab[0])) == NULL ||
		(new.room[1] = ft_find_room_by_name(*room, tab[1])) == NULL)
		return (1);
	ft_lstnewadd(&new, sizeof(new), pipe);
	ft_tabfree(tab);
	return (0);
}

int		ft_create_ant(int nb_ants, t_list **ant, t_list **room)
{
	t_ant new;
	
	while (nb_ants-- > 0)
	{
		ft_bzero(ant, sizeof(ant));
		new.id = ft_lstlen(*ant) + 1;
		new.room = ft_find_room_by_type(*room, 1);
		ft_lstnewadd(&new, sizeof(new), ant);
	}
	return (0);
}
