#include "include/philosophers.h"

#define PHILO_ALLOC 11

int 		main(int ac, char **gv)
{
	t_all	all;
	int 	code;

	if (!parsing_gv(ac, gv, &all.setting))
		return (call_err("ARG_ERROR", &all, 0));
	all.philo = malloc(sizeof(t_philo) * all.setting.nb_philo);
	if (!all.philo)
		return (call_err("MALLOC_ERR", &all, 0));
	if (init_philo(&all))
		return (call_err("INIT_PHILO_ERR", &all, PHILO_ALLOC));
	return ();
}

int			call_err(char *err, t_all *all, int f)
{
	printf("%s\n", err);
	if (f)
		if (f == PHILO_ALLOC)
			free(all->philo);
	return (-1);
}

int			init_philo(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->setting.nb_philo)
	{
		all->philo[i].nb = i + 1;
		i++;
	}
	return (0);
}
