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
	char		*str;
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

int		ft_parser(t_data *data);
int		ft_check_exceptions(t_data *data);

t_list	*ft_find_path(t_room *room, t_list *pipe);

t_room	*ft_find_room_by_name(t_list *start, char *name);
t_room	*ft_find_room_by_type(t_list *start, int type);

int		ft_create_room(char *line, int type, t_data *data);
int		ft_create_pipe(char *line, t_data *data);
int		ft_create_ant(int nb_ants, t_data *data);
int		ft_create_path(t_list **path, t_room *room);

int		ft_find_comb(t_list *paths, t_list *path, t_list **comb, t_list *current_comb);

int		ft_free_data(t_data *data);
int		ft_travel(t_data *data);
int		ft_choose_path(t_data *data);
int		ft_print_move(t_ant *ant);
void	ft_error(char *str, t_data *data);
void	ft_print_data(t_data *data);
char	*ft_strjoin2(char *s1, char *s2);

#endif
