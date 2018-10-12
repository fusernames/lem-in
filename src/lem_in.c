/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:54:27 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/12 20:50:27 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*static int		ft_print_comb(t_list *comb)
{
	t_list	*path;

	path = NULL;
	while (comb)
	{
		printf("paths :\n");
		path = comb->content;
		while (path)
		{
			printf("%s - ", ((t_room *)path->content)->name);
			path = path->next;
		}
		printf("\n");
		comb = comb->next;
	}
	return (0);
}*/

int		main(void)
{
	t_data	data;

	data.rooms = NULL;
	data.pipes = NULL;
	data.ants = NULL;
	data.paths = NULL;
	data.combs = NULL;
	data.str = NULL;
	ft_parser(&data);
	ft_check_exceptions(&data);
	data.paths = ft_find_path(ft_find_room_by_type(data.rooms, 1), data.pipes);
	if (!data.paths)
		ft_error("no valid paths found.", &data);
	ft_putendl(data.str);
	ft_find_comb(data.paths, NULL, &(data.combs), NULL);
	ft_travel(&data);
	ft_free_data(&data);
	return (0);
}
