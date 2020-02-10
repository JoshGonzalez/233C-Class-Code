#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int StrBin_to_Dec(const char *str);
/*int Char_to_Bin(char c);
int Dec_to_Bin(int dec);
"0101" = 5
int Char_to_Bin(char c){
  //Get the Char_to_Bin
  //Automatically convert to dec
  //Convert to Bin
  //Profit
  int dec = c;
  int ans = Dec_to_Bin(dec);
  return ans;
}
int Dec_to_Bin(int dec){
  int num = dec;
  int ans;
  char *str ="";
  while(num != 0){
    str += num % 2;
    num /= 2;
  }
  ans = atoi(str);
  return ans;
}*/
//Simplify the string to a string with less zeros or skip
//Start from the back of the string and starting at zero then multiply it by the power
//If it's a once
int StrBin_to_Dec(const char *str){
  int len = sizeof(str) - 1;
  int ans = 0;
  while(len >= 0){
    if(str[len] == '1'){
      ans += pow(2, sizeof(str) - len);
    }
    --len;
  }
  return ans;
};
int main (){
  int bin = StrBin_to_Dec("0101");
  printf("0101 in Decimal is %d\n", bin);
  return 0;
}
