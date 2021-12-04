/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:45:09 by esidelar          #+#    #+#             */
/*   Updated: 2021/12/04 19:22:12 by esidelar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

#define JOIN_PHILO_ERR -10
#define EAT 1
#define DIE 2

int	pthread_start(t_all *all)
{
	int	i;

	i = -1;
	all->setting.is_finish = 0;
	all->setting.start_time = actual_time();
	while (++i < all->setting.nb_philo)
	{
		if (pthread_create(&all->philo[i].routine, NULL, launch_routine,
				&all->philo[i]))
			return (call_err("CREAT_PTHREAD_ERR", all, JOIN_PHILO_ERR));
	}
	if (pthread_mutex_destroy(&all->setting.death_mutex)
		&& pthread_mutex_destroy(&all->setting.finish)
		&& pthread_mutex_destroy(&all->setting.write_mutex))
		return (call_err("MUTEX_DESTROY_ERR", all, JOIN_PHILO_ERR));
	i = -1;
	while (++i < all->setting.nb_philo)
	{
		if (pthread_join(all->philo[i].routine, NULL)
			&& pthread_mutex_destroy(all->philo[i].right_fork))
			return (call_err("JOIN_PHILO_ERR", all, JOIN_PHILO_ERR));
	}
	if (!all->setting.nb_finish_eat)
		good_eat();
	return (0);
}

void	secure_write_philo(t_philo *p, char *msg)
{
	long	t;

	if (!p->set->is_finish)
	{
		pthread_mutex_lock(&p->set->write_mutex);
		t = actual_time();
		printf(msg,
			t - p->set->start_time, p->nb);
		pthread_mutex_unlock(&p->set->write_mutex);
	}
}

void	*time_to_die(void *t_data)
{
	t_philo	*philo;

	philo = (t_philo *)t_data;
	ft_usleep(philo->set->time_die);
	pthread_mutex_lock(&philo->set->finish);
	while (check_die(philo))
		ft_usleep(5);
	pthread_mutex_unlock(&philo->set->finish);
	return (NULL);
}

void	*launch_routine(void *t_data)
{
	t_philo	*philo;

	philo = (t_philo *)t_data;
	if (philo->nb % 2 == 0)
		ft_usleep(philo->set->time_eat / 10);
	while (check_die(philo))
	{
		pthread_create(&philo->death, NULL, time_to_die, philo);
		goto_eat(philo);
		if (philo->eating_count == philo->set->nb_eat)
		{
			philo->set->nb_finish_eat--;
			return (0);
		}
		goto_sleep_think(philo);
		pthread_detach(philo->death);
	}
	return (0);
}

void	good_eat(void)
{
	printf(BOLDGREEN "ALL PHILO have a good meal\n");
	ft_usleep(1000);
	printf(BOLDGREEN "No more spaghetti\n");
	ft_usleep(1000);
	printf(RED "Simulation end\n");
}
