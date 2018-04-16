#include "lem_in.h"

int		ft_parser_room(t_room **room)
{
	char	*line;
	int		type;

	while (get_next_line(1, &line) > 0)
	{
		type = 0;
		if (!line || ft_strstr(line, "-"))
			break;
		if (line[0] == '#' && line[1] != '#')
			;
		else if (!ft_strcmp(line, "##start"))
			type = 1;
		else if (!ft_strcmp(line, "##end"))
			type = 2;
		else
			if (ft_create_room(room, line, mode)
				return (1);
	}
	return (0);
}

int		ft_parser_pipe(t_pipe **pipe)
{
	char 	*line;

	while (get_next_line(1, &line) > 0)
	{
		if (ft_charoc(line, '-') != 1 || ft_create_pipe(pipe, line))
			return (1);
	}
	return (0);
}

int		ft_parser(t_room **room, t_pipe **pipe)
{
	char	*line;
	int		nb_ants;
	
	get_next_line(1, &line);
	nb_ants = ft_atoi(line);
	ft_parser_room(room);
	ft_parser_pipe(pipe);
	ft_create_ant(nb_ants, ant, room);
	return (0);
}
