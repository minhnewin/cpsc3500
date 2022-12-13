#include <pthread.h> 
#include <stdio.h>

int value = 10;

void* runner(void* param);

int main(int argc, char* argv[]) {
  int pid;      
  pthread_t tid;
  pid = fork();
  if (!pid) { 
    pthread_create(&tid, NULL, runner, NULL); 
    pthread_join(tid, NULL); 
    printf("CHILD: value= %d\n", value); 
  } else if (pid>0) {
    wait(NULL);
    printf("PARENT: value = %d\n", value); 
  } 
}
void* runner (void* param) {
  value += 50; 
  pthread_exit(0);
}
