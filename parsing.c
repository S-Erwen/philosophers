/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:19:59 by esidelar          #+#    #+#             */
/*   Updated: 2021/12/04 18:56:52 by esidelar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	parsing_gv(int ac, char **gv, t_set *set)
{
	if (ac < 5 || ac > 6)
	{
		printf("Many or even more ARG\n");
		return (-1);
	}
	if (init_setting(ac, gv, set))
		return (-1);
	if (pthread_mutex_init(&set->finish, NULL)
		|| pthread_mutex_init(&set->write_mutex, NULL)
		|| pthread_mutex_init(&set->death_mutex, NULL))
		return (-1);
	return (0);
}

int	init_setting(int ac, char **gv, t_set *set)
{
	int	i;

	i = 1;
	set->nb_philo = ft_isnum(gv[i++]);
	set->time_die = ft_isnum(gv[i++]);
	set->time_eat = ft_isnum(gv[i++]);
	set->time_sleep = ft_isnum(gv[i++]);
	if (set->nb_philo <= 0 || set->time_die <= 0 || set->time_eat <= 0
		|| set->time_sleep <= 0)
		return (-1);
	if (ac == 6)
	{
		set->nb_eat = ft_isnum(gv[i++]);
		if (set->nb_eat <= 0)
			return (-1);
		set->nb_finish_eat = set->nb_philo;
	}
	else
	{
		set->nb_finish_eat = -1;
		set->nb_eat = -1;
	}
	return (0);
}
