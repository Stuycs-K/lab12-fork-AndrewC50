#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
  printf("\033[38;5;226m%d\033[0m about to create \033[38;5;196m2\033[0m child processes\n", getpid());
  pid_t p1, p2;
  p1 = fork();
  // printf("%d\n", p1);
  if(p1 < 0){
    perror("fork fail");//output to stderr instead of stdout
    exit(1);
  } else if(p1 == 0) {
      srand(getpid());
      int timer = rand() % 5 + 1;
      printf("\033[38;5;226m%d %d\033[0m sec\n", getpid(), timer);
      sleep(timer);
      printf("\033[38;5;226m%d\033[0m finished after \033[38;5;226m%d\033[0m sec\n", getpid(), timer);
  } else if(p1 > 0) {
      p2 = fork();
      if(p2 < 0){
        perror("fork fail");//output to stderr instead of stdout
        exit(1);
      } else if(p2 == 0) {
        srand(getpid());
        int timer = rand() % 5 + 1;
        printf("\033[38;5;226m%d %d\033[0m sec\n", getpid(), timer);
        sleep(timer);
        printf("\033[38;5;226m%d\033[0m finished after \033[38;5;226m%d\033[0m sec\n", getpid(), timer);
      } else {
        int * status;
        wait(status);
        printf("%d\n", WEXITSTATUS(*status));
      }

  }
  return 0;
}
