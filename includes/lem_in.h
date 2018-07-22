#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_data {
	t_list		*rooms;
	t_list		*ants;
	t_list		*pipes;
	t_list		*paths;
	t_list		*combs;
}				t_data;

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

int		ft_parser(t_list **room, t_list **pipe, t_list **ant);
int		ft_check_exceptions(t_list *rooms, t_list *pipes);
t_list	*ft_find_path(t_room *room, t_list *pipe);

t_room	*ft_find_room_by_name(t_list *start, char *name);
t_room	*ft_find_room_by_type(t_list *start, int type);

int		ft_create_room(char *line, int type, t_list **room);
int		ft_create_pipe(char *line, t_list **pipe, t_list **room);
int		ft_create_ant(int nb_ants, t_list **ant, t_list **room);
int		ft_create_path(t_list **path, t_room *room);

int		ft_find_comb(t_list *paths, t_list *path, t_list **comb, t_list *current_comb);

int		ft_clean(t_data *data);

#endif
