#include "lem_in.h"

static int	ft_parser_room(t_list **room, char **line)
{
	int		type;

	type = 0;
	while (1)
	{
		if (!(get_next_line(0, line)))
			return (1);
		if ((*line)[0] == '#' && (*line)[1] != '#')
			;
		else if (ft_strstr(*line, "-"))
			break;
		else if (!ft_strcmp(*line, "##start"))
			type = 1;
		else if (!ft_strcmp(*line, "##end"))
			type = 2;
		else
		{
			if (ft_create_room(*line, type, room))
				return (1);
			type = 0;
		}
	}
	return (0);
}

static int	ft_parser_pipe(t_list **pipe, t_list **room, char **line)
{
	while (1)
	{
		if ((*line)[0] == '#')
			;
		else if (ft_charoc(*line, '-') != 1)
			break;
		else 
			if (ft_create_pipe(*line, pipe, room))
				return (1);
		if (!(get_next_line(0, line)))
			break;
	}
	return (0);
}

int			ft_parser(t_list **room, t_list **pipe, t_list **ant)
{
	char	*line;
	int		nb_ants;
	
	get_next_line(0, &line);
	nb_ants = ft_atoi(line);
	if (ft_parser_room(room, &line)
		|| ft_parser_pipe(pipe, room, &line)
		|| ft_create_ant(nb_ants, ant, room))
		return (1);
	return (0);
}
