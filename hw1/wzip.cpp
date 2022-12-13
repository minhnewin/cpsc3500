// Minh Nguyen
// wzip.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int SIZE = 1000;

int main(int argc, char const *argv[]){
  char a[SIZE];

  // no files are specified
  if(argc == 1){
    printf("wzip: file1[file2 ...]\n");
    return 1;
  }

  // open file and check
  for (int i = 1; i < argc; i++){
    FILE *file = fopen(argv[i],"r");
    if(file == NULL) { 
      printf("wzip: cannot open file\n");
      return 1;
    }

    char b;
    int c = -1;
    // zip file
    while(fgets(a,SIZE,file)){
      for(unsigned int i = 0; i < strlen(a); i++){
        if(c < 0){
          b = a[i];
          c = 0;
        }else if (b != a[i]){
          cout.write((char*) &c, sizeof(int));
          cout.write((char*) &b, sizeof(char));
          b = a[i];
          c = 0;
        }
        c++;
      }
      if(c > 0) {
        cout.write((char*) &c, sizeof(int));
        cout.write((char*) &b, sizeof(char));
      }
    }
    // close file
    fclose(file);
  }
}
