/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:19:20 by esidelar          #+#    #+#             */
/*   Updated: 2021/02/16 11:27:03 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int			timesleep(struct timeval time, useconds_t ms, int nb, t_philo *ph)
{
	useconds_t	diff;

	usleep(ms * 1000);
	if (gettimeofday(&time, NULL))
		return (ERROR_FUNCTION);
	return (0);
}

int			ft_sleep(useconds_t wait_ms, int nb, t_philo *ph, char *etat)
{
	struct timeval		time; 
	struct timezone		timezone;
	int					ms;

	if (!ph->timebase)
	{
		if (gettimeofday(&time, NULL))
			return (ERROR_FUNCTION);
		ph->timebase = time.tv_usec;
	}
	if ((ms = timesleep(time, wait_ms, nb, ph)) == ERROR_FUNCTION)
		return (-1);
	printf("%d %d %s\n", time.tv_usec - ph->timebase, nb, etat);
	return (0);
}
