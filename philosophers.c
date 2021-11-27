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

void     	pthread_start(t_all *all)
{
	int		i = 0;
	
	i = 0;
	all->setting.start_time = actual_time();
	pthread_mutex_lock(&all->setting.finish);
	while (i < all->setting.nb_philo)
	{
		pthread_create(all->philo->routine, NULL, launch_routine,
			&all->philo[i++]);
	}
	i = -1;
	while (++i < all->setting.nb_philo)
		pthread_mutex_lock(&all->setting.finish);
}

void        time_to_die(t_philo *philo)
{
	int		i;

	while (philo->stack_time - philo->set->start_time < philo->set->time_die)
		ft_usleep(5);
	printf("&dms <%d> died\n",
		philo->stack_time - philo->set->start_time, philo->nb);
	philo->set->is_finish = 1;
	i = -1;
	while (++i < philo->set->nb_philo)
		pthread_mutex_unlock(&philo->set->finish);
}

void		launch_routine(t_philo *philo)
{
	while (42)
	{
		philo->stack_time = actual_time();
		printf("&d <%d> is eating\n",
			philo->stack_time - philo->set->start_time, philo->nb);
		ft_usleep(philo->set->time_eat * philo->set->nb_eat);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);

		philo->stack_time = actual_time();
		printf("&d <%d> is sleeping\n",
			philo->stack_time - philo->set->start_time, philo->nb);
		ft_usleep(philo->set->time_sleep);

		philo->stack_time = actual_time();
		printf("&d <%d> is thinking\n",
			philo->stack_time - philo->set->start_time, philo->nb);
		pthread_create(philo->death, NULL, time_to_die, philo);

		philo->stack_time = actual_time();
		pthread_mutex_lock(&philo->right_fork);
		printf("&d <%d> has taken a fork\n",
			philo->stack_time - philo->set->start_time, philo->nb);
		pthread_mutex_lock(philo->left_fork);
		printf("&d <%d> has taken a fork\n",
			philo->stack_time - philo->set->start_time, philo->nb);
	}
}
