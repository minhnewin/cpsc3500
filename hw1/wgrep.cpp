// Minh Nguyen
// wgrep.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int SIZE = 1000;

static bool search(const string& word, const string& found)
{
  return string::npos != word.find(found);
}

int main(int argc, char const *argv[]){
  char a[SIZE];

  // command-line arguments error
  if(argc < 2){
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }

  //read file
  for(int i = 2; i < argc; i++){
    FILE *file;
    if(i==2 && argc <= 2){
      file = stdin;
    }else{
      file = fopen(argv[i],"r");
    }

    //wgrep encounters a file that it cannot open
    if (file == NULL){
      printf("wgrep: cannot open file\n");
      return 1;
    }
    //print lines if exist
    while (fgets(a,SIZE,file)){
      if(search(a,argv[1]))
        printf("%s",a);
    }
    //close file
    fclose(file);
  }
  return 0;
}
