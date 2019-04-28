#include<bits/stdc++.h>

using namespace std;

int rad(int lim){
  int x = rand();
  int y = x%(lim-1) + 1;
  assert(y>0);
  assert(y<=lim);
  return y;
}
char inp[11000];
char out[11100];


void solvre(int n, int m){
  FILE* input;
  FILE* output;
  input = fopen(inp, "w");
  output = fopen(out, "w");
  vector<pair<int, int> > vec;
  vector<int> v(n+1);

  fprintf(input, "%d\n", n);
  for(int i = 1; i<=n; i++){
    v[i] = rad(100);
    fprintf(input, "%d ", v[i]);
  }
  fprintf(input, "\n%d\n", m);
  for(int i = 0; i<m; i++){
    
    vec.push_back(make_pair(rad(n), rad(n)));
    if(vec[i].first>vec[i].second)
      swap(vec[i].first, vec[i].second);
    fprintf(input, "%d %d\n", vec[i].first, vec[i].second);

    long long soma = 0;
    for(int j = vec[i].first; j<=vec[i].second; j++){
      soma += v[j];
    }
    //cout<<vec[i].first<<" "<<vec[i].second<<" "<<soma<<endl;
    fprintf(output, "%lld\n", soma);
  }
  fclose(input);
  fclose(output);
}

int main(){
  strcpy(inp, "1.in");
  strcpy(out, "1.out");
  solvre(10, 5);

  strcpy(inp, "2.in");
  strcpy(out, "2.out");
  solvre(100, 10);

  strcpy(inp, "3.in");
  strcpy(out, "3.out");
  solvre(100, 500);

  strcpy(inp, "4.in");
  strcpy(out, "4.out");
  solvre(200, 150);
  
  strcpy(inp, "5.in");
  strcpy(out, "5.out");
  solvre(100000, 100000);
}

