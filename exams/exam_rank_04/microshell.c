/* This is my solution for the microshell exam at 42 school.
  It is somehow partially inspired, yet improved upon,
  Nicolas Colomer's solution for the same task
Copyright (C) 2021 Alvaro Ollero

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor,
Boston, MA  02110-1301, USA. */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define SIDE_IN 1
#define SIDE_OUT 0

int ft_strlen(char *str)
{
	char *orig = str;
	while(*str)
		str++;
	return str - orig;
}

int ft_puts(char *str)
{
	if (!str)
		return 0;
	if (write(2, str, ft_strlen(str)) == -1)
		exit(1);
	return 1;
}

void exit_fatal(char *msg, int lineno)
{
	(void)msg; // these are here for debugging purpouses.
	(void)lineno; // I've come to accept that I will generally have to
	// debug any program that I write in one go under tight time
	// constraints. This makes my life easier.
	ft_puts("error: fatal\n");
	exit(1);
}

int mychdir(char **paths)
{
	if (!paths)
		return ft_puts("error: cd: bad arguments\n");
	unsigned int i = 0;
	while(paths[i])
		i++;
	if (i != 2)
		return ft_puts("error: cd: bad arguments\n");
	if (chdir(paths[1]))
	{
		ft_puts("error: cd: cannot change directory to ");
		ft_puts(paths[1]);
		return ft_puts("\n");
	}
	return 0;
}

int exec_program(char *token, char ***myarg, char **environ)
{
	int pno = ft_strlen(token);
	pid_t pid;
	int pipes[pno][2];
	int pipe_open[pno];
	int status;
	int ret = 0;
	int i = 0;

	while (i < pno)
	{
		pipe_open[i] = 0;
		if (!myarg[i][0])
		{
			i++;
			continue;
		}
		if (!strcmp(myarg[i][0], "cd"))
		{
			ret = mychdir(myarg[i]);
			i++;
			continue;
		}
		if(token[i] == '|')
		{
			pipe_open[i] = 1;
			if (pipe(pipes[i]))
				exit_fatal("pipe", __LINE__);
		}
		pid = fork();
		if (pid < 0)
			exit_fatal("fork", __LINE__);
		if (!pid)
		{
			if (pipe_open[i])
			{
				if (dup2(pipes[i][SIDE_IN], STDOUT_FILENO) < 0)
					exit_fatal("dup2", __LINE__);
			}
			if (i > 0 && pipe_open[i - 1])
			{
				if (dup2(pipes[i - 1][SIDE_OUT], STDIN_FILENO) < 0)
					exit_fatal("dup2", __LINE__);
			}
			if ((ret = execve(myarg[i][0], myarg[i], environ)) < 0)
			{
				ft_puts("error: cannot execute ");
				ft_puts(myarg[i][0]);
				ft_puts("\n");
				ret = 127;
			}
			exit(ret);
		}
		else
		{
			if(token[i] == ';')
			{
				if (waitpid(pid, &status, 0) == -1)
					exit_fatal("waitpid", __LINE__);
				if (WIFEXITED(status))
					ret = WEXITSTATUS(status);

			}
			if (pipe_open[i])
			{
				if (close(pipes[i][SIDE_IN]))
					exit_fatal("close", __LINE__);
			}
			if (i > 0 && pipe_open[i - 1])
			{
				if (close(pipes[i - 1][SIDE_OUT]))
					exit_fatal("close", __LINE__);
			}
		}
		i++;
	}
	return ret;
}

int main(int argc, char **argv, char **environ)
{
	int i = 1;
	int j = 0;
	char token[argc]; // We don't like free store memory
	char **myarg[argc]; // We don't like free store memory
	int ret = 0;
	char **oldarg;

	if (argc < 2)
		return ret;
	oldarg = &argv[1];
	while (i < argc)
	{
		if (!strcmp(argv[i], "|") || !strcmp(argv[i], ";"))
		{
			if (i < argc - 1)
			{
				myarg[j] = oldarg;
				token[j++] = argv[i][0];
				oldarg = &argv[i + 1];
			}
			argv[i] = NULL;
		}
		i++;
	}
	myarg[j] = oldarg;
	myarg[j + 1] = NULL;
	token[j] = ';';
	token[j + 1] = '\0';
	ret = exec_program(token, myarg, environ);
	// while (1); // to check fd leaks with lsof -c microshell
	// if this loop is enabled, the program has to be killed to recover
	// the terminal running it
	return ret;
}

// compile as $ clang -Wall -Wextra -Werror -o microshell microshell.c
