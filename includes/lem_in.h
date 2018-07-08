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
}				t_room;

typedef	struct	s_pipe {
	t_room			*room[2];
}				t_pipe;

typedef struct	s_ant {
	int				id;
	t_room			*room;
}				t_ant;

typedef struct	s_path {
	t_room			*room;
}				t_path;

int		ft_parser(t_list **room, t_list **pipe, t_list **ant);
t_list	*ft_find_path(t_room *room, t_list *pipe);

t_room	*ft_find_room_by_name(t_list *start, char *name);
t_room	*ft_find_room_by_type(t_list *start, int type);
t_room	*ft_path_contains(t_pipe *pipe_x, t_list *current_path, t_room *room);
int		ft_path_is_in_comb(t_list *comb, t_list *path);

int		ft_create_room(char *line, int type, t_list **room);
int		ft_create_pipe(char *line, t_list **pipe, t_list **room);
int		ft_create_ant(int nb_ants, t_list **ant, t_list **room);
int		ft_create_path(t_list **path, t_room *room);

#endif
