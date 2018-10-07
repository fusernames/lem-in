#include "lem_in.h"

static int	ft_parser_room(t_data *data, char **line)
{
	int		type;

	type = 0;
	while (1)
	{
		if (!(get_next_line(0, line)))
			ft_error(NULL);
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
			if (ft_create_room(*line, type, data))
				ft_error(NULL);
			type = 0;
		}
	}
	return (0);
}

static int	ft_parser_pipe(t_data *data, char **line)
{
	while (1)
	{
		if ((*line)[0] == '#')
			;
		else if (ft_charoc(*line, '-') != 1)
			break ;
		else 
			if (ft_create_pipe(*line, data))
				ft_error(NULL);
		if (!(get_next_line(0, line)))
			break ;
	}
	return (0);
}

int			ft_parser(t_data *data)
{
	char	*line;
	int		nb_ants;

	line = NULL;
	if (!get_next_line(0, &line))
		ft_error(NULL);
	if ((nb_ants = ft_atoi(line)) <= 0)
		ft_error(NULL);
	ft_parser_room(data, &line);
	if (!line)
		ft_error(NULL);
	ft_parser_pipe(data, &line);
	ft_create_ant(nb_ants, data);
	return (0);
}
