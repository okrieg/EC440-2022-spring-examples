#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int children = 0;
void do_something(int signo)
{
  int status, pid;

  fprintf (stderr, "\n-- got signal\n");
  while ((pid = waitpid(0, &status, WNOHANG))>0){
    if( WIFEXITED(status))
      fprintf (stderr, "child %d exit %d\n", pid, WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
      fprintf(stderr, "child %d kill by %d\n", pid, WTERMSIG(status));
    children--;
  }
  fprintf(stderr, "-- done signal handler\n");

}

void init_sigaction()
{
  struct sigaction act;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  act.sa_handler = do_something;
  sigaction(SIGCHLD, &act, NULL);
}

void child_function(int seconds)
{
  fprintf(stderr, "child with pid %d sleeping %d seconds\n", getpid(), seconds);
  sleep(seconds);
  exit(0);
}

#define FAST_SLEEP 2
#define SLOW_SLEEP 20
#define FAST_CHILDREN 3
#define SLOW_CHILDREN 2

int main()
{
  pid_t pid;
  int i;

  init_sigaction();
  
  children = FAST_CHILDREN + SLOW_CHILDREN;
  // start three fast children
  for (i=0; i<FAST_CHILDREN; i++ ) {
    pid = fork();
    if (pid==0) {
      child_function(FAST_SLEEP);
    }
  }

  for (i=0; i<SLOW_CHILDREN; i++ ) {
    pid = fork();
    if (pid==0) {
      child_function(SLOW_SLEEP);
    }
  }
    
  while (children > 0){
    fprintf (stderr, "[pid - %d]", getpid());
    sleep(1);
  }
  return 0;
}
      
