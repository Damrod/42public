#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include "my_errno.h"
# define STHINK "is thinking"
# define SEAT "is eating"
# define SSLEEP "is sleeping"
# define SDIE "died"
# ifdef DBG
#  define SFORK "has taken fork number"
# else
#  define SFORK "has taken a fork"
# endif
# define SDFORK "has dropped fork number"
# define TIMESTAMP_WIDTH 15
# define WAITFORFORK 1

enum e_states {
	THINK,
	EAT,
	SLEEP,
	DIE,
	FORK,
	DFORK,
};

enum e_hands {
	HLEFT = 0,
	HRIGHT = 1
};

enum e_error {
	F_OK_OP,
	F_NOT_AVAILABLE,
	F_AVAILABLE_ALREADY,
	F_IN_HAND_ALREADY,
	F_NOT_IN_HAND_ALREADY,
	P_DEAD,
	P_OTHER_DEAD,
	P_TIME_IS_UP
};

typedef struct s_shared {
	char			*fork_available;
	pthread_mutex_t	**f_mutexes;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*print_mutex;
	char			dead_register;
}	t_shared;

typedef struct s_philothread {
	pthread_t		*self;
	long int		time_last_eat;
	unsigned int	selfno;
	int				times;
	char			fork_register[2];
}	t_pinternal;

typedef struct s_self {
	t_shared		*shared;
	pthread_t		*self;
	unsigned int	id;
}	t_self;

#endif
