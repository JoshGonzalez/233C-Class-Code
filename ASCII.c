#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* Dec_to_Bin(int dec);

int* Dec_to_Bin(int dec){
  int bin[8];
  int i = 8;
  while(dec > 0){
    bin[i] = dec % 2;
    //printf("%d\n", bin[i]);
    dec = dec / 2;
    //printf("%d\n", dec);
    --i;
  }

  return bin;
}

int main(int argc, const char *argv[]){
//Take in a number
//Then produce a chart of every integer to said number in binary form
//Output it to a file
FILE *fout;

if(argc != 2){
  fprintf(stderr, "Usage: ./Chart fileoutput.txt\n");
  exit(1);
}

fout = fopen(argv[1], "w");

if(fout == NULL){
  fprintf(stderr, "Can not open output file %s\n", argv[1]);
  exit(0);
}

fprintf(fout, "%3s || %8s\n", "Dec", "Bin");

for(int i = 127; i >= 0; --i){
  int *num = Dec_to_Bin(i);
  fprintf(fout, "%03d || ", i);
  for(int i = sizeof(num) - 1; i >= 0; --i){
  fprintf(fout, "%d", *(num + i));
  }
  fprintf(fout, "\n");
}
}
