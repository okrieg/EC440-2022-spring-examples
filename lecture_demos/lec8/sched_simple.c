#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
jmp_buf env[3];
int x[3] = {0,0,0};

void
schedule()
{
  static int cenv = 0;
  if (cenv == 3) cenv = 0;
  longjmp(env[cenv++], 1);
}

void
a()
{
  if (x[0]==0) {
    if((x[0] = setjmp(env[0])) == 0)
      return;
  }
  printf("a() runs\n");
  sleep(1);
  schedule();
}

void
b()
{
  if (x[1]==0) {
    if( (x[1] = setjmp(env[1])) == 0)
      return;
  }
  printf("b() runs\n");
  sleep(1);
  schedule();
}

void
c()
{
  if (x[2]==0) {
    if( (x[2] = setjmp(env[2])) == 0) 
      return;
  }

  printf("c() runs\n");
  sleep(1);
  schedule();
}

int main()
{
  printf("suspending\n");
  a();
  b();
  c();
  
  printf("running\n");
  schedule();
}
