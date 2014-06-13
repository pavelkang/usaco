/*
  ID: kaik11
  LANG: C
  TASK: transform
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

void printArray(int A[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d", A[i]);
  }
  printf("\n");
}

int rc2index(int row, int col, int N) {
  /* Translates from row/col representation to index */
  return row*N + col;
}

int index2r(int index, int N) {
  return index / N;
}

int index2c(int index, int N) {
  return index % N;
}

int rot90(int index, int N) {
  return rc2index(index2c(index, N),
                  N-index2r(index, N)-1, N);
}

int rot180(int index, int N) {
  return rot90(rot90(index, N), N);
}

int rot270(int index, int N) {
  return rot90(rot180(index, N), N);
}

int reflect(int index, int N) {
  /* row -> row */
  /* col -> N-1-col */
  int row = index2r(index, N);
  int col = N - 1 - index2c(index, N);
  return rc2index(row, col, N);
}

bool isSame(int *A, int *B, int N) {
  int i = 0;
  for (i=0; i<N*N; i++) {
    if (A[i] != B[i]) {
      return false;}
  }
  return true;
}

bool isTransform(int (*f)(int index, int N), int *A, int *B, int N) {
  int i = 0;
  for (i=0; i<N*N; i++) {
    if (A[i] != B[f(i,N)]) {
      /* printf("i: %d f(i):%d, %d - %d\n", i, f(i,N), A[i], B[f(i,N)]); */
      return false;}
  }
  return true;
}

bool isComb(int (*g) (int index, int N),
            int (*f)(int index, int N), int *A, int *B, int N) {
  int i = 0;
  for (i=0; i<N*N; i++) {
    if (A[i] != B[g(f(i,N),N)]) {
      return false;}
  }
  return true;
}

int main() {
  FILE *fin  = fopen("transform.in", "r");
  FILE *fout = fopen("transform.out","w");
  int N; char c; int i=0;
  fscanf(fin, "%d", &N);
  int *A = calloc(N*N, sizeof(int));
  int *B = calloc(N*N, sizeof(int));
  while (1 == fscanf(fin, "%c", &c)) {
    if (c == '\n') {
      continue;
    }
    else {
      if (c == '@') {
        if (i>=N*N) {B[i-N*N]=1;} else {A[i]=1;}
        i+=1;
      }
      else {
        i+=1;
      }
    }
  }
  if (isTransform(rot90, A, B, N)) {fprintf(fout, "1\n");}
  else if (isTransform(rot180, A, B, N)) {fprintf(fout, "2\n");}
  else if (isTransform(rot270, A, B, N)) {fprintf(fout, "3\n");}
  else if (isTransform(reflect, A, B, N)) {fprintf(fout, "4\n");}
  else if (isComb(rot90, reflect, A, B, N)  ||
      isComb(rot180, reflect, A, B, N) ||
      isComb(rot270, reflect, A, B, N)) {fprintf(fout, "5\n");}
  else if (isSame(A, B, N)) {fprintf(fout, "6\n");}
  else {fprintf(fout, "7\n");}
  return 0;
}
