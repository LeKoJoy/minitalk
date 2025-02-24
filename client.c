#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>//Be aware, not all libraries are needed
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}
int sent = 0;

void waiter(int sig)
{
	if (sig == SIGUSR1)
		sent = 1;
	else if (sig == SIGUSR2)
	{
		printf("Message received!\n");
		exit(EXIT_SUCCESS);
	}
}

void process_char(pid_t pid, char c)
{
	int i = 7;

	while (i >= 0)
	{
		sent = 0;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		while (sent != 1)
			usleep(10);
	}
}

void process_message(pid_t pid, char *message)
{
	int i = 0;
	while (message[i] != '\0')
	{
		process_char(pid, message[i]);
		i++;
	}
	process_char(pid, 0);
}

int main(int argc, char **argv)
{
	pid_t pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if(pid <= 0)
		{
			write(1, "Invalid pid", 12);
			return 0;
		}
		signal(SIGUSR1, &waiter);
		signal(SIGUSR2, &waiter);
		process_message(pid, argv[2]);
	}
	else
		write(1, "Usage is ./client pid message", 30);
	return 0;
}
