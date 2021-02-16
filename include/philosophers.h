/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:45:12 by esidelar          #+#    #+#             */
/*   Updated: 2021/02/16 14:02:29 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define ERROR_MALLOC -1
# define ERROR_FUNCTION -11
# define MS_MAX -10
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct		s_philo
{
	long			id_th;
	uint32_t		die;
	uint32_t		eat;
	uint32_t		sleep;
	uint32_t		must_eat;
	uint32_t		timebase;
	pthread_t		th;
	pthread_mutex_t	**mu;
	int				*fourch;
}					t_philo;

int					ft_atoi(const char *nptr);
int					ft_isnum(char *str);
int					parsing_arg(int ac, char **gv, t_philo *ph);

int					ft_sleep(useconds_t wait_ms, int nb, t_philo *ph,
						char *etat);
int					timesleep(struct timeval time, useconds_t ms, int nb,
						t_philo *ph);

#endif