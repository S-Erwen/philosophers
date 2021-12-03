#include "include/philosophers.h"

#define DIE 2

int			check_die(t_philo *p)
{
	p->stack_time = actual_time();
	if (p->stack_time - p->eat_time >= p->set->time_die && !p->set->is_finish)
	{
		p->set->is_finish++;
		secrure_write_philo(p, RED "%dms - <%d>\t: died\n", DIE);
		return (0);
	}
	else if (p->set->is_finish)
		return (0);
	return (1);
}

void		check_sleep(t_philo *p, long add_time)
{
	p->stack_time = actual_time();
	if (((p->set->start_time - p->stack_time)
		- (p->set->start_time - p->eat_time) + add_time > p->set->time_die))
	{
		p->set->is_finish++;
	}
}
