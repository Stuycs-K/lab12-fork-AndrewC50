#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
  printf("\033[38;5;226m%d\033[0m about to create \033[38;5;196m2\033[0m child processes\n", getpid());
  pid_t p = fork();
  printf("%d", p);
  return 0;
}
