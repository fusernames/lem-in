#include "lem_in.h"

static int	recursive(t_list **path, t_list *current_path, t_room *room, t_list *pipe)
{
	t_list	*pipe_x;
	t_room	*ret;

	ft_create_path(&current_path, room);
	if (((t_path *)current_path->content)->room->type == 2)
	{
		ft_lstnewadd(NULL, 0, path);
		(*path)->content = ft_lstdup(current_path);
		return (1);
	}
	pipe_x = pipe;
	while (pipe_x)
	{
		ret = NULL;
		if ((ret = ft_path_contains(((t_pipe *)pipe_x->content),
			current_path, room)))
			recursive(path, current_path, ret, pipe);
		pipe_x = pipe_x->next;
	}
	free(current_path->content);
	free(current_path);
	return (0);
}

/*
	tester toutes les combinaisons de chemins et etablir un score.
	score = nb_chemins - (longueure chemin le plus long*2);
*/

static int		*ft_find_comb(t_list *paths, t_list *path, t_list **comb, t_list *current_comb)
{
	t_list	*paths_cpy;

	printf("femesk suce des bites\n");
	ft_lstnewadd(NULL, 0, &current_comb);
	current_comb->content = path;
	paths_cpy = paths;
	while (paths_cpy)
	{
		if (!ft_path_is_in_comb(current_comb, paths_cpy->content))
			ft_find_comb(paths, paths_cpy->content, comb, current_comb);
		paths_cpy = paths_cpy->next;
	}	
	return (0);
}

t_list		*ft_find_path(t_room *room, t_list *pipe)
{
	t_list	*paths;
	t_list	*comb;

	paths = NULL;
	recursive(&paths, NULL, room, pipe);
	ft_find_comb(paths, paths->content, &comb, NULL);
	return (paths);
}
