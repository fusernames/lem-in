#include "lem_in.h"

int		main(void)
{
	t_room	*room;
	t_pipe	*pipe;
	t_ant	*ant;

	if (ft_parser(&room, &pipe, &ant))
		exit(1);
	// path = ft_find_path(room, pipe);
	// boucle (1)
	// faire bouger de 1 de toute les salles
	// faire choisir un chemain les fourmis du start
	return (0);
}
