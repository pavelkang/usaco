/*
  ID: kaik11
  LANG: C++
  TASK: milk
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
  ifstream fin("milk.in");
  ofstream fout("milk.out");
  int N, M;
  fin >> N >> M;
  cout << "N is " << N << ", M is "<< M << endl;
  map<int, int> farmers; int price; int amount;
  for (int i=0; i<M; i++) {
    fin >> price;
    fin >> amount;
    farmers[price] = amount;
  }

  return 0;
}
