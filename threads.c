#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile long int a = 0;
pthread_mutex_t aLock;

void threadFunc(void* arg) {
  int i;
  long int localA = 0;
  for (i = 1; i < 5000000; i++) {
    localA = localA + i;
  }
  pthread_mutex_lock(&aLock);
  a = a + localA;
  pthread_mutex_unlock(&aLock);
}

void threadFunc2(void* arg) {
  int i;
  long int localA = 0;
  for (i = 5000000; i <= 10000000; i++) {
    localA = localA + i;
  }
  pthread_mutex_lock(&aLock);
  a = a + localA;
  pthread_mutex_unlock(&aLock);
}

int main(int argc, char** argv) {
  pthread_t one, two;
  int i;
  a = 0;

  pthread_mutex_init(&aLock, NULL);
  pthread_create(&one, NULL, (void*)&threadFunc, NULL);
  pthread_create(&two, NULL, (void*)&threadFunc2, NULL);

  pthread_join(one, NULL);
  pthread_join(two, NULL);

  // for (i = 1; i <= 10000000; i++) {
  //   a = a + i;
  // }

  printf("%ld\n", a);
}