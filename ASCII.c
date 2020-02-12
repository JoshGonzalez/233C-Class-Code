#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Dec_to_Bin(int dec);
/*char* StrRev(char* s);
void swap(char* a, char* b);
void swap(char* a, char* b){
  char temp = *a;
  *a = *b;
  *b = temp;
}
char* StrRev(char* s){
  char * p = s;
  size_t len = strlen(s);
  char * t = &s[len - 1];
  for(int i = 0; i < len/2; ++i){
    swap(s++, t--);
  }
  return p;
}*/
int[] Dec_to_Bin(int dec){
  int bin[8];
  int i = 7;
  while(dec > 0){
    bin[i] = n % 2;
    dec = dec / 2;
    --i;
  }
  /*char *str ="";
  char buf[1];
  while(num != 0){
    int remainder = num % 2;
    sprintf(buf, "%d", remainder);
    str = str + buf[0]; //Get Remainder
    num = num / 2; //Divide Quotient by 2
  }
  //char* ans = StrRev(str);
  num = atoi(str);*/
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
  int[] str = Dec_to_Bin(i);
  fprintf(fout, "%03d || %8d\n", i, str);
}
}
