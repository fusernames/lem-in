#include "lem_in.h"

static int		ft_print_comb(t_list *comb)
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
}

int		main(void)
{
	t_data	data;
	
	data.rooms = NULL;
	data.pipes = NULL;
	data.ants = NULL;
	data.paths = NULL;
	data.combs = NULL;
	if (ft_parser(&data))
		exit(1);
	if (ft_check_exceptions(data.rooms, data.pipes))
		exit (1);
	data.paths = ft_find_path(ft_find_room_by_type(data.rooms, 1), data.pipes);
	ft_print_comb(data.paths);
	ft_find_comb(data.paths, NULL, &(data.combs), NULL);
	ft_print_comb(data.combs);
	ft_travel(&data);
	// boucle (1)
	// faire bouger de 1 de toute les salles
	// faire choisir un chemin les fourmis du start
	ft_clean(&data);
	return (0);
}
