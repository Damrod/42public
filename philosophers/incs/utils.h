#ifndef UTILS_H
# define UTILS_H
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>
# include "philo.h"
# include "input_getters.h"
# include "my_errno.h"

# define ERANGE 34
# define EINVAL 22

long int		ft_strtol(const char *nptr, char **endptr, int base);
long int		current_time(void);
long int		timestamp(void);
unsigned int	abs_left_fork(t_pinternal *local);
unsigned int	abs_right_fork(t_pinternal *local);
void			*ft_calloc(size_t nmemb, size_t size);

#endif
