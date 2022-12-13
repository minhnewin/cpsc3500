#include <pthread.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;

int shared_data[10000];
void *fibonacci_thread(void* params);
void parent(int& num);

int main() {
  int num = 0; //user input.
//This will create thread
  pthread_t child;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
//Taking input from user and then start separate thread
  parent(num);
  pthread_create(&child, &attr, fibonacci_thread, (void*) &num);
//starts ( fibonacci thread )
  pthread_join(child, NULL); //waits for thread to end
  //output to command prompt after thread end.
  for(int i = 0; i <= shared_data[i]; i++) {
    printf("%d",shared_data[i]);
  }
  return 0;
}

//Function for fibonacci series
void *fibonacci_thread(void* params) {
  int fib0 = 0, fib1 = 1, next = 0;
  int *pointer;
  pointer = (int*) params;
  int total = *pointer;
  for (int i = 0 ; i < total; i++ ) {
    if ( i <= 1 )
      next = i;
    else {
      next = fib0 + fib1;
      fib0 = fib1;
      fib1 = next;
    }
   next = shared_data[i]; //store to shared_data array
  }
  //pthread_exit(0);
  return NULL;
}

//Input function (from user)
void parent(int& num) {
  cout << "Enter in a number to generate the Fibonacci sequence: ";
  cin >> *num;
  while(isdigit(*num) != true) {
    cout << "Invalid character, please enter in a number: ";
    cin >> *num;
  }
  return;
}
