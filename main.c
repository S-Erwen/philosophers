/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:44:54 by esidelar          #+#    #+#             */
/*   Updated: 2021/12/04 18:50:36 by esidelar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

#define PHILO_ALLOC -11
#define ALL_ALLOC -10

int	main(int ac, char **gv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (call_err("MALLOC_ERR00", all, 0));
	if (parsing_gv(ac, gv, &all->setting))
		return (call_err("ARG_ERROR", all, 0));
	all->philo = malloc(sizeof(t_philo) * all->setting.nb_philo);
	if (!all->philo)
		return (call_err("MALLOC_ERR01", all, ALL_ALLOC));
	if (init_philo(all->philo, &all->setting))
		return (call_err("INIT_PHILO_ERR", all, PHILO_ALLOC));
	return (pthread_start(all));
}

int	call_err(char *err, t_all *all, int f)
{
	printf("%s\n", err);
	if (f)
	{
		if (f == PHILO_ALLOC)
		{
			free(all);
			free(all->philo);
		}
		else if (f == ALL_ALLOC)
			free(all);
	}
	return (-1);
}

int	init_philo(t_philo *philo, t_set *set)
{
	int		i;

	i = 0;
	set->start_time = actual_time();
	while (i < set->nb_philo)
	{
		philo[i].set = set;
		philo[i].eat_time = set->start_time;
		philo[i].nb = i + 1;
		philo[i].eating_count = 0;
		philo[i].right_fork = NULL;
		if (pthread_mutex_init(&philo[i].left_fork, NULL))
			return (0);
		if (set->nb_philo == 1)
			return (0);
		if (i == set->nb_philo - 1)
			philo[i].right_fork = &philo[0].left_fork;
		else
			philo[i].right_fork = &philo[i + 1].left_fork;
		i++;
	}
	return (0);
}
