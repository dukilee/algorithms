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
// MO for [l, r]
struct Query{
  int l, r, p;
  //left, right, position
};
const int BLOCK_SIZE = 317; //sqrt(1e5)

int add(int x); // x is the element from the array
int del(int x); // x is the element from the array 

bool comp(Query a, Query b){
  if(a.l/BLOCK_SIZE != b.l/BLOCK_SIZE)
    return a.l/BLOCK_SIZE < b.l/BLOCK_SIZE;
  return a.r < b.r;
}

/**
* v -> vector where the queries are performed
* q -> queries
*/
void mo(vector<int>& v, vector<Query>& queries, vector<long long>& ans){
  int left, right;
  long long curr;

	for(int i = 0; i<queries.size(); i++){
    queries[i].p = i;
  }

  sort(queries.begin(), queries.end(), comp);

  left = right = queries[0].l;
  curr = add(v[left]); 
  for(auto q : queries){
    while(left<q.l){
      curr += del(v[left]);
      left++;
    }

    while(left>q.l){
      left--;
      curr += add(v[left]);
    }

    while(right<q.r){
      right++;
      curr += add(v[right]);
    }

    while(right>q.r){
      curr += del(v[right]);
      right--;
    }

    ans[q.p] = curr;
  }
}
//FINISH


//Given a vector with n elements and m queries
//For each query there are two numbers l, r
// Answer what is the sum of the elements in the interval [l, r]

int add(int x){
  return x;
}

int del(int x){
  return -x;
}

int main(){
  int n, m;
  cin>>n;
  vector<int> v(n+1);
	for(int i = 0; i<n; i++){
    cin>>v[i+1];
  }

  cin>>m;
  vector<Query> q(m);
	for(int i = 0; i<m; i++){
    cin>>q[i].l>>q[i].r;
  }

  vector<long long> ans(m);
  mo(v, q, ans);

	for(int i = 0; i<m; i++){
    cout<<ans[i]<<endl;
  }
}
