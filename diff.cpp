#include <bits/stdc++.h>

using namespace std;

int main(int n, char** v){
  if(n!=3){
    cout<<"WRONG PARAMETERS"<<endl;
    cout<<"PLEASE INFORM THE NAME OF TWO FILES TO COMPARE"<<endl;
    return 2;
  }
  FILE* a = fopen(v[1], "r");
  FILE* b = fopen(v[2], "r");
  char x, y;
  bool read1 = true, read2;
  while(read1){
    read1 = fscanf(a, "%c", &x)!=EOF;
    read2 = fscanf(b, "%c", &y)!=EOF;
    if(read1!=read2 || x!=y) return 1;
  }
  return 0;
}
