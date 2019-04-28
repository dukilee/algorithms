#include <bits/stdc++.h>

using namespace std;

char inp[100];
char out[100];

int rad(int minimo, int maximo){
  return rand()%(maximo-minimo) + minimo;
}

void solvre(int n, int q){
  FILE* input, *output;
  input = fopen(inp, "w");
  output= fopen(out, "w");

  int v[100100];
  fprintf(input, "%d\n", n);
  for(int i = 0; i<n; i++){
    v[i] = rad(1, 100);
    fprintf(input, "%d ", v[i]);
  }
  fprintf(input, "\n%d\n", q);
  for(int i = 0; i<q; i++){
    int x, y;
    x = rad(0, n);
    y = rad(0, n);
    if(x>y) swap(x, y);
    int soma = 0;
    for(int j = x; j<=y; j++){
      soma += v[j];
    }
    fprintf(input, "%d %d\n", x+1, y+1);
    fprintf(output, "%d\n", soma);
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
  solvre(100, 500);

  strcpy(inp, "3.in");
  strcpy(out, "3.out");
  solvre(100000, 100000);

  
}
