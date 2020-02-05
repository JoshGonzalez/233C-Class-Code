#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[]){
  FILE *fin, *fout;
  int c;
  int blankcount;
  if(argc != 2){
    fprintf(stderr, "Usage: ./entab inputfilename outputfilename\n");
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
    if(c != ' '){ fputc(c, fout);}
    else {
      while((c = fgetc(fin)) != EOF && c != ' '){ ++blankcount;}
      for(int i = 0; i < blankcount; i+=2){
        fputc('\t', fout);
      }
      blankcount = 0;
    }
    c = fgetc(fin);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
