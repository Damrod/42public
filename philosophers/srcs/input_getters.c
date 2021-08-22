#include <input_private.h>

unsigned int	get_philono(void)
{
	return (input_singleton()->philono);
}

unsigned int	get_time_die(void)
{
	return (input_singleton()->time_die);
}

unsigned int	get_time_eat(void)
{
	return (input_singleton()->time_eat);
}

unsigned int	get_time_sleep(void)
{
	return (input_singleton()->time_sleep);
}

int	get_times(void)
{
	return (input_singleton()->times);
}
