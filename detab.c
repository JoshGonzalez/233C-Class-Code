#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAB_INTERVAL 10
int main(int argc, const char * argv[]){
  FILE *fin, *fout;
  int c;
  int tab_interval = argc == 4 ? atoi(argv[3]) : TAB_INTERVAL;
  if (tab_interval > 80) {
    fprintf(stderr, "tabstops must be <= 80 characters\n");
    exit(2);
  }
  if(argc < 3){
    fprintf(stderr, "Usage: ./detab inputfilename outputfilename Tabnum(optional)\n");
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
    if(c != '\t'){ fputc(c, fout);}
    else {
      for(int i = 0; i < tab_interval; ++i){
        fputc(' ', fout);
      }
    }
    c = fgetc(fin);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
