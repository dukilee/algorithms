#include <bits/stdc++.h>

using namespace std;

int main(int n, char** v){
  if(n!=2){
    cout<<"Please specify which is the input file.cpp\n";
    return 1;
  }
  string s;
  ifstream input(v[1]);

  bool start = false;

  while(getline(input, s)){
    if(start && s.find("FINISH") != string::npos) return 0;
    if(start) cout<<s<<endl;
    if(s.find("START") != string::npos) start = true, cout<<endl;
  }

  if(!start){
    cout<<"Did not find the start\n";
  }else{
    cout<<"Did not find the finish\n";
  }
  return 1;
}
