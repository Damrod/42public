#ifndef INPUT_PRIVATE_H
# define INPUT_PRIVATE_H

# include <sys/time.h>
# include <stdlib.h>

typedef struct s_data {
	long int		start_time;
	unsigned int	philono;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				times;
}	t_input;

t_input	*input_singleton(void);

#endif
