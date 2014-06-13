/*
  ID: kaik11
  LANG: C
  TASK: barn1
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
  // Decreasing
  return *(int *)b - *(int *)a;
}

int comp(const void *a, const void *b) {
  // Increasing
  return *(int *)a - *(int *)b;
}

void main() {
  FILE *fin  = fopen("barn1.in", "r");
  FILE *fout = fopen("barn1.out","w");
  int M, S, C; // M is the max # of boards; S the # of stalls; C: # of cows
  fscanf(fin, "%d %d %d", &M, &S, &C);
  if (M >= C) {
    /* If we can choose a lot of boards, just use C of them */
    fprintf(fout, "%d\n", C);
    exit (0);
  }
  int i;
  int indices[C];
  int dif[C-1];
  for (i=0; i<C; i++) {
    fscanf(fin, "%d", &indices[i]);
  }
  qsort(&indices[0], C, sizeof(int), &comp);
  for (i=0; i<C-1; i++) {
    dif[i] = indices[i+1] - indices[i] -1;
  }
  qsort(&dif[0], C-1, sizeof(int), &compare);
  for (i=0; i<C-1; i++) {
    printf("dif %d\n", dif[i]);
  }
  int space_saved = 0; int total_space = indices[C-1] - indices[0] + 1;
  for (i=0; i<M-1; i++) {
    space_saved += dif[i];
  }
  printf("answer is %d\n", total_space - space_saved);
  fprintf(fout, "%d\n", total_space - space_saved);
  exit (0);
}
