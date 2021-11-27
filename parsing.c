/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:19:59 by esidelar          #+#    #+#             */
/*   Updated: 2021/11/26 15:34:57 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int			parsing_gv(int ac, char **gv, t_set *set)
{
	int		i;

	if (ac < 4 || ac > 5)
	{
		printf("Many or even more ARG\n");
		return (-1);
	}
	i = 1;
	if ((set->nb_philo = ft_isnum(gv[i++])) == -1)
		return (-1);
	if ((set->time_die = ft_isnum(gv[i++])) == -1)
		return (-1);
	if ((set->time_eat = ft_isnum(gv[i++])) == -1)
		return (-1);
	if ((set->time_sleep = ft_isnum(gv[i++])) == -1)
		return (-1);
	if (ac == 6)
		if ((set->nb_eat = ft_isnum(gv[i++])) == -1)
			return (-1);
	set->nb_eat = -1;
	if (set->nb_philo < 2 || set->time_die <= 0 || set->time_eat <= 0
		|| set->time_sleep <= 0)
		return (-1);
	return (0);
}
