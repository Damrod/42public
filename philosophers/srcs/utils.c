#include <utils.h>

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (long int)1000) + (time.tv_usec / 1000));
}

long int	timestamp(void)
{
	return (current_time() - get_start_time());
}

unsigned int	abs_left_fork(t_pinternal *local)
{
	if (!local->selfno)
		return (get_philono() - 1);
	else
		return (local->selfno - 1);
}

unsigned int	abs_right_fork(t_pinternal *local)
{
	return (local->selfno);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ret;
	size_t			req;

	req = nmemb * size;
	ret = malloc(req);
	if (!ret)
		return (NULL);
	memset(ret, 0, req);
	return ((void *)ret);
}
