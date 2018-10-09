/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:08:28 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/09 13:50:35 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_pipes(t_data *data)
{
	t_list	*lst;
	t_pipe	*pipe;

	lst = data->pipes;
	while (lst)
	{
		pipe = lst->content;
		ft_putstr(pipe->room[0]->name);
		ft_putchar('-');
		ft_putstr(pipe->room[1]->name);
		ft_putchar('\n');
		lst = lst->next;
	}
}

static void	ft_print_rooms(t_data *data)
{
	t_list	*lst;
	t_room	*room;

	lst = data->rooms;
	while (lst)
	{
		room = lst->content;
		if (room->type == 1)
			ft_putendl("##start");
		else if (room->type == 2)
			ft_putendl("##end");
		ft_putstr(room->name);
		ft_putchar(' ');
		ft_putnbr(room->x);
		ft_putchar(' ');
		ft_putnbr(room->y);
		ft_putchar('\n');
		lst = lst->next;
	}
}

void		ft_print_data(t_data *data)
{
	ft_putnbr(ft_lstlen(data->ants));
	ft_putchar('\n');
	ft_print_rooms(data);
	ft_print_pipes(data);
	ft_putchar('\n');
}
