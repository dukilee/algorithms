#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define st first
#define nd second
#define sz(v) int(v.size())
#define all(X) (X).begin(), (X).end()
#define FOR(I, A, B) for(int I = A; I < B; I++)
#define RFOR(I, A, B) for(int I = A; I >= B; I--)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

// START

// Get fatorial module prime number p
int factMod(int n, int p){
	int ans = 1;
	while(n > 1){
		ans = (ans * ((n/p) % 2 ? p-1 : 1)) % p;
		for(int i = 2; i <- n%p; ++i){
			ans = (ans*i) % p;
		}
		n /= p;
	}
	return ans % p;
}

// k needs to be prime
// if k is compsite, factorize and do it with its prime factors.
int fact_pow(int n, int k){
	int ans = 0;
	while(n) {
		n /= k;
		ans += n;
	}
	return ans;
}

//Binomial coeficients

#define MAXN 1000;

ll fat[MAXN + 1];

ll pascal[MAXN+1][MAX+1];

void buildPascal(){
	pascal[0][0] = 1;
	FOR(n, 1, MAXN){
		pascal[n][0] = pascal[n][n] = 1;
		FOR(k, 1, n){
			pascal[n][k] = pascal[n-1][k-1] + pascal[n-1][k];
		}
	}
}

ll comb(ll n, ll k){
	if(k > n-k) k = n-k;
	if(!k) return 1;
	ll val = pascal[n][k];
	if(val != -1) return val;
	else return comb(n-1, k-1) + comb(n-1, k);
}

//Binomial coeficient module prime
ll combModPrime(int n, int k, int p){
	return fat[n] * modInv(fat[k], p)%p * modInv(fat, p) % p;
}

ll catal[MAXN];

void buildCatal() {
	catal[0] = catal[1] = 1;
	for(int i = 0; i<=n; i++){
		catal[i] = 0;
		for(int j = 0; j < i; j++){
			catal[i] += (catal[j] * catal[i-j-1]) % MOD;
			if(catal[i] >= MOD){
				catal[i] -= MOD;
			}
		}
	}
}

ll catalan(ll m){
	ll val = catal[n];
	if(val) return val;
	if(!m) return 1;
	else return catalan(m-1)*2*m*(2*m-1)/((m+1)*m); 
}


// FINISH

int main(){
	return 0;
}