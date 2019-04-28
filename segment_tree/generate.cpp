#include <bits/stdc++.h>

using namespace std;

char inp[100];
char out[100];

int rad(int minimo, int maximo){
  double x = 1.0*rand()/RAND_MAX;
  return x*(maximo-minimo) + minimo;
}

void solvre(int n, int q, int operation){
  //operation 0 -> sum 
  //operation 1 -> max
  FILE* input, *output;
  input = fopen(inp, "w");
  output= fopen(out, "w");

  long long v[100100];
  int maxVal = 1000000;
  fprintf(input, "%d %d\n", n, operation);
  for(int i = 0; i<n; i++){
    v[i] = rad(1, maxVal);
    fprintf(input, "%d ", v[i]);
  }
  fprintf(input, "\n%d\n", q);
  for(int i = 0; i<q; i++){
    int x, y, z;
    z = rad(0, 2);
    if(z==0){//query
      x = rad(0, n-1);
      y = rad(0, n-1);
      if(x>y) swap(x, y);
      long long soma = 0;
      for(int j = x; j<=y; j++){
        if(operation == 0) soma += (long long) v[j];
        else soma = max(soma, (long long) v[j]);
      }
      fprintf(output, "%lld\n", soma);
    }else{//update
      x = rad(0, n-1);
      y = rad(-maxVal, maxVal);
      v[x] += y;
    }
    fprintf(input, "%d %d %d\n", z, x, y);
  }

  fclose(input);
  fclose(output);
}

int main(){
  strcpy(inp, "1.in");
  strcpy(out, "1.out");
  solvre(10, 15, 0);

  strcpy(inp, "2.in");
  strcpy(out, "2.out");
  solvre(10, 15, 1);

  strcpy(inp, "3.in");
  strcpy(out, "3.out");
  solvre(100, 500, 0);

  strcpy(inp, "4.in");
  strcpy(out, "4.out");
  solvre(100, 500, 1);

  strcpy(inp, "5.in");
  strcpy(out, "5.out");
  solvre(100000, 1500, 0);
  
  strcpy(inp, "6.in");
  strcpy(out, "6.out");
  solvre(100000, 150000, 1);

  
}
