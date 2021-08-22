#include <philo_entry.h>

static int	drop_forks(t_shared *shared, t_pinternal *local,
			int *retval, int nbr)
{
	int	ret1;
	int	ret2;

	if (local->selfno)
	{
		ret1 = philo_drop_right_fork(shared, local) != F_AVAILABLE_ALREADY;
		ret2 = philo_drop_left_fork(shared, local) != F_AVAILABLE_ALREADY;
	}
	else
	{
		ret2 = philo_drop_left_fork(shared, local) != F_AVAILABLE_ALREADY;
		ret1 = philo_drop_right_fork(shared, local) != F_AVAILABLE_ALREADY;
	}
	(void)ret1;
	(void)ret2;
	*retval = nbr;
	return (nbr);
}

static int	take_forks(t_shared *shared, t_pinternal *local)
{
	int	ret1;
	int	ret2;

	if (local->selfno && !(get_philono() & 1))
	{
		ret1 = philo_take_right_fork(shared, local);
		ret2 = philo_take_left_fork(shared, local);
	}
	else
	{
		ret2 = philo_take_left_fork(shared, local);
		ret1 = philo_take_right_fork(shared, local);
	}
	if (ret1 == P_DEAD || ret2 == P_DEAD)
		return (P_DEAD);
	if (ret1 == P_OTHER_DEAD || ret2 == P_OTHER_DEAD)
		return (P_OTHER_DEAD);
	return (EXIT_SUCCESS);
}

static int	eat(t_shared *shared, t_pinternal *local, int *retval)
{
	int	locretval;

	locretval = take_forks(shared, local);
	if (locretval)
		return (drop_forks(shared, local, retval, locretval));
	if (local->fork_register[0] && local->fork_register[1]
		&& philo_did_any_die(shared) != P_OTHER_DEAD)
		locretval = print_and_maybe_wait(local, shared, EAT, 0);
	if (locretval == P_DEAD)
		return (drop_forks(shared, local, retval, P_DEAD));
	if (locretval == P_OTHER_DEAD)
		return (drop_forks(shared, local, retval, P_OTHER_DEAD));
	if (local->times > 0)
		local->times--;
	if (!(local->times))
		return (drop_forks(shared, local, retval, P_TIME_IS_UP));
	return (drop_forks(shared, local, retval, F_OK_OP));
}

static int	philo_loop(t_shared *shared, t_pinternal *local)
{
	int	retval;

	retval = EXIT_SUCCESS;
	while (1)
	{
		if (eat(shared, local, &retval) != F_OK_OP)
			break ;
		if (philo_did_any_die(shared) == P_OTHER_DEAD)
			return (P_OTHER_DEAD);
		retval = print_and_maybe_wait(local, shared, SLEEP, 0);
		if (retval != F_OK_OP)
			break ;
		if (philo_did_any_die(shared) == P_OTHER_DEAD)
			return (P_OTHER_DEAD);
		print_and_maybe_wait(local, shared, THINK, 0);
		if (philo_did_any_die(shared) == P_OTHER_DEAD)
			return (P_OTHER_DEAD);
	}
	return (retval);
}

void	*entry(void *data)
{
	t_pinternal		local;
	t_shared		*shared;
	int				*retval;

	if (get_times() > 0)
		local.times = get_times();
	else
		local.times = -1;
	local.time_last_eat = timestamp();
	memset(local.fork_register, '\0', 2);
	shared = ((t_self *)data)->shared;
	local.selfno = ((t_self *)data)->id;
	local.self = ((t_self *)data)->self;
	free(data);
	retval = NULL;
	if (((get_philono() & 1) && !(local.selfno & 1))
		|| (!(get_philono() & 1) && (local.selfno & 1)))
		usleep(get_time_die() * 10);
	if (philo_loop(shared, &local) == P_DEAD)
	{
		print_and_maybe_wait(&local, shared, DIE, 0);
		retval = (void *)EXIT_FAILURE;
	}
	return (retval);
}
