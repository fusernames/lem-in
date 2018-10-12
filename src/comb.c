/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:26:30 by alcaroff          #+#    #+#             */
/*   Updated: 2018/10/12 19:28:03 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_same_path(t_list *path1, t_list *path2)
{
	while (path1 && path2)
	{
		if (path1->content != path2->content)
			return (0);
		path1 = path1->next;
		path2 = path2->next;
	}
	return (1);
}

static int		path_cmp(t_list *path1, t_list *path2)
{
	t_list	*save;

	save = path2;
	while (path1)
	{
		path2 = save;
		while (path2)
		{
			if ((t_room *)path1->content == (t_room *)path2->content &&
				((t_room *)path2->content)->type == 0)
				return (1);
			path2 = path2->next;
		}
		path1 = path1->next;
	}
	return (0);
}

static int		path_is_in_comb(t_list *comb, t_list *path)
{
	while (comb)
	{
		if (path_cmp(path, comb->content) || is_same_path(path, comb->content))
			return (1);
		comb = comb->next;
	}
	return (0);
}

static int		score(t_list *comb)
{
	int		score;

	score = 0;
	score += ft_lstlen(comb) * 10;
	while (comb)
	{
		score -= ft_lstlen((t_list *)comb->content) / 2;
		comb = comb->next;
	}
	return (score);
}

int				ft_find_comb(t_list *paths, t_list *path,
		t_list **comb, t_list *current_comb)
{
	t_list	*paths_cpy;

	if (path)
	{
		ft_lstnewadd(NULL, 0, &current_comb);
		current_comb->content = path;
	}
	if (score(*comb) < score(current_comb))
	{
		ft_lstfree(comb);
		*comb = ft_lstcpy(current_comb);
	}
	paths_cpy = paths;
	while (paths_cpy)
	{
		if (!path_is_in_comb(current_comb, paths_cpy->content))
			ft_find_comb(paths, paths_cpy->content, comb, current_comb);
		paths_cpy = paths_cpy->next;
	}
	if (current_comb)
		free(current_comb);
	return (0);
}
