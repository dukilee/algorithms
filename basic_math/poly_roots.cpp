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

double logN(double a, double b){
	return log(a)/log(b);
}

vector<double> integratePoly(vector<double> &v){
	vector<double> ans(sz(v)+1, 0);
	FOR(i, 0, sz(v)){
		ans[i] = v[i]/(sz(v)-i);
	}
	return ans;
}
// Poly roots
double evaluateHorner(vector<double> &v, double x){
	double val = 0;
	FOR(i, 0, sz(v)){
		double coef = v[i];
		val*=x;
		val+=coef;
	}
	return val;
}

double ruffiniDivision(vector<double> &px, double r, vector<double> &ans){
	ans.resize(sz(px)-1);
	double curr = 0;
	FOR(i,0, sz(px)-1){
		curr*=r;
		curr+=px[i];
		ans[i]=curr;
	}
	return px.back()+curr*r;
}

double newtonRoot(vector<double> &v, bool &conv, double guess = INT_MAX){
	if(sz(v) == 2){
		conv = true;
		return v.back();
	}
	vector<double> vlinha = derivePoly(v);
	double last = guess-1;
	int i = 200;
	while(abs(guest-last) > EPS && i--){
		last = guess;
		guess = guess - evaluateHorner(v,guess)/evaluateHorner(vlinha, guess);
	}
	conv = (abs(guess-last) <= EPS);
	return guess;
}

vector<double> getAllRoots(vector<double> v){
	vector<double> roots;
	bool conv = true;
	vector<double> nextV;
	double guess = INT_MAX;
	while(sz(v) > 1){
		double root = newtonRoot(v, conv, guess);
		roots.pb(root);
		ruffiniDivision(v, root, nextV);
		swap(v, nextV);
		guess = root;
	}
	return roots;
}

//END

int main(){
	return 0;
}