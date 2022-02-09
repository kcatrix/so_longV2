/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:09:03 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/09 13:10:39 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse(t_data *img, char *arg)
{
	if(avance(arg) == 0)
	{
		write(1, "erreur dans le nom de la map", 28);
		return(0);
	}
	if (stock_map(img) == 0)
		return (0);
	return(1);
}

int	avance(char *arg)
{
	int i;

	i = 0;
	while(arg[i])
	{
		if(arg[i] == '.')
		{
			if (verif_ber(arg, i) == 0)
				return 0;
			else
				return(1);
		}
		i++;
	}
	return (0);
}

int	verif_ber(char *arg, int i)
{
	int j;
	int f;

	f = 0;
	j = i;
	while(arg[i])
	{
		i++;
		f++;
	}
	if(f > 4)
		return 0;
	if (arg[++j] != 'b')
		return 0;
	if (arg[++j] != 'e')
		return 0;
	if (arg[++j] != 'r')
		return 0;
	return(1);
}
