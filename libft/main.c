#include "libft.h"
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <errno.h>
#include <fcntl.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s2 == *s1 && *s1 != '\0')
	{
		s2++;
		s1++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

static int		hexres_len(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len = 1;
	while (len < 14 && n / 16 != 0)
	{
		len++;
		n /= 16;
	}
	return (len + 1);
}

static char		*hexft_itoa(size_t nbr, char *resul, int *b)
{
	static const char base[16] = "0123456789abcdef";

	if (nbr > 16 - 1)
		hexft_itoa(nbr / 16, resul, b);
	resul[(*b)++] = base[nbr % 16];
	resul[(*b)] = '\0';
	return (resul);
}

char			*ft_itohex(long unsigned int n)
{
	char	*res;
	int		b;

	b = 0;
	res = malloc(sizeof(*res) * ((hexres_len(n)) + 1));
	if (res == NULL)
		return (NULL);
	else
		hexft_itoa(n, res, &b);
	return (res);
}

void	wrtptr(void *ptr)
{
	char *cptr;
	unsigned int i;

	cptr = ft_itohex((size_t)ptr);
	write (1, "0x", 2);
	i = strlen(cptr);
	while (i < 12)
	{
		write(1, "0", 1);
		i++;
	}
	write (1, cptr, strlen(cptr));
	free (cptr);
}

int		main_memset(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	void *strorig;
	void *strcp;
	size_t len;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	len = strlen(argv[2]);
	strorig = memset(argv[2], argv[3][0], atoi(argv[4]));
	write (1, "memset: ", 8);
	wrtptr(strorig);
	write(1, " \"", 2);
	write(1, strorig, len);
	strcp = ft_memset(argv2[2], argv2[3][0], atoi(argv2[4]));
	write(1, "\"\n", 2);
	write (1, "ft_memset: ", 11);
	wrtptr(strcp);
	write(1, " \"", 2);
	write(1, strcp, len);
	write(1, "\"\n", 2);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_bzero(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	size_t len;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	len = strlen(argv[2]);
	bzero(argv[2], atoi(argv[3]));
	write(1, "bzero: ", 7);
	wrtptr(argv[2]);
	write(1, ": ", 2);
	write(1, argv[2], len);
	write(1, "\n", 1);
	ft_bzero(argv2[2], atoi(argv2[3]));
	write(1, "ft_bzero: ", 10);
	wrtptr(argv2[2]);
	write(1, ": ", 2);
	write(1, argv[2], len);
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_memcpy(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	size_t len;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	len = strlen(argv[2]);
	memcpy(argv[2], argv[3], atoi(argv[4]));
	write(1, "memcpy: ", 8);
	wrtptr(argv[2]);
	write(1, ": ", 2);
	write(1, argv[2], len);
	write(1, "\n", 1);
	ft_memcpy(argv2[2], argv2[3], atoi(argv2[4]));
	write(1, "ft_memcpy: ", 10);
	wrtptr(argv2[2]);
	write(1, ": ", 2);
	write(1, argv2[2], len);
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_memccpy(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	size_t len;
	char *ptr1;
	char *ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	len = strlen(argv[3]);
	ptr1 = memccpy(argv[2], argv[3], (int)argv[4][0], atoi(argv[5]));
	write(1, "memccpy: ", 9);
	wrtptr(argv[2]);
	write(1, ": ", 2);
	write(1, argv[2], len);
	if (ptr1 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr1, strlen(ptr1));
	}
	write(1, "\n", 1);
	ptr2 = ft_memccpy(argv2[2], argv2[3], (int)argv2[4][0], atoi(argv2[5]));
	write(1, "ft_memccpy: ", 12);
	wrtptr(argv2[2]);
	write(1, ": ", 2);
	write(1, argv2[2], len);
	if (ptr2 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr2, strlen(ptr2));
	}
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_memmove(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	size_t len;
	char *ptr1;
	char *ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	len = strlen(argv[3]);
	ptr1 = memmove(argv[2], argv[3], atoi(argv[4]));
	write(1, "memmove: ", 9);
	wrtptr(argv[2]);
	write(1, ": ", 2);
	write(1, argv[2], len);
	if (ptr1 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr1, strlen(ptr1));
	}
	write(1, "\n", 1);
	ptr2 = ft_memmove(argv2[2], argv2[3], atoi(argv2[4]));
	write(1, "ft_memmove: ", 12);
	wrtptr(argv2[2]);
	write(1, ": ", 2);
	write(1, argv2[2], len);
	if (ptr2 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr2, strlen(ptr2));
	}
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_memchr(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	size_t len;
	char *ptr1;
	char *ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	len = strlen(argv[3]);
	ptr1 = memchr(argv[2], argv[3][0], atoi(argv[4]));
	write(1, "memchr: ", 8);
	wrtptr(argv[2]);
	write(1, ": ", 2);
	write(1, argv[2], len);
	if (ptr1 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr1, strlen(ptr1));
	}
	write(1, "\n", 1);
	ptr2 = ft_memchr(argv2[2], argv2[3][0], atoi(argv2[4]));
	write(1, "ft_memchr: ", 11);
	wrtptr(argv2[2]);
	write(1, ": ", 2);
	write(1, argv2[2], len);
	if (ptr2 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr2, strlen(ptr2));
	}
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_memcmp(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	int ptr1;
	int ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	ptr1 = memcmp(argv[2], argv[3], atoi(argv[4]));
	write(1, "memcmp: ", 8);
	ft_putnbr(ptr1);
	write(1, "\n", 1);
	ptr2 = ft_memcmp(argv2[2], argv2[3], atoi(argv2[4]));
	write(1, "ft_memcmp: ", 11);
	ft_putnbr(ptr2);
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_strlen(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	size_t len;
	size_t len2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	len = strlen(argv[2]);
	write(1, "strlen: ", 8);
	ft_putnbr(len);
	write(1, "\n", 1);
	len2 = ft_strlen(argv2[2]);
	write(1, "ft_strlen: ", 11);
	ft_putnbr(len2);
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_strlcpy(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	int ptr1;
	int ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	ptr1 = strlcpy(argv[2], argv[3], atoi(argv[4]));
	write(1, "strlcpy: ", 9);
	ft_putnbr(ptr1);
	write(1, ": ", 2);
	write(1, argv[2], strlen(argv[2]));
	write(1, "\n", 1);
	ptr2 = ft_strlcpy(argv2[2], argv2[3], atoi(argv2[4]));
	write(1, "ft_strlcpy: ", 12);
	ft_putnbr(ptr2);
	write(1, ": ", 2);
	write(1, argv2[2], strlen(argv2[2]));
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_strlcat(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	int ptr1;
	int ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	ptr1 = strlcat(argv[2], argv[3], atoi(argv[4]));
	write(1, "strlcat: ", 9);
	ft_putnbr(ptr1);
	write(1, ": ", 2);
	write(1, argv[2], strlen(argv[2]));
	write(1, "\n", 1);
	ptr2 = ft_strlcat(argv2[2], argv2[3], atoi(argv2[4]));
	write(1, "ft_strlcat: ", 12);
	ft_putnbr(ptr2);
	write(1, ": ", 2);
	write(1, argv2[2], strlen(argv2[2]));
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_strchr(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	char *ptr1;
	char *ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	ptr1 = strchr(argv[2], argv[3][0]);
	write(1, "strchr: ", 8);
	wrtptr(argv[2]);
	if (ptr1 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr1, strlen(ptr1));
	}
	write(1, "\n", 1);
	ptr2 = ft_strchr(argv2[2], argv2[3][0]);
	write(1, "ft_strchr: ", 11);
	wrtptr(argv2[2]);
	if (ptr2 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr2, strlen(ptr2));
	}
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_strrchr(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	char *ptr1;
	char *ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	ptr1 = strrchr(argv[2], argv[3][0]);
	write(1, "strrchr: ", 9);
	wrtptr(argv[2]);
	if (ptr1 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr1, strlen(ptr1));
	}
	write(1, "\n", 1);
	ptr2 = ft_strrchr(argv2[2], argv2[3][0]);
	write(1, "ft_strrchr: ", 12);
	wrtptr(argv2[2]);
	if (ptr2 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr2, strlen(ptr2));
	}
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_strnstr(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	char *ptr1;
	char *ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	ptr1 = strnstr(argv[2], argv[3], atoi(argv[4]));
	write(1, "strnstr: ", 9);
	wrtptr(argv[2]);
	if (ptr1 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr1, strlen(ptr1));
	}
	write(1, "\n", 1);
	ptr2 = ft_strnstr(argv2[2], argv2[3], atoi(argv2[4]));
	write(1, "ft_strnstr: ", 12);
	wrtptr(argv2[2]);
	if (ptr2 != NULL)
	{
		write(1, ": ", 2);
		write(1, ptr2, strlen(ptr2));
	}
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_strncmp(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	int ptr1;
	int ptr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	ptr1 = strncmp(argv[2], argv[3], atoi(argv[4]));
	write(1, "strncmp: ", 9);
	ft_putnbr(ptr1);
	write(1, "\n", 1);
	ptr2 = ft_strncmp(argv2[2], argv2[3], atoi(argv2[4]));
	write(1, "ft_strncmp: ", 12);
	ft_putnbr(ptr2);
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_atoi(int argc, char **argv)
{
	int i;
	char *argv2[argc];
	size_t nbr;
	size_t nbr2;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	nbr = atoi(argv[2]);
	write(1, "atoi: ", 6);
	ft_putnbr_fd(nbr, 1);
	write(1, "\n", 1);
	nbr2 = ft_atoi(argv2[2]);
	write(1, "ft_atoi: ", 9);
	ft_putnbr_fd(nbr2, 1);
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	return (0);
}

int		main_is(int argc, char **argv)
{
	char is;
	char toc;
	char yes[] = "Yes";
	char no[] = "No";

	if (argc < 3)
	{
		write(1, "Missing input\n", 14);
		return (1);
	}
	toc = argv[2][0];
	if (ft_strcmp(argv[1], "ft_isalpha") == 0)
		is = ft_isalpha((int)toc);
	else if (ft_strcmp(argv[1], "ft_isdigit") == 0)
		is = ft_isdigit((int)toc);
	else if (ft_strcmp(argv[1], "ft_isalnum") == 0)
		is = ft_isalnum((int)toc);
	else if (ft_strcmp(argv[1], "ft_isascii") == 0)
		is = ft_isascii((int)toc);
	else if (ft_strcmp(argv[1], "ft_isprint") == 0)
		is = ft_isprint((int)toc);
	else if (ft_strcmp(argv[1], "ft_toupper") == 0)
	{
		is = ft_toupper((int)toc);
		write(1, &is, 1);
		write(1, "\n", 1);
		return (0);
	}
	else if (ft_strcmp(argv[1], "ft_tolower") == 0)
	{
		is = ft_tolower((int)toc);
		write(1, &is, 1);
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		write(1, "Missing input\n", 14);
		return (1);
	}
	write(1, (is == 0 ? no : yes), (is == 0 ? 2 : 3));
	write(1, "\n", 1);
	return (0);
}

int		main_calloc(int argc, char **argv)
{
	void *ptr;
	void *ptr2;
	char *argv2[argc];
	size_t totlen;
	size_t totlen2;
	int i;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	// NORMAL, SHOWS ZEROES
	totlen = atoi(argv[2]) * atoi(argv[3]);
	ptr = calloc(atoi(argv[2]), atoi(argv[3]));
	write(1, "calloc: ", 8);
	wrtptr(ptr);
	write(1, ": ", 2);
	write(1, ptr, totlen);
	write(1, "\n", 1);
	// COPY, SHOWS ZEROES
	totlen2 = atoi(argv2[2]) * atoi(argv2[3]);
	ptr2 = ft_calloc(atoi(argv2[2]), atoi(argv2[3]));
	write(1, "ft_calloc: ", 11);
	wrtptr(ptr2);
	write(1, ": ", 2);
	write(1, ptr2, totlen2);
	write(1, "\n", 1);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	free(ptr);
	free(ptr2);
	return (0);
}

int		main_strdup(int argc, char **argv)
{
	char *ptr;
	char *ptr2;
	char *argv2[argc];
	int i;

	i = 0;
	while (i < argc)
	{
		argv2[i] = strdup(argv[i]);
		i++;
	}
	ptr = strdup(argv[2]);
	write(1, "strdup: ", 8);
	wrtptr(ptr);
	write(1, ": \"", 3);
	write(1, ptr, strlen(ptr));
	write(1, "\"\n", 2);
	ptr2 = ft_strdup(argv2[2]);
	write(1, "ft_strdup: ", 11);
	wrtptr(ptr2);
	write(1, ": \"", 3);
	write(1, ptr2, strlen(ptr2));
	write(1, "\"\n", 2);
	i = 0;
	while (i < argc)
	{
		free(argv2[i]);
		i++;
	}
	free(ptr);
	free(ptr2);
	return (0);
}

int main_substr(int argc, char **argv)
{
	char *str;

	if(argc != 5)
		return (1);
	str = ft_substr(argv[2], atoi(argv[3]), atoi(argv[4]));
	write(1, str, strlen(str));
	write(1, "\n", 1);
	free (str);
	return (0);
}

int main_strjoin(int argc, char **argv)
{
	char *str;

	if(argc != 4)
		return (1);
	str = ft_strjoin(argv[2], argv[3]);
	write(1, str, strlen(str));
	write(1, "\n", 1);
	free (str);
	return (0);
}

int		main_strtrim(int argc, char **argv)
{
	char *str;

	if(argc != 4)
		return (1);
	str = ft_strtrim(argv[2], argv[3]);
	write(1, "\"", 1);
	write(1, str, strlen(str));
	write(1, "\"\n", 2);
	free (str);
	return (0);
}

int main_split(int argc, char **argv)
{
	int i;
	char **tab;

	if (argc != 4)
		return (1);
	tab = ft_split(argv[2], argv[3][0]);
	i = 0;
	while (tab[i])
	{
		printf("\"%s\" : ", tab[i]);
		free(tab[i]);
		i++;
	}
	printf("substrings no.: %d\noriginal unmodified string: \"%s\"\n", i, argv[2]);
	free (tab);
	return (0);
}

int main_itoa(int argc, char **argv)
{
	char *str;

	if(argc != 3)
		return (1);
	str = ft_itoa(atoi(argv[2]));
	write(1, str, strlen(str));
	write(1, "\n", 1);
	free (str);
	return (0);
}

char		ft_testtoupper(unsigned int i, char c)
{
	if ('a' <= c && c <= 'z' && i % 3 == 0)
		c = c - 32;
	return (c);
}

int main_strmapi(int argc, char **argv)
{
	char *str;

	if (argc != 3)
		return (1);
	str = ft_strmapi(argv[2], &ft_testtoupper);
	write(1, str, ft_strlen(str));
	free (str);
	write(1, "\n", 1);
	return (0);
}

int main_putchar_fd(int argc, char **argv)
{
	int fd;

	if (argc != 4)
		return (1);
	fd = open(argv[2], O_RDWR);
	ft_putchar_fd(argv[3][0], fd);
	close(fd);
	write(1, "\n", 1);
	return (0);
}

int main_putstr_fd(int argc, char **argv)
{
	int fd;

	if (argc != 4)
		return (1);
	fd = open(argv[2], O_RDWR);
	ft_putstr_fd(argv[3], fd);
	close(fd);
	write(1, "\n", 1);
	return (0);
}

int main_putendl_fd(int argc, char **argv)
{
	int fd;

	if (argc != 4)
		return (1);
	fd = open(argv[2], O_RDWR);
	ft_putendl_fd(argv[3], fd);
	close(fd);
	return (0);
}

int main_putnbr_fd(int argc, char **argv)
{
	int fd;
	int nbr;

	if (argc != 4)
		return (1);
	nbr = atoi(argv[3]);
	fd = open(argv[2], O_RDWR);
	ft_putnbr_fd(nbr, fd);
	close(fd);
	return (0);
}

int main (int argc, char **argv)
{
	if (argc < 3)
		return (1);
	if (ft_strcmp(argv[1], "ft_memset") == 0)
		return (main_memset(argc, argv));
	else if (ft_strcmp(argv[1], "ft_bzero") == 0)
		return (main_bzero(argc, argv));
	else if (ft_strcmp(argv[1], "ft_memcpy") == 0)
		return (main_memcpy(argc, argv));
	else if (ft_strcmp(argv[1], "ft_memccpy") == 0)
		return (main_memccpy(argc, argv));
	else if (ft_strcmp(argv[1], "ft_memmove") == 0)
		return (main_memmove(argc, argv));
	else if (ft_strcmp(argv[1], "ft_memchr") == 0)
		return (main_memchr(argc, argv));
	/* else if (ft_strcmp(argv[1], "ft_memrchr") == 0) */
	/* 	return (main_memrchr(argc, argv)); */
	else if (ft_strcmp(argv[1], "ft_memcmp") == 0)
		return (main_memcmp(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strlen") == 0)
		return (main_strlen(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strlcpy") == 0)
		return (main_strlcpy(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strlcat") == 0)
		return (main_strlcat(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strchr") == 0)
		return (main_strchr(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strrchr") == 0)
		return (main_strrchr(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strnstr") == 0)
		return (main_strnstr(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strncmp") == 0)
		return (main_strncmp(argc, argv));
	else if (ft_strcmp(argv[1], "ft_atoi") == 0)
		return (main_atoi(argc, argv));
	else if ((ft_strcmp(argv[1], "ft_isalpha") == 0) ||
			 (ft_strcmp(argv[1], "ft_isdigit") == 0) ||
			 (ft_strcmp(argv[1], "ft_isalnum") == 0) ||
			 (ft_strcmp(argv[1], "ft_isascii") == 0) ||
			 (ft_strcmp(argv[1], "ft_isprint") == 0) ||
			 (ft_strcmp(argv[1], "ft_toupper") == 0) ||
			 (ft_strcmp(argv[1], "ft_tolower") == 0))
		return (main_is(argc,argv));
	else if (ft_strcmp(argv[1], "ft_calloc") == 0)
		return (main_calloc(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strdup") == 0)
		return (main_strdup(argc, argv));
	else if (ft_strcmp(argv[1], "ft_substr") == 0)
		return (main_substr(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strjoin") == 0)
		return (main_strjoin(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strtrim") == 0)
		return (main_strtrim(argc, argv));
	else if (ft_strcmp(argv[1], "ft_split") == 0)
		return (main_split(argc, argv));
	else if (ft_strcmp(argv[1], "ft_itoa") == 0)
		return (main_itoa(argc, argv));
	else if (ft_strcmp(argv[1], "ft_strmapi") == 0)
		return (main_strmapi(argc, argv));
	else if (ft_strcmp(argv[1], "ft_putchar_fd") == 0)
		return (main_putchar_fd(argc, argv));
	else if (ft_strcmp(argv[1], "ft_putstr_fd") == 0)
		return (main_putstr_fd(argc, argv));
	else if (ft_strcmp(argv[1], "ft_putendl_fd") == 0)
		return (main_putendl_fd(argc, argv));
	else if (ft_strcmp(argv[1], "ft_putnbr_fd") == 0)
		return (main_putnbr_fd(argc, argv));
}
