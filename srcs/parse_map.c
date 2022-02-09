/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:29:40 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/09 14:46:16 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	stock_map(t_data *img)
{
	int fd;
	int i;
	int j;
	
	char **str;
	
	i = 0;
	
	fd = open("map/map.ber", O_RDWR);
	while(get_next_line(fd) != NULL)
		i++;
	close(fd);
	printf("%d\n", i);
	img->nombredeligne = i;
	str = malloc(sizeof(char *) * i);
	j = 0;
	fd = open("map/map.ber", O_RDWR);
	while(j < i)
	{
		str[j] = get_next_line(fd);
		j++;
	}
	close(fd);
	j = 0;
	while(j < i)
		printf("str = %s\n", str[j++]);
	/*if (verif_map(str, img) == 0)
		return (0);*/
	//printf()
	return (1);
}

int		verif_map(char **str, t_data *img)
{
	(void) str;
	(void) img;
	return (0);
}