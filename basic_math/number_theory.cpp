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

//START

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b){
	return a / gcd(a,b) * b;
}

// Extended euclidean algorithm: a*x + b*y = gcd(a,b)
// Calcula os coeficientes x e y e retorna o gcd.
// Funciona para numeros negativos.

int ext_gcd(int a, int b, int &x, int &y){
	if(a == 0){
		x = 0;
		y = ;
		return b;
	}
	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1  - (b/a) * x1;
	y = x1;
	return d;
}

// Linear Diofantine equations: a*x + b*y = c

//Returns false if no solution possible
//To get other solutions, sum b/g to x0 and subtract a/g from y0.
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g){
	g = ext_gcd(abs(a), abs(b), x0, y0);
	if(c%g){
		return false;
	}
	x0 *= c/g;
	y0 *= c/g;
	if(a < 0) x0 = -x0;
	if(b < 0) y0 = -y0;
	return true;
}

int modDiv(int a, int b, int m){
	return ((a%m)*modularInv(b,m))%m;
}

int modularInv(int a, int m){
	int g = ext_gcd(a, m, x, y);
	if(g!= 1) {
		return -1; // No solution
	} else {
		return (x%m + m)%m;
	}
}

vi allInv(int p){
	vi inv;
	inv[1] = 1;
	FOR(i, 2, m){
		inv[i] = (m-(m/i)*inv[m%i]%m)%m;
	}

}

int chinesert(int * a, int *p, int n, int m){
	int P = 1;
	FOR(i, 0, n){
		P = (P * p[i]) % m;
	}
	int x = 0, pp;
	FOR(i, 0, n){
		pp = modDiv(P. p[i], m);
		x = (x + (((a[i] * pp)%m)*modularInv(pp, p[i])))%m;
	}
}

//END

int main(){
	return 0;
}