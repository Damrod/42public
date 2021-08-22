#include <input_private.h>

t_input	*input_singleton(void)
{
	static t_input	input = {
		.start_time = -1,
		.philono = (unsigned int) -1,
		.time_die = (unsigned int) -1,
		.time_eat = (unsigned int) -1,
		.time_sleep = (unsigned int) -1,
		.times = -1
	};

	return (&input);
}

void	set_start_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	input_singleton()->start_time = time.tv_sec * (long int)1000
	+ (time.tv_usec / 1000);
}

long int	get_start_time(void)
{
	return (input_singleton()->start_time);
}
