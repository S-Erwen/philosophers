/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:45:09 by esidelar          #+#    #+#             */
/*   Updated: 2021/11/29 17:49:31 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

#define JOIN_PHILO_ERR -10
#define EAT 1

int     	pthread_start(t_all *all)
{
	int		i;
	
	i = 0;
	all->setting.start_time = actual_time();
	pthread_mutex_lock(&all->setting.finish);
	while (i < all->setting.nb_philo)
	{
		pthread_create(&all->philo->routine, NULL, launch_routine,
			&all->philo[i++]);
	}
	i = -1;
	while (++i < all->setting.nb_philo)
		pthread_mutex_lock(&all->setting.finish);
	i = -1;
	while (++i < all->setting.nb_philo)
		if (pthread_join(all->philo[i].routine, NULL))
			return (call_err("JOIN_PHILO_ERR", all, JOIN_PHILO_ERR));
	return (0);
}

void		write_philo(t_philo *p, char *msg, int eat)
{
	p->stack_time = actual_time();
	if (eat)
		p->eat_time = p->stack_time;
	pthread_mutex_lock(&p->set->write_mutex);
	printf(msg,
		p->stack_time - p->set->start_time, p->nb);
	pthread_mutex_unlock(&p->set->write_mutex);
}

void        *time_to_die(void *t_data)
{
	int		i;
	t_philo *philo;

	philo = (t_philo *)t_data;
	while (philo->stack_time - philo->set->start_time < philo->set->time_die)
		ft_usleep(5);
	write_philo(philo, "&dms <%d> died\n", 0);
	philo->set->is_finish = 1;
	i = -1;
	while (++i < philo->set->nb_philo)
		pthread_mutex_unlock(&philo->set->finish);
	return (NULL);
}

void		*launch_routine(void *t_data)
{
	t_philo *philo;

	philo = (t_philo *)t_data;
	while (42)
	{
		write_philo(philo ,"&d <%d> is thinking\n", 0);
		pthread_create(&philo->death, NULL, time_to_die, philo);

		pthread_mutex_lock(&philo->right_fork);
		write_philo(philo ,"&d <%d> has taken a fork\n", 0);
		pthread_mutex_lock(philo->left_fork);
		write_philo(philo ,"&d <%d> has taken a fork\n", 0);

		write_philo(philo ,"&d <%d> is eating\n", EAT);
		ft_usleep(philo->set->time_eat * philo->set->nb_eat);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);

		write_philo(philo ,"&d <%d> is sleeping\n", 0);
		ft_usleep(philo->set->time_sleep);
	}
	return (0);
}
