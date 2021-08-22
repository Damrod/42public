#include <philo_entry.h>
#include <philo_init.h>

static int	mutexes_init(t_shared *shared)
{
	unsigned int	philono;
	unsigned int	i;

	set_start_time();
	if (pthread_mutex_init(shared->death_mutex, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(shared->print_mutex, NULL))
		return (EXIT_FAILURE);
	philono = get_philono();
	if (!shared->f_mutexes)
		return (EXIT_FAILURE);
	i = 0;
	while (i < philono)
	{
		shared->f_mutexes[i] = malloc(sizeof(*shared->f_mutexes[i]));
		if (!shared->f_mutexes[i])
			return (EXIT_FAILURE);
		if (pthread_mutex_init(shared->f_mutexes[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	threads_init(pthread_t **philos, t_shared *shared)
{
	unsigned int	i;
	unsigned int	philono;
	t_self			*self;

	philono = get_philono();
	i = 0;
	while (i < philono)
	{
		self = ft_calloc(1, sizeof(*self));
		self->id = i;
		self->self = &(*philos)[i];
		self->shared = shared;
		if (pthread_create(&(*philos)[i], NULL, entry, self))
		{
			free(self);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	threads_terminate(pthread_t **philos)
{
	unsigned int	i;
	unsigned int	philono;
	int				*retval;

	philono = get_philono();
	i = 0;
	while (i < philono)
	{
		if (pthread_join((*philos)[i], (void **)&retval))
			return (EXIT_FAILURE);
		if (retval)
			break ;
		i++;
	}
	if (retval)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	program_init(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (configure_input(argc, (const char **)argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	pthread_t		*philos;
	t_shared		*shared;

	if (program_init(argc, argv))
		return (EXIT_FAILURE);
	if (shared_ctor(&philos, &shared))
		return (EXIT_FAILURE);
	if (mutexes_init(shared))
	{
		shared_dtor(&philos, &shared);
		return (EXIT_FAILURE);
	}
	if (threads_init(&philos, shared))
	{
		shared_dtor(&philos, &shared);
		return (EXIT_FAILURE);
	}
	if (threads_terminate(&philos))
	{
		shared_dtor(&philos, &shared);
		return (EXIT_FAILURE);
	}
	shared_dtor(&philos, &shared);
	return (EXIT_SUCCESS);
}
