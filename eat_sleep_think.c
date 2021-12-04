/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:19:11 by esidelar          #+#    #+#             */
/*   Updated: 2021/12/04 19:19:12 by esidelar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	goto_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	secure_write_philo(philo, YELLOW "%dms - <%d>\t: has taken a left fork\n");
	if (philo->right_fork == NULL)
	{
		ft_usleep(philo->set->time_die * 2);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	secure_write_philo(philo, YELLOW "%dms - <%d>\t: has taken a right fork\n");
	secure_write_philo(philo, BOLDGREEN "%dms - <%d>\t: is eating\n");
	philo->eat_time = actual_time();
	ft_usleep(philo->set->time_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	philo->eating_count++;
	return (0);
}

void	goto_sleep_think(t_philo *philo)
{
	long int	i;

	i = philo->set->time_sleep;
	secure_write_philo(philo, GRAY "%dms - <%d>\t: is sleeping\n");
	while (i > philo->set->time_die)
	{
		ft_usleep(philo->set->time_die);
		i -= philo->set->time_die;
		if (philo->set->is_finish)
			return ;
	}
	ft_usleep(i);
	secure_write_philo(philo, GRAY "%dms - <%d>\t: is thinking\n");
}
