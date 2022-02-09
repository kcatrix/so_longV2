#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		nombredeligne;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fake;
}				t_data;

int		main(int argc, char **argv);
int		parse(t_data *img, char *arg);
int		avance(char *arg);
int		verif_ber(char *arg, int i);
int		stock_map(t_data *img);
int		verif_map(char **str, t_data *img);

char	*get_next_line(int fd);

#endif
