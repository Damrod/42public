#include <utils.h>

static int	get_value(char queried, int base, int *retval)
{
	static const char	lookupl[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
	static const char	lookupu[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int					i;

	i = 0;
	while ((int)i < base && lookupl[i])
	{
		if (queried == lookupl[i] || queried == lookupu[i])
		{
			if (retval)
				return (*retval = i);
			return (i);
		}
		i++;
	}
	if (retval)
		*retval = -1;
	return (-1);
}

static int	is_multiplication_overflow(long int a, long int b)
{
	long int	result;

	if (a == 0 || b == 0)
		return (0);
	result = a * b;
	if (a == result / b)
		return (0);
	else
		return (1);
}

static long int	loop_strtol(int sign, char **endptr, int base)
{
	long int	oldresul;
	long int	resul;
	int			retval;

	resul = 0;
	while (get_value(**endptr, base, &retval) >= 0)
	{
		oldresul = resul;
		resul = base * resul + retval;
		(*endptr)++;
		if (resul < 0 || is_multiplication_overflow(oldresul, base))
		{
			if (!(resul == LONG_MIN
					&& get_value(**endptr, base, NULL) < 0) || sign > 0)
				set_myerrno(ERANGE);
			while (get_value(**endptr, base, NULL) >= 0)
				(*endptr)++;
			if (sign < 0)
				return (LONG_MIN);
			return (LONG_MAX);
		}
	}
	while (get_value(**endptr, base, NULL) >= 0)
		(*endptr)++;
	return (sign * resul);
}

static void	config_strtol(int *sign, char ***endptr, int *base)
{
	(*sign) = 1;
	while (***endptr == '\t' || ***endptr == '\n' || ***endptr == '\v'
		|| ***endptr == '\f' || ***endptr == '\r' || ***endptr == ' ')
		(**endptr)++;
	if (***endptr == '-')
	{
		(*sign) = -1;
		(**endptr)++;
	}
	else if (***endptr == '+')
		(**endptr)++;
	if (*base == 0)
	{
		if (***endptr == '0')
		{
			*base = 8;
			if ((**endptr)[1] == 'x' || (**endptr)[1] == 'X')
				*base = 16;
		}
		else
			*base = 10;
	}
}

long int	ft_strtol(const char *nptr, char **endptr, int base)
{
	int			sign;

	if (!endptr)
		endptr = (char **)&nptr;
	*endptr = (char *)nptr;
	if (base != 0 && (base < 2 || base > 36))
	{
		set_myerrno(EINVAL);
		return (0);
	}
	config_strtol(&sign, &endptr, &base);
	if (base == 16)
		if (**endptr == '0' && ((*endptr)[1] == 'x' || (*endptr)[1] == 'X'))
			(*endptr) += 2;
	return (loop_strtol(sign, endptr, base));
}
