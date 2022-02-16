#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
jmp_buf env[3];
int x[3];

void
a(int i)
{
  if (i==1) {
    x[0] = setjmp(env[0]);
  } else {
    longjmp(env[0], 1);
  }
  if (x[0]) {
    printf("a() runs\n");
    sleep(1);
  }
}

void
b(int i)
{
  if (i==1) {
    x[1] = setjmp(env[1]);
  } else {
    longjmp(env[1], 1);
  }
  if (x[1]) {
    printf("b() runs\n");
    sleep(1);
  }
}

void
c(int i)
{
  if (i==1) 
    x[2] = setjmp(env[2]);
  else
    longjmp(env[2], 1);
  if (x[2]) {
    printf("c() runs\n");
    sleep(1);
  }
}

int main()
{
  do {
    printf("suspending\n");
    a(1);
    b(1);
    c(1);
    
    printf("running\n");
    a(0);
    b(0);
    c(0);
  } while(1);
}
