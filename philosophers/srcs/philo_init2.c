#include <philo_init.h>

static int	ft_strtol_error_checking(const char *nptr, int idx)
{
	static	void	(*setters [4])(unsigned int) = {
		set_philono,
		set_time_die,
		set_time_eat,
		set_time_sleep,
	};
	char			*where;
	long int		retval;

	reset_myerrno();
	retval = ft_strtol(nptr, &where, 10);
	if (get_myerrno() || *where || retval <= 0)
		return (EXIT_FAILURE);
	if (idx < 4)
		setters[idx](retval);
	else
		set_times(retval);
	return (EXIT_SUCCESS);
}

int	configure_input(int argc, const char **argv)
{
	int			i;
	long int	time;

	set_start_time();
	i = 1;
	while (i < 5)
	{
		if (ft_strtol_error_checking(argv[i], i - 1))
			return (EXIT_FAILURE);
		i++;
	}
	if (argc == 6)
		if (ft_strtol_error_checking(argv[5], 4))
			return (EXIT_FAILURE);
	if (get_philono() < 2)
	{
		time = current_time() - get_start_time();
		printf("%*li %u %s\n", TIMESTAMP_WIDTH, time, 1, SFORK);
		usleep(get_time_die() * 1000);
		printf("%*li %u %s\n", TIMESTAMP_WIDTH, time + get_time_die(), 1, SDIE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	shared_ctor(pthread_t **philos, t_shared **shared)
{
	unsigned int	philono;

	*shared = ft_calloc(1, sizeof(**shared));
	if (!(*shared))
		return (EXIT_FAILURE);
	philono = get_philono();
	*philos = ft_calloc(philono, sizeof(**philos));
	(*shared)->f_mutexes = ft_calloc(philono, sizeof(*(*shared)->f_mutexes));
	(*shared)->fork_available = ft_calloc(philono,
			sizeof(*(*shared)->fork_available));
	(*shared)->death_mutex = ft_calloc(1, sizeof(*(*shared)->death_mutex));
	(*shared)->print_mutex = ft_calloc(1, sizeof(*(*shared)->print_mutex));
	if (!(*shared)->print_mutex
		|| !(*shared)->f_mutexes || !(*shared)->death_mutex
		|| !(*shared)->fork_available || !*philos)
		return (EXIT_FAILURE);
	memset((*shared)->fork_available, 1, philono);
	(*shared)->dead_register = 0;
	return (EXIT_SUCCESS);
}

void	shared_dtor(pthread_t **philos, t_shared **shared)
{
	unsigned int	philono;
	unsigned int	i;

	free(*philos);
	free((*shared)->fork_available);
	free((*shared)->death_mutex);
	free((*shared)->print_mutex);
	philono = get_philono();
	i = 0;
	while (i < philono)
	{
		if ((*shared)->f_mutexes)
		{
			free((*shared)->f_mutexes[i]);
			(*shared)->f_mutexes[i] = NULL;
		}
		i++;
	}
	free((*shared)->f_mutexes);
	(*shared)->f_mutexes = NULL;
	free(*shared);
	*philos = NULL;
	*shared = NULL;
}
