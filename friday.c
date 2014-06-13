/*
  ID: kaik11
  LANG: C
  TASK: friday
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isLeapYear(int n) {
  if (n%100==0) {return n%400?false:true;}
  else {return n%4?false:true;}
}

void printArray(int A[], int len) {
  int i;
  for (i=0; i<len-1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d", A[len-1]);
}

int main() {
  FILE *fin = fopen("friday.in", "r");
  FILE *fout= fopen("friday.out","w");
  int N;
  int leapYear[12]  = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int normalYear[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int badLuck[7]; // result SAT, SUN ...
  memset(badLuck, 0, sizeof(badLuck)); badLuck[0] = 1; // for the first SAT
  fscanf(fin, "%d", &N);
  int curr_year  = 1900; int target_year = curr_year + N - 1;
  int curr_month = 0; // 0 is JAN
  int curr_date  = 0; // JAN 13, 1900 was a SAT, which is 0
  while ((curr_year != target_year) || (curr_month != 11)) {
    printf("year: %d, month: %d\n", curr_year, curr_month);
    if (isLeapYear(curr_year)) {
      /* do something */
      curr_date = (curr_date + leapYear[curr_month]%7) % 7;
      badLuck[curr_date] += 1;
    }
    else {
      /* do something else */
      curr_date = (curr_date + normalYear[curr_month]%7) % 7;
      badLuck[curr_date] += 1;
    }
    curr_month = (curr_month+1)%12;
    if (curr_month == 0) { curr_year += 1;}
  }
  fprintf(fout, "%d %d %d %d %d %d %d\n", badLuck[0], badLuck[1], badLuck[2],
          badLuck[3], badLuck[4], badLuck[5], badLuck[6]);
  return 0;
}
