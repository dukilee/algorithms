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

// START

//indexed from 0
//n is not necessary power of 2

#define NULL_ELEMENT 0
typedef long long T;

class SegTree{
  public:
    int n;
    vector<T> tree;

    T op(T a, T b);

    void build(int node, int a, int b, vector<T>& v){
      if(a>b) return;
      if(a==b){
        tree[node] = v[a];
        return;
      }
      build(2*node, a, (a+b)/2, v);
      build(2*node+1, 1+(a+b)/2, b, v);
      tree[node] = op(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int a, int b, int pos, T value){
      if(a==b){//leaf node
        tree[node] += value;
        return;
      }

      int m = (a+b)/2;
      if(pos<=m){
        update(2*node, a, m, pos, value);
      }else{
        update(2*node+1, m+1, b, pos, value);
      }
      tree[node] = op(tree[2*node], tree[2*node+1]);
    }

    /*Query in range [l, r]*/
    T query(int node, int a, int b, int l, int r){
      if(a>b || a>r || b<l)
        return NULL_ELEMENT;
      if(a>=l && b<=r) return tree[node];
      int m = (a+b)/2;
      T q1 =query(node*2, a, m, l, r);
      T q2 = query(node*2+1, m+1, b, l, r);
      return op(q1, q2);
    }

    void build(vector<T>& v){
      tree.resize(10+4*v.size());
      n = v.size();
      build(1, 0, n-1, v);
    }
    void update(int pos, T value){
      update(1, 0, n-1, pos, value);
    }
    T query(int l, int r){
      return query(1, 0, n-1, l, r);
    }
};

//FINISH

int operation;
T SegTree::op(T a, T b){
  if(operation ==0) return a+b;
  return max(a, b);
}

int main(){
  SegTree st;
  int n;
  cin>>n>>operation;
  vector<ll> v(n);
  rp(i, n){
    cin>>v[i];
  }
  st.build(v);
  int q;
  cin>>q;
  rp(i, q){
    int x, y, z;
    cin>>x>>y>>z;
    if(x==0){
      cout<<st.query(y, z)<<endl;
    }else if(x==1){
      st.update(y, z);
    }
  }
}
