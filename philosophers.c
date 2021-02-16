/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:45:09 by esidelar          #+#    #+#             */
/*   Updated: 2021/02/16 16:36:08 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void		terminus(t_philo *ph)
{
	free(ph->th);
	free(ph);
	exit(0);
}

void		*init(t_philo *ph, int nb)
{
	if (!(ph->fourch = malloc(sizeof(ph->id_th))))
		return ((void *)1);
	return (0);
}

void		*time_to_eat(t_philo *ph, int nb)
{
	int		i;

	dprintf(2, "HERE\n");
	pthread_mutex_init(ph->mu[i], NULL);
	dprintf(2, "HERE\n");
	pthread_mutex_lock(ph->mu[i]);
	pthread_mutex_lock(ph->mu[i]);
	ft_sleep(ph->eat, nb, ph, EAT);
	pthread_mutex_unlock(ph->mu[i]);
	pthread_mutex_unlock(ph->mu[i]);
	return (0);
}

void		*time_to_sleep(t_philo *ph, int nb)
{
	int		*i;

	if ((*i = pthread_mutex_init(ph->mu[*i], NULL)))
		return ((void *)i);
	pthread_mutex_lock(ph->mu[*i]);
	pthread_mutex_lock(ph->mu[*i]);
	ft_sleep(ph->eat, nb, ph, SLEEP);
	pthread_mutex_unlock(ph->mu[*i]);
	pthread_mutex_unlock(ph->mu[*i]);
	return (i);
}

void		*time_to_think(t_philo *ph, int nb)
{
	int		*i;

	if ((*i = pthread_mutex_init(ph->mu[*i], NULL)))
		return ((void *)i);
	pthread_mutex_lock(ph->mu[*i]);
	pthread_mutex_lock(ph->mu[*i]);
	ft_sleep(ph->eat, nb, ph, THINK);
	pthread_mutex_unlock(ph->mu[*i]);
	pthread_mutex_unlock(ph->mu[*i]);
	return (i);
}

int 		main(int ac, char **gv)
{
	t_philo		*ph;
	int 		code;
	int			i;

	if (ac < 5)
		printf("Even more ARG\n");
	if (ac > 6)
		printf("Many ARG\n");
	if (!(ph = malloc(sizeof(t_philo))))
		return (0);
	ph->timebase = 0;
	if (!(ph->th = malloc(sizeof(pthread_t))))
		(terminus(ph));
	if (!(ph->mu = malloc(sizeof(pthread_mutex_t *))))
		(terminus(ph));
	if ((parsing_arg(ac, gv, ph)) < 0)
		(terminus(ph));
	dprintf(2, "ID = [%ld]\nDIE = [%d]\nEAT = [%d]\nSLEEP = [%d]\nMUST_EAT = [%d]\n",
		ph->id_th, ph->die, ph->eat, ph->sleep, ph->must_eat);
	i = 0;
	if (pthread_create(&ph->th, NULL, init(ph, i), 0))
		terminus(ph);
	while (i < ph->id_th)
		if (!(ph->mu[i] = malloc(sizeof(pthread_t))))
			terminus(ph);
	i = 0;
	while (42)
	{
		dprintf(2, "== PASSHAUT ==\n");
		if (pthread_join(ph->th, time_to_eat(ph, i))
			|| (pthread_join(ph->th, time_to_sleep(ph, i)))
			|| (pthread_join(ph->th, time_to_think(ph, i))))
			terminus(ph);
		dprintf(2, "== PASS BAS ==\n");
		i++;
	}
}
