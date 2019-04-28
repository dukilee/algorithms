#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i<b; i++)
#define rp(i, a) for(int i = 0; i<a; i++)
#define REP(i, a, b) for(int i = a; i<=b; i++)
#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

//START
int fen[100100] = {0};

void update(int p, int val, int n){
  for(int i = p; i<=n; i+=i&-i)
    fen[i]+=val;
}

int sum(int p){
  int ans = 0;
  for(int i = p; i; i-=i&-i)
    ans+=fen[i];
  return ans;
}
//FINISH

int main(){
  int n;
  cin>>n;
  rp(i, n){
    int x;
    cin>>x;
    update(i+1, x, n);
  }
  int q;
  cin>>q;
  int x, y;

  rp(i , q){
    cin>>x>>y;
    cout<<sum(y)-sum(x-1)<<endl;
  }
}
