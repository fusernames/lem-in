#include "lem_in.h"

int		ft_create_room(t_room **start, char *line, int type)
{
	char 	**tab;
	t_room	*new;

	tab = ft_strsplit(' ', line);
	if (ft_tablen(tab) != 3 || !ft_isdigit(tab[1][0])
		|| !ft_isdigit(tab[2][0]))
		return (1);
	new = malloc(sizeof(room));
	new->name = ft_strdup(tab[0]);
	new->x = ft_atoi(tab[1]);
	new->y = ft_atoi(tab[2]);
	new->type = type;
	ft_tabfree(tab);
	if (ft_lst_last_elem(*start))
		(ft_lst_last_elem(*start))->next = new;
	else
		*start = new;
}

int		ft_create_pipe(t_pipe **start, char *line)
{
	char	**tab;
	t_pipe	*new;

	tab = ft_strsplit('-', line);
	if (ft_tablen(tab) != 2)
		return (1);
	pipe = malloc(sizeof(pipe));
	if ((new->room[0] = ft_find_room_by_name(tab[0])) == NULL ||
		(new->room[1] = ft_find_room_by_name(tab[1])) == NULL)
		return (1);
	ft_tabfree(tab);
	if (ft_lst_last_elem(*start))
		(ft_lst_last_elem(*start))->next = new;
	else
		*start = new;
	return (0);
}

int		ft_create_ant(t_ant **start, t_room *room)
{
	t_ant	*new;

	new = malloc(sizeof(room));
	new->id = lst_size(*start) + 1;
	new->room = ft_find_room_start;
	if (ft_lst_last_elem(*start))
		(ft_lst_last_elem(*start))->next = new;
	else
		*start = new;
}
