#include <philo_fork.h>

static int	philo_block_fork(t_shared *shared, t_pinternal *local, int absfork,
					int *retval)
{
	long int		actionlen;

	*retval = F_OK_OP;
	while (1)
	{
		if (philo_did_any_die(shared) == P_OTHER_DEAD)
			return (*retval = P_OTHER_DEAD);
		if (philo_should_die(local, timestamp(), WAITFORFORK, &actionlen))
		{
			philo_mark_dead(local, shared, &actionlen, timestamp());
			usleep(actionlen * 1000);
			return (*retval = P_DEAD);
		}
		if (!shared || !shared->f_mutexes)
			return (*retval = P_OTHER_DEAD);
		pthread_mutex_lock(shared->f_mutexes[absfork]);
		if (shared->fork_available[absfork])
			break ;
		pthread_mutex_unlock(shared->f_mutexes[absfork]);
		usleep(actionlen * 1000);
	}
	return (*retval);
}

int	philo_take_right_fork(t_shared *shared, t_pinternal *local)
{
	int				ret;
	unsigned int	abs_rfork;

	abs_rfork = abs_right_fork(local);
	if (philo_did_any_die(shared) == P_OTHER_DEAD)
		return (P_OTHER_DEAD);
	if (local->fork_register[HRIGHT])
		return (F_IN_HAND_ALREADY);
	if (philo_block_fork(shared, local, abs_rfork, &ret))
		return (ret);
	shared->fork_available[abs_rfork] = 0;
	if (!shared || !shared->f_mutexes)
		return (P_OTHER_DEAD);
	pthread_mutex_unlock(shared->f_mutexes[abs_rfork]);
	local->fork_register[HRIGHT] = 1;
	print_and_maybe_wait(local, shared, FORK, abs_rfork + 1);
	return (ret);
}

int	philo_drop_right_fork(t_shared *shared, t_pinternal *local)
{
	int				ret;
	unsigned int	abs_rfork;

	abs_rfork = abs_right_fork(local);
	if (!local->fork_register[HRIGHT])
		return (F_NOT_IN_HAND_ALREADY);
	if (shared && shared->f_mutexes)
		pthread_mutex_lock(shared->f_mutexes[abs_rfork]);
	else
		return (P_OTHER_DEAD);
	if (!shared->fork_available[abs_rfork])
	{
		shared->fork_available[abs_rfork] = 1;
		local->fork_register[HRIGHT] = 0;
		ret = F_OK_OP;
		print_and_maybe_wait(local, shared, DFORK, abs_rfork + 1);
	}
	else
		ret = F_AVAILABLE_ALREADY;
	if (!shared || !shared->f_mutexes)
		return (P_OTHER_DEAD);
	pthread_mutex_unlock(shared->f_mutexes[abs_rfork]);
	return (ret);
}

int	philo_take_left_fork(t_shared *shared, t_pinternal *local)
{
	int				ret;
	unsigned int	abs_lfork;

	abs_lfork = abs_left_fork(local);
	if (local->fork_register[HLEFT])
		return (F_IN_HAND_ALREADY);
	if (philo_block_fork(shared, local, abs_lfork, &ret))
		return (ret);
	shared->fork_available[abs_lfork] = 0;
	if (shared && shared->f_mutexes)
		pthread_mutex_unlock(shared->f_mutexes[abs_lfork]);
	else
		return (P_OTHER_DEAD);
	local->fork_register[HLEFT] = 1;
	print_and_maybe_wait(local, shared, FORK, abs_lfork + 1);
	return (ret);
}

int	philo_drop_left_fork(t_shared *shared, t_pinternal *local)
{
	int				ret;
	unsigned int	abs_lfork;

	abs_lfork = abs_left_fork(local);
	if (!local->fork_register[HLEFT])
		return (F_NOT_IN_HAND_ALREADY);
	if (shared && shared->f_mutexes)
		pthread_mutex_lock(shared->f_mutexes[abs_lfork]);
	else
		return (P_OTHER_DEAD);
	if (!shared->fork_available[abs_lfork])
	{
		shared->fork_available[abs_lfork] = 1;
		local->fork_register[HLEFT] = 0;
		ret = F_OK_OP;
		print_and_maybe_wait(local, shared, DFORK, abs_lfork + 1);
	}
	else
		ret = F_AVAILABLE_ALREADY;
	if (shared && shared->f_mutexes)
		pthread_mutex_unlock(shared->f_mutexes[abs_lfork]);
	else
		return (P_OTHER_DEAD);
	return (ret);
}
