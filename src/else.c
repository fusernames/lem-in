/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:23:18 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/12 19:23:19 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_find_room_by_name(t_list *start, char *name)
{
	while (start)
	{
		if (!ft_strcmp(name, ((t_room *)start->content)->name))
			return (((t_room *)start->content));
		start = start->next;
	}
	return (NULL);
}

t_room	*ft_find_room_by_type(t_list *start, int type)
{
	while (start)
	{
		if (type == ((t_room *)start->content)->type)
			return (((t_room *)start->content));
		start = start->next;
	}
	return (NULL);
}
