#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i<b; i++)
#define rp(i, a) for(int i = 0; i<(int) a; i++)
#define REP(i, a, b) for(int i = a; i<=b; i++)
#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

// START
// GRAFO DE 1 a n;

int father[100100][20];
vi grafo[100100];
int logn;
int dept[100100];

void DFS(int x, int p){
  for(int i = 1 ; i<=logn; i++){
    father[x][i] = father[father[x][i-1]][i-1];
  }

  for(vi::iterator it = grafo[x].begin(); it!=grafo[x].end(); it++){
     if(*it == p) continue;
     father[*it][0] = x;
     dept[*it] = dept[x] + 1;
     DFS(*it, x);
  }
}

int goup(int a, int dist){
  for(int i = 0; dist; i++){
    if(dist & (1<<i)){
      a = father[a][i];
      dist -= 1<<i;
    }
  }
  return a;
}

int LCA(int a, int b){
  if(dept[a]<dept[b]) swap(a, b);
  a = goup(a, dept[a] - dept[b]);
  if(a==b) return a;
  for(int i = logn; i>=0; i--){
    if(father[a][i] != father[b][i]){
      a = father[a][i];
      b = father[b][i];
    }
  }
  return father[a][0];
}

void preLCA(int n /*quant vertex*/){
  logn = 0; 
  while((1<<(logn+1))<=n) logn++;
  dept[1] = 0;
  for(int i = 0; i<=logn; i++){
    father[0][i] = father[1][i] = 1;
  }
  DFS(1, 0);
}

//FINISH

int main(){
  int n, q;
  int x, y;
  cin>>n;
	for(int i = 0; i<n-1; i++){
    scanf("%d %d", &x, &y);
    grafo[x].pb(y);
    grafo[y].pb(x);
  }
  preLCA(n);
  cin>>q;
	for(int i = 0; i<q; i++){
    scanf("%d %d", &x, &y);
    cout<<LCA(x, y)<<endl;
  }
}
