/*
  ID: kaik11
  LANG: C
  TASK: beads
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 400

void printArray(int A[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d", A[i]);
  }
  printf("\n");
}

size_t getBeads(char neck[], int index, int len, int dir) {
  int j; size_t length = 0;
  if (index==0 && dir==0) {return 1;}
  if (index==len-1 && dir==1) {return 0;}
  if (dir == 0) {
    char c=neck[index];
    /* backwards */
    for (j=index; j>=0; j--) {
      if (c == 'w') {
        length += 1;
        if (neck[j]!='w') {c = neck[j];}
      }
      else {
        if (neck[j]=='w') {length+=1;}
        else {
          if (neck[j]!=c) {return length;}
          else {length += 1;}
        }
      }
    }
    return length;
  }
  else {
    /* forward */
    char c=neck[index+1];
    for (j=index+1; j<len; j++) {
      if (c == 'w') {
        length += 1;
        if (neck[j] != 'w') {c = neck[j];}
      }
      else {
        if (neck[j]=='w') {length+=1;}
        else {
          if (neck[j]!=c) {return length;}
          else {length += 1;}
        }
      }
    }
    return length;
  }
}

int main() {
  int len;char n;
  FILE *fin  = fopen("beads.in", "r");
  FILE *fout = fopen("beads.out","w");
  char necklace[2*MAX];
  char neck[MAX];
  int count[MAX]; memset(count, 0, sizeof(count));
  fscanf(fin, "%d\n", &len);
  fgets(neck, MAX, fin);
  int i;
  for (i=0; i<len; i++) {
    necklace[i] = neck[i];
    necklace[len+i] = neck[i];
  }
  /* necklace is the CONCATENATED necklace */
  size_t max_cut = 0;size_t back; size_t forw;

  for (i=0; i<2*len; i++) {
    back = getBeads(necklace, i, 2*len, 0);
    forw = getBeads(necklace, i, 2*len, 1);
    /* printf("%i back: %zu forw: %zu\n", i, back, forw); */
    if (back + forw > max_cut) {
      /* printf("i: %i\n", i); */
      if (back+forw>len) {
        max_cut = len;
      }
      else {
        max_cut = back + forw;}
    }
  }
  printf("answer is %zu\n", max_cut);
  fprintf(fout, "%zu\n", max_cut);
  return 0;
}
