#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("PID = %d\n", getpid());
  char *args[] = {"Hello", "World", NULL};
  execv("./exec2", args);
  printf("Back to exec.c\n");
  return 0;
}