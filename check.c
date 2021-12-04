#include "include/philosophers.h"

#define DIE 2

int			check_die(t_philo *p)
{
	long int time;

	time = actual_time();
	if (!p->set->is_finish && time - p->eat_time >= p->set->time_die)
	{
		pthread_mutex_lock(&p->set->death_mutex);
		if (p->set->is_finish)
			return (0);
		secure_write_philo(p, RED "%dms - <%d>\t: died\n");
		p->set->is_finish++;
		return (0);
	}
	else if (p->set->is_finish)
		return (0);
	return (1);
}
