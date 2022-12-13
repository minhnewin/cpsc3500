// Minh Nguyen
// HW #3 question 5

#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
using namespace std;

float* a;
int allocate = 0;

void* fibseq(void* arg)
{
  int *numptr = (int*)arg;
  if(allocate == 0){
    a = new float [*numptr];
    a[0] = 0;
    a[1] = 1;
    allocate += 1;
  }
  
  for(int i = 0; i < *numptr; i++){
    if(i == 0){
      a[0] = 0;
    }else if(i == 1){
      a[1] = 1;
    }else{
      a[i] = a[i-2] + a[i-1];
    }
  }
  return 0;
}

int main(int argc, char *argv[]){
  int num = atoi(argv[1]);
  if(argc!=2){
    cout<<"Input Error\n";
    return -1;
  }   
  if(argv[1]<=0){
    cout<<"Error, negative number\n";
    return -1;
  }
  pthread_t fd;
  pthread_create(&fd,NULL,fibseq,&num);
  pthread_join(fd,NULL);
  
  for(int i = 0; i < num; i++){
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
