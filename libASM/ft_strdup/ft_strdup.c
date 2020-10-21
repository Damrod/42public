#include <stdlib.h>

size_t ft_strlen(const char *str);

char	*ft_strdup(const char *s)
{
	char	*des;
	int		i;

	if (!(des = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(des + i) = *(s + i);
		i++;
	}
	*(des + i) = '\0';
	return (des);
}
