#include <signal.h>

int main(int argc, char *argv[])
{
  pid_t   pid;
  char    str;
  int     i;

  if (argc != 3 || argv[1] == "-1")
	{
    server_pid = ft_atoi(argv[1]);
    if(argv[1] == "-1")
    {
      ft_printf("Haha nice try");
      exit(0)
    }
    else
		{
      ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		  exit(0);
	  }
  }
  server_pid = ft_atoi(argv[1]);
  str = argv[1];
  i = 0;
  while (message[i])
    sig_handle(pid, message[i++]);
  sig_handle(pid, '\0');
  return (0);
}
