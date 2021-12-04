/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:45:12 by esidelar          #+#    #+#             */
/*   Updated: 2021/12/04 16:29:41 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"
# define BOLDGREEN "\033[1;32m"
# define GRAY "\033[30;1m"

typedef struct		s_set
{
	long int		time_eat;
	long int		time_sleep;
	long int		time_die;
	int				nb_eat;
	int				nb_philo;
	int				nb_finish_eat;
	int				is_finish;
	long int		start_time;
	pthread_mutex_t	finish;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	death_mutex;
}					t_set;

typedef struct		s_philo
{
	int				nb;
	long int		eat_time;
	int				eating_count;
	pthread_t		routine;
	pthread_t		death;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	t_set			*set;
}					t_philo;

typedef struct		s_all
{
	t_set			setting;
	t_philo			*philo;
}					t_all;

int					call_err(char *err, t_all *all, int f);
int					init_philo(t_philo *philo, t_set *set);

int					parsing_gv(int ac, char **gv, t_set *set);
int					init_setting(int ac, char **gv, t_set *set);

long int			actual_time(void);
void				ft_usleep(long int time_in_ms);

int     			pthread_start(t_all *all);
void				secure_write_philo(t_philo *p, char *msg);
void        		*time_to_die(void *t_data);
int					goto_eat(t_philo *philo);
void				goto_sleep_think(t_philo *philo);
void				*launch_routine(void *t_data);
void				good_eat();

int					check_die(t_philo *p);

int					ft_atoi(const char *nptr);
int					ft_isnum(char *str);

#endif