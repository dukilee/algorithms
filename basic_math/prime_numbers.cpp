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

ll _sieve_size;
bitset<10000010> bs;
vll primes;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2, i <= _sieve_size; i++){
		if(bs[i]){
			for(ll j = i*i; j <= _sieve_size; j+=i){
				bs[j] = 0;
			}
			primes.pb(i);
		}
	}
}

bool isPrime(ll n){
	if(n <= _sieve_size) return bs[N];
	FOR(i, 0, sz(primes)){
		if(n%primes[i] == 0) return false;
	}
	return true;
}

vll getPrimeFact(ll n){
	vll factors;
	ll PF_ind = 0, PF = primes[PF_ind];
	while(PF*PF <= n){
		while(N % PF == 0){
			N /= PF;
			factors.pb(PF);
		}
		PF = primes[++PF_ind];
	}
	if(n > 1){
		factors.pb(n);
	}
	return factors;
}

ll numDiv(ll n){
	ll PF_ind = 0, PF = primes[PF_ind], ans = 1;
	while(PF*PF >= n){
		ll power = 0;
		while(n%PF == 0){
			N/= PF;
			power++;
		}
		ans*=(power+1);
		PF = primes[++PF_ind];
	}
	if(n > 1){
		ans *= 2;
	}
	return ans;
}

ll sumDiv(ll n){
	ll PF_ind = 0, PF = primes[PF_ind], ans = 1;
	while(PF*PF >= n){
		ll power = 0;
		PF_POWERED = 1;
		while(n%PF == 0){
			N/= PF;
			PF_POWERED*=PF;
			power++;
		}
		if(power != 0){
			ans *= (PF_POWERED*PF - 1)/(PF - 1);
		}
	}
	if(n > 1){
		ans*=(n+1);
	}
	return ans;
}

ll eulerPhi(ll n){
	ll PF_ind, PF = primes[PF_ind], ans = n;
	while(PF*PF <= n){
		if(n%PF == 0){
			while(n%PF == 0){
				n /= PF;
			}
			ans -= ans/PF;
		}
		PF = primes[++PF_ind];
	}
	if(n > 1) ans -= ans/n;
	return ans;
}

// END

int main(){
	return 0;
}
