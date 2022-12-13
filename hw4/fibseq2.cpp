#include<bits/stdc++.h>
using namespace std;

vector<int>;

int i;
void *runn(void *arg)
{
  if(i==0){
    fib[i]=0;
    pthread_exit(0);
  }
  else if(i==1){
    fib[i]=1;
    pthread_exit(0);
  }
  else{
    fib[i] = fib[i-1]+fib[i-2];
    pthread_exit(0);
  }
}

int main(int argc, char *argv[])
{
  if(argc!=2){
    cout<<"Input format is : ./filename <integer value>\n";
    return -1;
  }
  
  int n = atoi(argv[1]);
  
  if(n<=0){
    cout<<"Input number should be > 0\n";
    return -1;
  }
  fib.resize(n);
  pthread_t *threads = (pthread_t *) malloc(n * sizeof(pthread_t));
  
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  
  for(i=0; i<n ;i++){
      pthread_create(&threads[i], &attr, runn, NULL);
      pthread_join(threads[i], NULL);
  }
  
  printf("The Fibonacci sequence.:");
  for(int j=0; j<n; j++){
    cout<<fib[j]<<' ';
  }
  cout<<endl;
  return 0;
}
