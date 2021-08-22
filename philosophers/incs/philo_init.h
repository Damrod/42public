#ifndef PHILO_INIT_H
# define PHILO_INIT_H

# include "philo.h"
# include "input_setters.h"
# include "input_getters.h"
# include "utils.h"

int		configure_input(int argc, const char **argv);
int		shared_ctor(pthread_t **philos, t_shared **shared);
void	shared_dtor(pthread_t **philos, t_shared **shared);

#endif
