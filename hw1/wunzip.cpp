// Minh Nguyen
// wunzip.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[]){
  char b;
  int c = 0;
  //no files specified
  if(argc == 1){
    printf("wunzip: file1[file2 ...]\n");
    return 1;
  }

  ifstream infile;
  // open file and check
  for (int i = 1; i < argc; i++){
    infile.open(argv[i]);
    if(infile.fail()){
      printf("wunzip: cannot open file\n");
      return 1;
    }
    // read file
    while(!infile.fail()){
      
      infile.read((char*) &c, sizeof(int));
      infile.read((char*) &b, sizeof(char));

      // print contents to screen
      for(int j = 0; j < c && !infile.fail(); j++){
        cout << b;
      }
    }
  }
}
