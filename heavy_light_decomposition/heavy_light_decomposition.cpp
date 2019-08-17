#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

//START
class HLD{
public:
	vi heavy, parent, depth, head;
	int dfs(vvi& grafo, int v){
		int size = 1;
		int maxSubtree = 0;
		for(auto u : grafo[v]){
			if(u == parent[v]) continue;
			parent[u] = v;
			depth[u] = depth[v]+1;
			int subtree = dfs(grafo, u);
			if(subtree>maxSubtree){
				maxSubtree = subtree;
				heavy[v] = u;
			}
		}
		return size;
	}

	int lca(int x, int y){
		while(head[x]!=head[y]){
			if(depth[head[x]]>depth[head[y]]) swap(x, y);
			y = parent[head[y]];
		}
		if(depth[x]>depth[y]) swap(x, y);
		return x;
	}

	HLD(vvi& grafo, int root){
		heavy.resize(grafo.size(), -1);
		parent.resize(grafo.size());
		depth.resize(grafo.size());
		head.resize(grafo.size());

		parent[root] = root;
		depth[root] = 0;
		head[root] = 0;
		dfs(grafo, root);

		for(int i = 0; i<grafo.size(); i++){
			if(parent[i] != i && heavy[parent[i]]==i) continue;
			for(int x = i; x!=-1; x = heavy[x]){
				head[x] = i;
			}
		}
	}
};

//FINISH

//Problem: Finding lca with hld

int main(){
	vector<vector<int> > grafo;
	int n;
	int m;

	cin>>n;
	m = n-1;
	grafo.resize(n+1);
	for(int i = 0; i<m; i++){
		int x, y;
		cin>>x>>y;
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}

	HLD hld(grafo, 1);

	int q;
	cin>>q;
	for(int i = 0; i<q; i++){
		int x, y;
		cin>>x>>y;
		//cout<<x<<" "<<y<<" ";
		cout<<hld.lca(x, y)<<endl;
	}
}



