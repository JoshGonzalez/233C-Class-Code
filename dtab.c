#include <stdio.h>
#include <stdlib.h>
void detab(){
  int c;
  //Read
  //Create a new string
  //Replace all tabs into a certain amount of spaces
  //Profit
  fscanf(fin, "%c", &c)
  while(c != EOF){
    if(c != '\t'){putchar(c);}
  }
  fscanf(fin, "%c", &c)
}
int main(int argc, const char * argv[]){
  if(argc != 3 && argc != 4){
    fprintf(stderr, "Usage: ./tabs input.txt output.txt num\n");
    exit(1);
  }
  FILE * fin = fopen(argv[1], "r");
  if(fin == nullptr || fout == nullptr){
    fprintf(stderr, "File does not exist\n");
    exit(1);
  }
  FILE * fout = fopen(argv[2], "w")
  detab();
  fclose(fin);
  fclose(fout);
  return 0;
}
