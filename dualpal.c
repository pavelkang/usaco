/*
  ID: kaik11
  LANG: C
  TASK: dualpal
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

bool isPal(int base, int number) {
  char result[30]; int i=0; int j;
  while (number != 0) {
    result[i] = base_digits[number % base];
    number = number / base;
    i += 1;
  }
  for (j=0; j<i; j++) {
    if (result[j] != result[i-j-1]) {
      return false;
    }
  }
  return true;
}

bool isTwoPal(int N) {
  int base; int noOfPal = 0;
  for (base=2; base<=10; base++) {
    if (isPal(base, N)) {
      noOfPal += 1;
      if (noOfPal == 2) return true;
    }
  }
  return false;
}

int main() {
  FILE *fin  = fopen("dualpal.in", "r");
  FILE *fout = fopen("dualpal.out","w");
  int N, S; int found = 0;
  fscanf(fin, "%d %d", &N, &S);
  /* printf("N S: %d %d\n", N, S); */
  S += 1; // greater than S
  while (found < N) {
    /* first N numbers greater than S*/
    if (isTwoPal(S)) {
      fprintf(fout, "%d\n", S);
      printf("%d\n", S);
      found += 1;
    }
    S += 1;
  }
  return 0;
}
