/*
  ID: kaik11
  LANG: C++
  TASK: calfflac
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
  ifstream fin("calfflac.in");
  ofstream fout("calfflac.out");
  string in;
  getline(fin, in， EOF);
  cout << "This is the input: " << in << endl;
  return 0;
}
