#include <philo_dead.h>

static const char	*g_actions[6] =
{
	STHINK,
	SEAT,
	SSLEEP,
	SDIE,
	SFORK,
	SDFORK
};

#ifdef DBG

static void	locked_print(t_pinternal *local, t_shared *shared,
			enum e_states state, int nbr)
{
	pthread_mutex_lock(shared->print_mutex);
	if (state == FORK || state == DFORK)
		printf("%*li %u %s %d\n", TIMESTAMP_WIDTH, timestamp(),
			local->selfno + 1, g_actions[state], nbr);
	else
		printf("%*li %u %s\n", TIMESTAMP_WIDTH, timestamp(), local->selfno + 1,
			g_actions[state]);
	pthread_mutex_unlock(shared->print_mutex);
}

#else

static void	locked_print(t_pinternal *local, t_shared *shared,
			enum e_states state, int nbr)
{
	pthread_mutex_lock(shared->print_mutex);
	if (state != DFORK)
		printf("%*li %u %s\n", TIMESTAMP_WIDTH, timestamp(), local->selfno + 1,
			g_actions[state]);
	(void) nbr;
	pthread_mutex_unlock(shared->print_mutex);
}

#endif

int	philo_mark_dead(t_pinternal *local, t_shared *shared,
					long int *actionlen, long int abstime)
{
	*actionlen = local->time_last_eat + get_time_die() - abstime;
	if (*actionlen < 0)
		*actionlen = 0;
	pthread_mutex_lock(shared->death_mutex);
	shared->dead_register = 1;
	pthread_mutex_unlock(shared->death_mutex);
	return (P_DEAD);
}

int	print_and_maybe_wait(t_pinternal *local, t_shared *shared,
			enum e_states state, int nbr)
{
	long int			abstime;
	long int			actionlen;
	static unsigned	int	(*getters [6])(void) = {NULL, get_time_eat,
		get_time_sleep, NULL, NULL,	NULL};
	int					retval;

	retval = F_OK_OP;
	actionlen = -1;
	if (getters[state])
		actionlen = getters[state]();
	abstime = timestamp();
	if (state == EAT)
		local->time_last_eat = abstime;
	if (getters[state] && philo_should_die(local, abstime, actionlen, NULL))
		retval = philo_mark_dead(local, shared, &actionlen, abstime);
	locked_print(local, shared, state, nbr);
	if (getters[state])
	{
		if (retval != P_DEAD && philo_did_any_die(shared) == P_OTHER_DEAD)
			return (P_OTHER_DEAD);
		usleep(actionlen * 1000);
	}
	return (retval);
}
