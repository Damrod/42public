#ifndef PHILO_FORK_H
# define PHILO_FORK_H

# include "philo.h"
# include "philo_dead.h"
# include "utils.h"

int	philo_take_right_fork(t_shared *shared, t_pinternal *local);
int	philo_drop_right_fork(t_shared *shared, t_pinternal *local);
int	philo_take_left_fork(t_shared *shared, t_pinternal *local);
int	philo_drop_left_fork(t_shared *shared, t_pinternal *local);

#endif
