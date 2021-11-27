/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:45:09 by esidelar          #+#    #+#             */
/*   Updated: 2021/11/26 16:12:40 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// void		terminus(t_philo *ph)
// {
// 	free(ph->th);
// 	free(ph);
// 	exit(0);
// }

// void		*init(t_philo *ph, int nb)
// {
// 	if (!(ph->fourch = malloc(sizeof(ph->id_th))))
// 		return ((void *)1);
// 	return (0);
// }

// void		*time_to_eat(t_philo *ph, int nb)
// {
// 	int		i;

// 	dprintf(2, "HERE\n");
// 	pthread_mutex_init(ph->mu[i], NULL);
// 	dprintf(2, "HERE\n");
// 	pthread_mutex_lock(ph->mu[i]);
// 	pthread_mutex_lock(ph->mu[i]);
// 	ft_sleep(ph->eat, nb, ph, EAT);
// 	pthread_mutex_unlock(ph->mu[i]);
// 	pthread_mutex_unlock(ph->mu[i]);
// 	return (0);
// }

// void		*time_to_sleep(t_philo *ph, int nb)
// {
// 	int		*i;

// 	if ((*i = pthread_mutex_init(ph->mu[*i], NULL)))
// 		return ((void *)i);
// 	pthread_mutex_lock(ph->mu[*i]);
// 	pthread_mutex_lock(ph->mu[*i]);
// 	ft_sleep(ph->eat, nb, ph, SLEEP);
// 	pthread_mutex_unlock(ph->mu[*i]);
// 	pthread_mutex_unlock(ph->mu[*i]);
// 	return (i);
// }

// void		*time_to_think(t_philo *ph, int nb)
// {
// 	int		*i;

// 	if ((*i = pthread_mutex_init(ph->mu[*i], NULL)))
// 		return ((void *)i);
// 	pthread_mutex_lock(ph->mu[*i]);
// 	pthread_mutex_lock(ph->mu[*i]);
// 	ft_sleep(ph->eat, nb, ph, THINK);
// 	pthread_mutex_unlock(ph->mu[*i]);
// 	pthread_mutex_unlock(ph->mu[*i]);
// 	return (i);
// }

