/*
  ID: kaik11
  LANG: C
  TASK: milk
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

struct Farmer{
  int price;
  int amount;
};

int farmerComp(const void *a, const void *b) {
  return ((struct Farmer *)a)->price - ((struct Farmer *)b)->price;
}

void main() {
  FILE *fin  = fopen("milk.in", "r");
  FILE *fout = fopen("milk.out","w");
  int N, M;
  fscanf(fin, "%d %d", &N, &M); // N: total amount of milk; M: # of farmers
  struct Farmer farmers[M];
  int i;
  for (i=0; i<M; i++) {
    struct Farmer farmer;
    fscanf(fin, "%d %d", &farmer.price, &farmer.amount);
    farmers[i] = farmer;
  }
  // Sort farmers by price
  qsort(&farmers[0], M, sizeof(struct Farmer), &farmerComp);
  int spend = 0;
  for (i=0; i<M; i++) {
    if (N >= farmers[i].amount) {
      N -= farmers[i].amount;
      spend += farmers[i].price*farmers[i].amount;
    } else {
      spend += farmers[i].price * N;
      break;
    }
  }
  printf("spend %d\n", spend);
  fprintf(fout, "%d\n", spend);
  exit (0);
}
