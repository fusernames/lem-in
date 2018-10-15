/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:13:47 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/15 17:22:56 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_parser_room(t_data *data, char **line)
{
	int		type;

	type = 0;
	while (1)
	{
		if (get_next_line(0, line) <= 0)
			ft_error(NULL, data);
		if (ft_strstr(*line, "-"))
			break ;
		else if (!ft_strcmp(*line, "##start"))
			type = 1;
		else if (!ft_strcmp(*line, "##end"))
			type = 2;
		else if ((*line)[0] == '#')
			;
		else
		{
			if (ft_create_room(*line, type, data))
				ft_error(NULL, data);
			type = 0;
		}
		data->str = ft_strjoinline(data->str, *line);
	}
	return (0);
}

static int	ft_parser_pipe(t_data *data, char **line)
{
	while (1)
	{
		data->str = ft_strjoinline(data->str, *line);
		if ((*line)[0] == '#')
			;
		else if (ft_charoc(*line, '-') != 1)
			ft_error(NULL, data);
		else
		{
			if (ft_create_pipe(*line, data))
				ft_error(NULL, data);
		}
		if (get_next_line(0, line) <= 0)
			break ;
	}
	return (0);
}

int			ft_parser(t_data *data)
{
	char	*line;
	int		nb_ants;

	line = NULL;
	while ((get_next_line(0, &line) > 0 && line && *line == '#'))
		data->str = ft_strjoinline(data->str, line);
	if ((!line || !ft_strisnum(line)))
		ft_error(NULL, data);
	data->str = ft_strjoinline(data->str, line);
	if ((nb_ants = ft_atoi(line)) <= 0)
		ft_error(NULL, data);
	ft_parser_room(data, &line);
	if (!line)
		ft_error(NULL, data);
	ft_parser_pipe(data, &line);
	ft_create_ant(nb_ants, data);
	return (0);
}
