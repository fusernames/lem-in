#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_room {
	int				id;
	char			name[255];
	int				x;
	int				y;
	int				type;
	struct s_room	*next;
}				t_room;

typedef	struct	s_pipe {
	t_room			*room[2];
	struct s_pipe	*next;
}				t_pipe;

typedef struct	s_ant {
	int				id;
	s_room			*room;
	struct s_ant	*next;
}

#endif
