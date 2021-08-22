#ifndef PHILO_DEAD_H
# define PHILO_DEAD_H

# include "philo.h"
# include "input_getters.h"
# include "utils.h"
# include <stdlib.h>

int		philo_should_die(t_pinternal *local, long int abstime,
			long int actionlen, long int *actionlendef);
int		philo_did_any_die(t_shared *shared);
int		print_and_maybe_wait(t_pinternal *local, t_shared *shared,
			enum e_states state, int nbr);
int		philo_mark_dead(t_pinternal *local, t_shared *shared,
			long int *actionlen, long int abstime);

#endif
