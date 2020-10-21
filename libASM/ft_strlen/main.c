#include <stdio.h>

long unsigned int ft_strlen(char *str);

int main (int argc, char **argv)
{
  printf("%lu\n", ft_strlen(argv[1]));
}
