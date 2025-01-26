#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void print_pid()
{
  ft_printf("PID: %d\n", getpid());
}

int main(void)
{
  struct sigaction str_sigact;

  print_pid();
  
}
