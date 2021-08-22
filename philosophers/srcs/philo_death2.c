#include <philo_dead.h>

int	philo_should_die(t_pinternal *local, long int abstime, long int actionlen,
					 long int *actionlendef)
{
	if (actionlendef)
	{
		*actionlendef = actionlen;
		if (*actionlendef <= 0)
			*actionlendef = 0;
	}
	if (abstime + actionlen - local->time_last_eat >= get_time_die())
	{
		if (actionlendef)
		{
			*actionlendef = local->time_last_eat + get_time_die() - abstime;
			if (*actionlendef <= 0)
				*actionlendef = 0;
		}
		return (EXIT_FAILURE);
	}
	return (F_OK_OP);
}

int	philo_did_any_die(t_shared *shared)
{
	int	retval;

	retval = F_OK_OP;
	pthread_mutex_lock(shared->death_mutex);
	if (shared->dead_register)
		retval = P_OTHER_DEAD;
	pthread_mutex_unlock(shared->death_mutex);
	return (retval);
}
