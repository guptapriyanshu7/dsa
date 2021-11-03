#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("We are in exec2.c\n");
  printf("PID of exec2.c = %d\n", getpid());
  return 0;
}