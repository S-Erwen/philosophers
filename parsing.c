/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:19:59 by esidelar          #+#    #+#             */
/*   Updated: 2021/02/16 11:20:15 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int			parsing_arg(int ac, char **gv, t_philo *ph)
{
	int		i;

	i = 1;
	if ((ph->id_th = ft_isnum(gv[i++])) == -1)
		return (-1);
	if ((ph->die = ft_isnum(gv[i++])) == -1)
		return (-1);
	if ((ph->eat = ft_isnum(gv[i++])) == -1)
		return (-1);
	if ((ph->sleep = ft_isnum(gv[i++])) == -1)
		return (-1);
	if (ac == 6)
	{
		if ((ph->must_eat = ft_isnum(gv[i++])) == -1)
			return (-1);
	}
	else
		ph->must_eat = -1;
	return (0);
}
