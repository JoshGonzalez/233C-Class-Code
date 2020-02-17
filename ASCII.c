
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BINLEN 8
char* Dec_to_Bin(int dec);
char* Base_to_Bin(int dec, int basenum){
  static char bin[BINLEN];
  size_t i = 0;
  memset(bin, '0', BINLEN);
 while(dec > 0){
   size_t rem = dec % basenum;
   if(rem == 0){bin[i++] = '0';}
   //printf("Remainder is %d\n", bin[i]);
   else{bin[i++] = (rem + '0');}
   dec = dec / basenum;
   //printf("New number is %d\n", dec);
 };

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

for(int i = 128; i >= 0; --i){
 char *str = Base_to_Bin(i, 10);
 //char *bin = Reverse(str);
 fprintf(fout, "%03d ||", i);
 for(int i = sizeof(str) - 1; i >= 0; --i){
 fprintf(fout, "%c", str[i]);
 }
 fprintf(fout, "\n");
}
}
