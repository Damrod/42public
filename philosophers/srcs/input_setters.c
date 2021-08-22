#include <input_private.h>

void	set_philono(unsigned int philono)
{
	input_singleton()->philono = philono;
}

void	set_time_die(unsigned int time_die)
{
	input_singleton()->time_die = time_die;
}

void	set_time_eat(unsigned int time_eat)
{
	input_singleton()->time_eat = time_eat;
}

void	set_time_sleep(unsigned int time_sleep)
{
	input_singleton()->time_sleep = time_sleep;
}

void	set_times(int times)
{
	input_singleton()->times = times;
}
