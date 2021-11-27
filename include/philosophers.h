/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:45:12 by esidelar          #+#    #+#             */
/*   Updated: 2021/11/26 16:18:46 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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
	int				nb;
	long int		stack_time;
	int				eating_count;
	pthread_t		routine;
	pthread_t		death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	t_set			*set;
}					t_philo;

typedef struct		s_set
{
	long int		time_eat;
	long int		time_sleep;
	long int		time_die;
	int				nb_eat;
	int				nb_philo;
	int				is_finish;
	long int		start_time;
	pthread_mutex_t	finish;
	pthread_mutex_t	write_mutex;
}					t_set;

typedef struct		s_all
{
	t_set			setting;
	t_philo			*philo;
}					t_all;

int					call_err(char *err, t_all *all, int f);
int					init_philo(t_philo *philo);

int					parsing_gv(int ac, char **gv, t_set *set);

long int			actual_time(void);
void				ft_usleep(long int time_in_ms);

#endif