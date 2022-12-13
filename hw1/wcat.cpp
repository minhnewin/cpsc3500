// Minh Nguyen
// wcat.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int SIZE = 1000;

int main(int argc, char const *argv[]){
  char a[SIZE];
  
  // command-line argument error
  if(argc == 1){
    printf("wcat: file[file ...]\n");
    return 1;
  }

  // read file
  for(int i = 1; i < argc; i++){
    FILE *file = fopen(argv[i], "r");
    // if file cannot be opened
    if(file == NULL) { 
      printf("wcat: File cannot be opened\n");
      return 1;
    }
    // print line
    while(fgets(a,SIZE,file)){
      printf("%s",a);
    }
    printf("\n");
    // close file
    fclose(file);
  }
  return 0;
}
