#include "lem_in.h"

int		main(void)
{
	t_list	*room;
	t_list	*pipe;
	t_list	*ant;
	t_list	*path;
	t_list	*tmp;

	room = NULL;
	pipe = NULL;
	ant = NULL;
	path = NULL;
	if (ft_parser(&room, &pipe, &ant))
		exit(1);
	/*while (room)
	{
		printf("name : %s\n", ((t_room *)room->content)->name);
		printf("type : %d\n", ((t_room *)room->content)->type);

		room = room->next;
	}
	printf("name : %s\n", ((t_pipe *)pipe->content)->room[0]->name);
	*/
	path = ft_find_path(ft_find_room_by_type(room, 1), pipe);
	while (path)
	{
		tmp = path->content;
		printf("chemin\n");
		while (tmp)
		{
			printf("%s => ", ((t_path *)tmp->content)->room->name);
			tmp = tmp->next;
		}
		path = path->next;
		printf("\n");
	}
	// boucle (1)
	// faire bouger de 1 de toute les salles
	// faire choisir un chemin les fourmis du start
	return (0);
}
