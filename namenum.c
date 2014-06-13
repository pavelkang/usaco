/*
  ID: kaik11
  LANG: C
  TASK: namenum
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char D[5000][13];
long long  Dint[5000];

long long char2int(char c, int i, int len) {
  long long num;
  if (c=='A' || c=='B' || c=='C') {num = 2;}
  else if (c=='D' || c=='E' || c=='F') {num = 3;}
  else if (c=='G' || c=='H' || c=='I') {num = 4;}
  else if (c=='J' || c=='K' || c=='L') {num = 5;}
  else if (c=='M' || c=='N' || c=='O') {num = 6;}
  else if (c=='P' || c=='R' || c=='S') {num = 7;}
  else if (c=='T' || c=='U' || c=='V') {num = 8;}
  else if (c=='W' || c=='X' || c=='Y') {num = 9;}
  return num * pow(10, len-i-1);
}

long long str2int(char s[]) {
  long long result = 0;
  int len = strlen(s);
  int i;
  for (i=0; i<len; i++) {
    result += char2int(s[i], i, len); }
  return result;
}


int main() {
  char pad[10][3] = {{0,1,0}, {0,0,0}, {'A', 'B', 'C'},
                    {'D','E','F'}, {'G','H','I'}, {'J','K','L'},
                    {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W','X','Y'}};
  FILE *fin  = fopen("namenum.in", "r");
  FILE *dict = fopen("dict.txt", "r");
  FILE *fout = fopen("namenum.out","w");
  long long N; fscanf(fin,"%lld",  &N);
  printf("N is %lld\n", N);
  /* Get Data */
  int i = 0; char s[12];
  while (fscanf(dict, "%s", D[i]) != EOF) {
    i += 1;
  }
  /* Pre-processing: Translate to int  */
  int j; int numOfWords = 0; int answers[300];
  for (j=0; j<i; j++) {
    Dint[j] = str2int(D[j]);
    if (Dint[j] == N) {
      answers[numOfWords] = j;
      numOfWords += 1;
    }
  }
  char K[] = "KRISTOPHER";
  printf("number is %lld \n", str2int(K));
  if (numOfWords == 0) {fprintf(fout, "NONE\n");printf("NONE\n");}
  else {
    for (j=0; j<numOfWords; j++) {
      printf("%s\n", D[answers[j]]);
      fprintf(fout, "%s\n", D[answers[j]]);
    }
  }
  return 0;
}
