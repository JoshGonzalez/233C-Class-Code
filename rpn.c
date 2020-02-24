//
//  main.c
//  rpn
//
//  Created by William McCarthy on 192//20.
//  Modified by Joshua Gonzalez on 24/2/20
//  Copyright © 2020 William McCarthy. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define MAXOP   100    /* max size of operand/operator */
#define NUMBER '0'     /* signal that a number was found */
#define MAXVAL  100

size_t sp = 0;   // aka unsigned long -- printf using %zu
double val[MAXVAL];   // stack of values

char buf[BUFSIZ];
size_t bufp = 0;
double pop();
void push();
void clear();
void swap();
void duplicate();
double peek();
void peekAll();
void peekAtTopTwo();

int getch_(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch_(int c) {
  if (bufp >= BUFSIZ) { fprintf(stderr, "ungetch: too many characters\n");  return; }
  buf[bufp++] = c;
}
void clear(){
  for(int i = 0; i < MAXVAL; ++i){ val[i] = 0;}
}
void swap(){
  double temp = pop();
  double demp = pop();
  val[sp] = temp;
  val[++sp] = demp;
}
void duplicate(){
  double temp = val[sp];
  double demp = val[sp -1];
  val[++sp] = demp;
  val[++sp] = temp;
}
/*double peek(){
  return val[sp - 1];
}*/
void peekAll(){
  for(int i = 0; i < MAXVAL; ++i){ printf("%.8g ",val[i]);}
  printf("\n");
}
void peekAtTopTwo(){
  if(sp == 0){ fprintf(stderr, "Stack underflow\n");}
  else if(sp == 1){printf("Top of stack is {%.8g}\n", val[sp - 1]);}
  else {printf("Top of stack and below it is {%.8g, %.8g}\n", val[sp - 1], val[sp - 2]);}
}
int getop(char* s) {
  int i, c;
  while ((s[0] = c = getch_()) == ' ' || c == '\t') { }  // skip whitespace
  s[1] = '\0';

  if (!isdigit(c) && c != '.') { return c; }  // if not a digit, return

  i = 0;
  if (isdigit(c)) {  // get digits before '.'
    while (isdigit(s[++i] = c = getch_())) { }
  }
  if (c == '.') {    // get digits after decimal (if any)
    while (isdigit(s[++i] = c = getch_())) { }
  }
  s[i] = '\0';
  if (c != EOF) { ungetch_(c); }
  return NUMBER;      // return type is NUMBER, number stored in s
}
/*bool isNegative(double x){
  if(x > 0){ return true;}
  return false;
}*/
double pop(void) {
  if (sp == 0) { fprintf(stderr, "stack underflow\n");  return 0.0; }
  return val[--sp];
}

void push(double f) {
  if (sp == MAXVAL) { fprintf(stderr, "stack overflow -- can't push %g\n", f);  return; }
  val[sp++] = f;
}
double dmod(double x, double y){
  return x - (int)(x/y) * y;
}
double dpow(double x, double y){
  return pow(y, x);
}

void rpn(void) {
  int type;
  double op2;
  char s[BUFSIZ];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case '\n':    printf("\t%.8g\n", pop());  break;
      case 'p':     peekAtTopTwo();             break;
      case 'a':     peekAll();                  break;
      case 's':     swap();                     break;
      case 'd':     duplicate();                break;
      case 'c':     clear();                    break;
      case '$':     push(sin(pop()));           break;
      case '^':     push(dpow(pop(), pop()));   break;
      case 'e':     push(exp(pop()));           break;
      case NUMBER:  push(atof(s));              break;
      case '+':     push(pop() + pop());        break;
      case '*':     push(pop() * pop());        break;
      case '-':     push(-(pop() - pop()));     break;
      case '/':
        if ((op2 = pop()) == 0.0) { fprintf(stderr, "divide by zero\n");  break; }
        push(pop() / op2);
        break;
      case '%':
        if ((op2 = pop()) == 0.0) { fprintf(stderr, "diveide by zero\n"); break;}
        push(dmod(pop(), op2));
        break;
      default:      fprintf(stderr, "unknown command %s\n", s);  break;
    }
  }
}

int main(int argc, const char * argv[]) {
  rpn();

  return 0;
}
