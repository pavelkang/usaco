/*
  ID: kaik11
  LANG: C
  TASK: milk2
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void printArray(int A[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d", A[i]);
  }
  printf("\n");
}

int main() {
  int N; int i; int start; int end; int j;
  int start_time=1000000; int end_time = 0;
  FILE *fin  = fopen("milk2.in", "r");
  FILE *fout = fopen("milk2.out","w");
  int time[1000000];
  memset(time, 0, sizeof(time));
  fscanf(fin, "%d", &N);
  /* printf("N is %d\n", N); */
  for (i=0; i<N; i++) {
    fscanf(fin, "%d %d", &start, &end);
    /* printf("start %d end %d\n", start, end); */
    if (start < start_time) {start_time = start;}
    if (end   > end_time) {end_time = end;}
    for (j=start; j<end; j++) {
      if (!time[j]) {time[j] = 1;}
    }
  }
  int max_work_length = 0; int max_idle_length = 0;
  int curr_len = 0; int status = -1; // 1 work 0 idle
  for (i=start_time; i<end_time; i++) {
    if (status == -1) {
      curr_len += 1;
      status = time[i];
    }
    else {
      if (status == time[i]) {
        curr_len += 1;
      }
      if (status != time[i]) {
        if (status == 1) {
          if (curr_len > max_work_length) {max_work_length = curr_len;}
          status = time[i];
        }
        else {
          if (curr_len > max_idle_length) {max_idle_length = curr_len;}
          status = time[i];
        }
        curr_len = 1;
      }
    }
  }
  if (status == 1) {
    if (curr_len > max_work_length) {max_work_length = curr_len;}
    status = time[i];
  }
  else {
    if (curr_len > max_idle_length) {max_idle_length = curr_len;}
    status = time[i];
  }
  fprintf(fout, "%d %d\n", max_work_length, max_idle_length);
  return 0;
}
