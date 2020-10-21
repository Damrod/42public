unsigned long	ft_strlen(char *str)
{
	char *src;

	src = str;
	while (*str)
		str++;
	return ((unsigned long)(str - src));
}
