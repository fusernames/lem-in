#include "lem_in.h"

static int	ft_free_paths(t_list *paths)
{
	t_list	*tmp;
	t_list	*path;

	while (paths)
	{
		path = paths->content;
		ft_lstfree(&path);
		tmp = paths;
		paths = paths->next;
		free(tmp);
	}
	return (0);
}

int			ft_clean(t_data *data)
{
	ft_free_paths(data->paths);
	ft_lstfree(&(data->combs));
	return (0);
}
