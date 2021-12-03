/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:45:09 by esidelar          #+#    #+#             */
/*   Updated: 2021/12/03 19:18:18 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

#define JOIN_PHILO_ERR -10
#define EAT 1
#define DIE 2

int     	pthread_start(t_all *all)
{
	int		i;
	
	i = 0;
	all->setting.is_finish = 0;
	all->setting.start_time = actual_time();
	while (i < all->setting.nb_philo && !all->setting.is_finish)
	{
		if (pthread_create(&all->philo->routine, NULL, launch_routine,
			&all->philo[i++]))
			return (call_err("CREAT_PTHREAD_ERR", all, JOIN_PHILO_ERR));
	}
	while (!all->setting.is_finish)
		ft_usleep(5);
	i = -1;
	while (++i < all->setting.nb_philo)
		pthread_mutex_lock(&all->setting.finish);
	i = -1;
	while (++i < all->setting.nb_philo)
	{
		if (pthread_join(all->philo[i].routine, NULL)
			&& pthread_mutex_destroy(&all->philo[i].right_fork))
			return (call_err("JOIN_PHILO_ERR", all, JOIN_PHILO_ERR));
	}
	return (0);
}

void		secrure_write_philo(t_philo *p, char *msg, int eat)
{
	long t;
	
	if (!p->set->is_finish || eat == DIE)
	{
		pthread_mutex_lock(&p->set->write_mutex);
		t = actual_time();
		if (eat == EAT)
			p->eat_time = t;
		printf(msg,
			t - p->set->start_time, p->nb);
		pthread_mutex_unlock(&p->set->write_mutex);
	}
}

void        *time_to_die(void *t_data)
{
	t_philo *philo;

	philo = (t_philo *)t_data; 
	pthread_mutex_lock(&philo->set->finish);
	while (check_die(philo))
		ft_usleep(5);
	pthread_mutex_unlock(&philo->set->finish);
	return (NULL);
}

void		take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	secrure_write_philo(philo, YELLOW "%dms - <%d>\t: has taken a fork\n", 0);
}

int			goto_eat(t_philo *philo)
{
	secrure_write_philo(philo, BOLDGREEN "%dms - <%d>\t: is eating\n", EAT);
	ft_usleep(philo->set->time_eat);
	if (philo->set->arg && !philo->set->nb_eat--)
	{
		secrure_write_philo(philo, RED "Simulation stop at %dms\n\
			<%d> eating last spaghetti\n", 0);
		philo->set->is_finish++;
		pthread_detach(philo->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

void		goto_sleep_think(t_philo *philo)
{
		secrure_write_philo(philo, GRAY "%dms - <%d>\t: is sleeping\n", 0);
		ft_usleep(philo->set->time_sleep);
		secrure_write_philo(philo, GRAY "%dms - <%d>\t: is thinking\n", 0);
}

void		*launch_routine(void *t_data)
{
	t_philo *philo;

	philo = (t_philo *)t_data;
	philo->stack_time = actual_time();
	while (!philo->set->is_finish)
	{
		pthread_create(&philo->death, NULL, time_to_die, philo);
		take_fork(philo);
		if (goto_eat(philo))
			return (0);
		goto_sleep_think(philo);
		pthread_detach(philo->death);
	}
	return (0);
}
	