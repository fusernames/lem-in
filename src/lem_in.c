/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:54:27 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/14 22:08:03 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_print_paths(t_list *comb, char *str)
{
	t_list	*path;
	int		i;

	i = 0;
	path = NULL;
	ft_putchar('\n');
	ft_putendl(str);
	while (comb)
	{
		ft_putnbr(i++);
		ft_putstr(".\n");
		path = comb->content;
		while (path)
		{
			ft_putstr(((t_room *)path->content)->name);
			if (path->next)
				ft_putstr(" - ");
			path = path->next;
		}
		ft_putchar('\n');
		comb = comb->next;
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_data	data;

	data.rooms = NULL;
	data.pipes = NULL;
	data.ants = NULL;
	data.paths = NULL;
	data.combs = NULL;
	data.str = NULL;
	ft_parse_flags(ac, av, data.flags);
	ft_parser(&data);
	ft_check_exceptions(&data);
	data.paths = ft_find_path(ft_find_room_by_type(data.rooms, 1), data.pipes);
	if (!data.paths)
		ft_error("no valid paths found.", &data);
	ft_find_comb(data.paths, NULL, &(data.combs), NULL);
	ft_putendl(data.str);
	ft_travel(&data);
	if (ft_strstr(data.flags, "p"))
		ft_print_paths(data.paths, "===== PATHS FOUND =====");
	if (ft_strstr(data.flags, "c"))
		ft_print_paths(data.combs, "===== BEST COMB =====");
	ft_free_data(&data);
	return (0);
}
