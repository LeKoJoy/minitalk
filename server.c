#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void sig_handle(int sig, siginfo_t *info, void *context)
{
	static char c = 0;
	static int i = -1;

	(void)context;
	if (i < 0)
		i = 7;
	if (sig == SIGUSR1)
		c |= 1 << i;
	else if (sig == SIGUSR2)
		c &= ~(1 << i);
	if (!i && c)
		write(1, &c, 1);
	else if (!i && !c)
		kill(info->si_pid, SIGUSR2);
	i--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sigact;

	ft_putstr("Server PID: ");
	ft_putnbr_fd(getpid(), 1);
	ft_putstr("\n");
	sigact.sa_sigaction = sig_handle;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&sigact.sa_mask);
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	while (1)
		sleep(1);
}
