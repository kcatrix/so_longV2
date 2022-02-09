/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:58:37 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/09 14:30:06 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	deal_key(int key, t_data *img)
{
	img->fake = 0;
	if(key == 53)
		exit('exit');
	return (0);
}


static char	*ft_sstrjoin(char *s, char c)
{
	char	*out;
	int		n;

	n = 2;
	if (s)
		while (*s && s++)
			n++;
	out = malloc(n * sizeof(char));
	out[--n] = '\0';
	out[--n] = c;
	if (s)
	{
		while (n--)
			out[n] = *--s;
		free(s);
	}
	return (out);
}

char	*get_next_line(int fd)
{
	char		c;
	static char	*line = NULL;

	if (line)
		free(line);
	line = NULL;
	while (read(fd, &c, 1) && (c != '\n' || line == NULL))
	{
		if (c == '\n')
			continue ;
		line = ft_sstrjoin(line, c);
	}
	return (line);
}

int	main(int argc, char **argv)
{
	t_data	img;
	if (argc != 2)
		return (0);
	parse(&img, argv[1]);
	/*
	int 	x;
	//int		img_width;
	//int		img_height;
	//char	*relative_path = "/Users/kcatrix/Downloads/Sprite.xpm";

	x = 500;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while(x != 1920)
	{
		my_mlx_pixel_put(&img, x, 500, 0x0000FF00);
		//mlx_loop_hook(img.mlx, render_next_frame(&img), &img);
		x++;
	}
	//img.img = mlx_xpm_file_to_image(img.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 200, 200);
	mlx_key_hook(img.mlx_win, deal_key, &img);
	mlx_loop(img.mlx);*/
}
