#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 10
int main(int argc, const char * argv[]){
  FILE *fin, *fout;
  int c;
  int iterator = 0;
  int line_length = argc == 4 ? atoi(argv[3]) : LINE_LENGTH;
  if(argc < 3){
    fprintf(stderr, "Usage: ./fold inputfilename outputfilename linelength(optional)\n");
    exit(1);
  }
  fin = fopen(argv[1], "r");
  fout = fopen(argv[2], "w");
  if(fin == NULL){
    fprintf(stderr, "Can not open input file %s\n", argv[1]);
    exit(0);
  }
  if(fout == NULL){
    fprintf(stderr, "Can not open output file %s\n", argv[2]);
    exit(0);
  }
  c = fgetc(fin);
  while(c != EOF){
    if(iterator < line_length - 1){
      fputc(c, fout);
      ++iterator;
    }
    else {
      fputc(c, fout);
      fputc('-', fout);
      fputc('\n', fout);
      iterator = 0;
      }
    c = fgetc(fin);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
