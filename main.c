#include "include/philosophers.h"

#define PHILO_ALLOC -11
#define ALL_ALLOC -10

int 		main(int ac, char **gv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (call_err("MALLOC_ERR00", all, 0));
	if (parsing_gv(ac, gv, &all->setting))
		return (call_err("ARG_ERROR", all, 0));
	all->philo = malloc(sizeof(t_philo) * all->setting.nb_philo);
	if (!all->philo)
		return (call_err("MALLOC_ERR01", all, ALL_ALLOC));
	if (init_philo(all->philo, &all->setting))
		return (call_err("INIT_PHILO_ERR", all, PHILO_ALLOC));
	return (pthread_start(all));
}

int			call_err(char *err, t_all *all, int f)
{
	printf("%s\n", err);
	if (f)
	{
		if (f == PHILO_ALLOC)
		{
			free(all);
			free(all->philo);
		}
		else if (f == ALL_ALLOC)
			free(all);
	}
	return (-1);
}

int			init_philo(t_philo *philo, t_set *set)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i <= set->nb_philo)
	{
		if (i < set->nb_philo)
		{
			set->start_time = actual_time();
			philo[i].eat_time = actual_time();
			philo[i].nb = i + 1;
			philo[i].eating_count = 1;
			philo[i].set = set;
			ret = pthread_mutex_init(&philo[i].right_fork, NULL);
			if (i)
				philo[i].left_fork = &philo[i - 1].right_fork;
		}
		else
			philo[0].left_fork = &philo[i].right_fork;
		i++;
	}
	return (0);
}
