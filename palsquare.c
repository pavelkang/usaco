/*
  ID: kaik11
  LANG: C
  TASK: palsquare
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

char base_digits[19] =
  {'0', '1', '2', '3', '4', '5', '6', '7',
   '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

void printIntArray(int A[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d", A[i]);
  }
  printf("\n");
}

void printCharArray(char A[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%c", A[i]);
  }
  printf("\n");
}

bool isPal(int number, int base, FILE *fout) {
  char result[30]; int i=0; int j; bool is = true;
  int n = number; number *= number;
  while (number != 0) {
    result[i] = base_digits[number % base];
    number = number / base;
    i += 1;
  }
  for (j=0; j<i; j++) {
    if (result[j] != result[i-j-1]) {
      is = false;
    }
  }
  if (is) {
    char N[30]; int ori_n = n; int k=0;
    while (n != 0) {
      N[k] = base_digits[n % base];
      n = n/base;
      k += 1;
    }
    for (j=0; j<k; j++) {
      fprintf(fout, "%c", N[k-j-1]);
      printf("%c", N[k-j-1]);
    }
    fprintf(fout, " ");
    printf(" ");
    for (j=0; j<i; j++) {
      fprintf(fout, "%c", result[i-j-1]);
      printf("%c", result[i-j-1]);
    }
    fprintf(fout, "\n");
    printf("\n");
  }
}

int main() {
  FILE *fin  = fopen("palsquare.in", "r");
  FILE *fout = fopen("palsquare.out","w");
  int B; int i;
  fscanf(fin, "%d", &B);
  for (i=1; i<301; i++) {
    isPal(i, B, fout);
  }
  return 0;
}
